
// ImageRgnView.cpp : CImageRgnView 클래스의 구현
//

#include "stdafx.h"
#include "ImageRgn.h"

#include "ImageRgnDoc.h"
#include "ImageRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageRgnView

IMPLEMENT_DYNCREATE(CImageRgnView, CView)

BEGIN_MESSAGE_MAP(CImageRgnView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CImageRgnView 생성/소멸

CImageRgnView::CImageRgnView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageRgnView::~CImageRgnView()
{
}

BOOL CImageRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageRgnView 그리기

void CImageRgnView::OnDraw(CDC* /*pDC*/)
{
	CImageRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CImageRgnView 인쇄

BOOL CImageRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageRgnView 진단

#ifdef _DEBUG
void CImageRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CImageRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageRgnDoc* CImageRgnView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageRgnDoc)));
	return (CImageRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageRgnView 메시지 처리기

int CImageRgnView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_rectVisible = CRect(0, 0, 0, 0);
	//배경으로 사용할 이미지 리소스 로드.
	m_ImgSample.LoadFromResource(AfxGetInstanceHandle(), IDB_Sample);

	return 0;
}

void CImageRgnView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//반투명하게 배경 이미지를 출력.
	m_ImgSample.AlphaBlend(dc.m_hDC, 0, 0, 50);
	//원으로된 윈도우 영역을 선택.
	CRgn Rgn;
	Rgn.CreateEllipticRgn(m_rectVisible.left,
					m_rectVisible.top,
					m_rectVisible.right,
					m_rectVisible.bottom);
	dc.SelectClipRgn(&Rgn);
	//투명하지 않은 이미지를 다시 한번 출력.
	m_ImgSample.BitBlt(dc.m_hDC, 0, 0);
}

void CImageRgnView::OnMouseMove(UINT nFlags, CPoint point)
{
	//마우스 왼쪽 버튼이 눌린 상태이면 윈도우를 다시 그린다.
	if(nFlags & MK_LBUTTON)
	{
		//원이 생성될 사각형의 좌표는 마우스를 기준으로
		//지름이 200픽셀 정도가 되도록 한다.
		m_rectVisible = CRect(	point.x - 100, point.y - 100,
								point.x + 100, point.y + 100);
		RedrawWindow();
	}

	CView::OnMouseMove(nFlags, point);
}

void CImageRgnView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//눈에 보이는 영역을 없에고 윈도우를 다시 그린다.
	m_rectVisible = CRect(0, 0, 0, 0);
	RedrawWindow();

	CView::OnLButtonUp(nFlags, point);
}
