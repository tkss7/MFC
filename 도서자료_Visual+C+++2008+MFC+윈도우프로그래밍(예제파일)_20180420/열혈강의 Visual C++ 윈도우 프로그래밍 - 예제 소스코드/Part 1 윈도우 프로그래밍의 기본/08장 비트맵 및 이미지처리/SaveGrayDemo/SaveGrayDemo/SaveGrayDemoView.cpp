
// SaveGrayDemoView.cpp : CSaveGrayDemoView 클래스의 구현
//

#include "stdafx.h"
#include "SaveGrayDemo.h"

#include "SaveGrayDemoDoc.h"
#include "SaveGrayDemoView.h"

#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSaveGrayDemoView

IMPLEMENT_DYNCREATE(CSaveGrayDemoView, CView)

BEGIN_MESSAGE_MAP(CSaveGrayDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSaveGrayDemoView 생성/소멸

CSaveGrayDemoView::CSaveGrayDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSaveGrayDemoView::~CSaveGrayDemoView()
{
}

BOOL CSaveGrayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSaveGrayDemoView 그리기

void CSaveGrayDemoView::OnDraw(CDC* /*pDC*/)
{
	CSaveGrayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSaveGrayDemoView 인쇄

BOOL CSaveGrayDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSaveGrayDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSaveGrayDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSaveGrayDemoView 진단

#ifdef _DEBUG
void CSaveGrayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSaveGrayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSaveGrayDemoDoc* CSaveGrayDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSaveGrayDemoDoc)));
	return (CSaveGrayDemoDoc*)m_pDocument;
}
#endif //_DEBUG

inline void RGBtoGray(COLORREF& rgb)
{
	BYTE byGray = (GetRValue(rgb)	* 30
				+ GetGValue(rgb)	* 59
				+ GetBValue(rgb)	* 11) / 100;

	rgb = RGB(byGray, byGray, byGray);
}

// CSaveGrayDemoView 메시지 처리기

void CSaveGrayDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//바탕화면 윈도우 객체에 대한 포인터를 얻음.
	CWnd* pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);		//바탕화면 윈도우DC
	CClientDC dc(this);					//뷰 윈도우DC

	//바탕화면 크기 및 색상수와 동일한 비트맵 이미지를 만든다.
	CImage Image;
	Image.Create(300, 300, ScrDC.GetDeviceCaps(BITSPIXEL));

	//이미지DC와 화면DC에 바탕화면 윈도우DC를 출력한다.
	CDC* pDC = CDC::FromHandle(Image.GetDC());
	pDC->BitBlt(0, 0, 300, 300, &ScrDC, 0, 0, SRCCOPY);
	Image.ReleaseDC();

	//일부(200 * 200)를 Gray 이미지로 변환.
	COLORREF rgb;
	for(int x = 0; x < 200; x++)		//폭
	{
		for(int y = 0; y < 200; ++y)	//높이
		{
			rgb = Image.GetPixel(x, y);
			//Gray RGB 값으로 변환.
			RGBtoGray(rgb);
			Image.SetPixel(x, y, rgb);
		}
	}

	//흑백으로 변환된 이미지를 화면DC에 출력.
	Image.BitBlt(dc.m_hDC, 0, 0);

	CView::OnLButtonDown(nFlags, point);
}

void CSaveGrayDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	//바탕화면 윈도우 객체에 대한 포인터를 얻음.
	CWnd* pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);		//바탕화면 윈도우DC
	CClientDC dc(this);					//뷰 윈도우DC

	//바탕화면 윈도우의 크기를 알아낸다.
	CRect Rect;
	pWndDesktop->GetWindowRect(&Rect);

	//바탕화면 크기 및 색상수와 동일한 비트맵 이미지를 만든다.
	CImage Image;
	int cx = Rect.Width();		//바탕화면 폭
	int cy = Rect.Height();		//바탕화면 높이
	Image.Create(cx, cy, ScrDC.GetDeviceCaps(BITSPIXEL));

	//이미지DC와 화면DC에 바탕화면 윈도우 화면을 출력한다.
	CDC* pDC = CDC::FromHandle(Image.GetDC());
	pDC->BitBlt(0, 0, cx, cy, &ScrDC, 0, 0, SRCCOPY);
	dc.BitBlt(0, 0, cx, cy, pDC, 0, 0, SRCCOPY);
	Image.ReleaseDC();

	//JPEG 형식으로 바탕화면 이미지를 저장한다.
	Image.Save(TEXT("Desktop.jpg"), Gdiplus::ImageFormatJPEG);
	//저장된 이미지를 뷰어를 실행하여 보여준다.
	::ShellExecute(	NULL,
					TEXT("open"), TEXT("Desktop.jpg"),
					NULL, NULL, SW_SHOW);

	::ShellExecute(	NULL,
		TEXT("open"), TEXT("http://www.freelec.co.kr"),
					NULL, NULL, SW_SHOW);

	CView::OnRButtonDown(nFlags, point);
}
