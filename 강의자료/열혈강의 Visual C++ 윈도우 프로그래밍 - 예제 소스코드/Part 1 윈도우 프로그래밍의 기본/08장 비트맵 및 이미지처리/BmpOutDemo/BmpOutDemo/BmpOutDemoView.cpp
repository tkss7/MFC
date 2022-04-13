
// BmpOutDemoView.cpp : CBmpOutDemoView 클래스의 구현
//

#include "stdafx.h"
#include "BmpOutDemo.h"

#include "BmpOutDemoDoc.h"
#include "BmpOutDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBmpOutDemoView

IMPLEMENT_DYNCREATE(CBmpOutDemoView, CView)

BEGIN_MESSAGE_MAP(CBmpOutDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CBmpOutDemoView 생성/소멸

CBmpOutDemoView::CBmpOutDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBmpOutDemoView::~CBmpOutDemoView()
{
}

BOOL CBmpOutDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBmpOutDemoView 그리기

void CBmpOutDemoView::OnDraw(CDC* /*pDC*/)
{
	CBmpOutDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CBmpOutDemoView 인쇄

BOOL CBmpOutDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBmpOutDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBmpOutDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBmpOutDemoView 진단

#ifdef _DEBUG
void CBmpOutDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CBmpOutDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBmpOutDemoDoc* CBmpOutDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBmpOutDemoDoc)));
	return (CBmpOutDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CBmpOutDemoView 메시지 처리기

void CBmpOutDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CDC MemDC;
	BITMAP bmpInfo;
	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmap(IDB_Test_Image);

	bmp.GetBitmap(&bmpInfo);
	pOldBmp = MemDC.SelectObject(&bmp);

	dc.StretchBlt(20, 20,
				bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2,
				&MemDC,
				0, 0,
				bmpInfo.bmWidth, bmpInfo.bmHeight,
				SRCCOPY);			//래스터 연산 값.

	//※ 마지막 인자를 제외하면 StretchBlt() 함수와 거의 동일. 
	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = 50;	//0: 투명 255: 불투명
	bf.AlphaFormat = 0;
	//반투명 이미지를 출력한다.
	dc.AlphaBlend(20, 100,
				bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2,
				&MemDC,
				0, 0,
				bmpInfo.bmWidth, bmpInfo.bmHeight,
				bf);				//BLENDFUNCTION 구조체

	MemDC.SelectObject(pOldBmp);
}


/*	dc.TransparentBlt(20, 100,
				bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2,
				&MemDC,
				0, 0,
				bmpInfo.bmWidth, bmpInfo.bmHeight,
				RGB(0, 0, 0));		//투명처리될 색상의 RGB값.
*/