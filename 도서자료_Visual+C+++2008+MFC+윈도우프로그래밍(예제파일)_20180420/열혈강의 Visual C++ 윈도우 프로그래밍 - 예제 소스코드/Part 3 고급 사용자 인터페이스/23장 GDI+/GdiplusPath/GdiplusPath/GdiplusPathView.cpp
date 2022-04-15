
// GdiplusPathView.cpp : CGdiplusPathView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusPath.h"

#include "GdiplusPathDoc.h"
#include "GdiplusPathView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusPathView

IMPLEMENT_DYNCREATE(CGdiplusPathView, CView)

BEGIN_MESSAGE_MAP(CGdiplusPathView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusPathView 생성/소멸

CGdiplusPathView::CGdiplusPathView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusPathView::~CGdiplusPathView()
{
}

BOOL CGdiplusPathView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusPathView 그리기

void CGdiplusPathView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusPathDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusPathView 인쇄

BOOL CGdiplusPathView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusPathView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusPathView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusPathView 진단

#ifdef _DEBUG
void CGdiplusPathView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusPathView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusPathDoc* CGdiplusPathView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusPathDoc)));
	return (CGdiplusPathDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusPathView 메시지 처리기

void CGdiplusPathView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen pen(Color(255, 0, 0, 0), 1);
	SolidBrush sbrush(Color(255, 192, 192, 192));

	Region Rgn1(Rect(10, 10, 140, 140));
	Region Rgn2(Rect(80, 50, 140, 140));

	Rgn2.Exclude(&Rgn1);
	graphics.FillRegion(&sbrush, &Rgn2);
}

/*
	path.SetFillMode(FillModeWinding);
	graphics.DrawPath(&pen, &path);
	graphics.FillPath(&sbrush, &path);
*/

/*
	Pen pen(Color(255, 0, 0, 0), 1);
	SolidBrush sbrush(Color(255, 192, 192, 192));
	GraphicsPath path;

	path.AddRectangle(Rect(10, 10, 100, 100));
	path.AddEllipse(Rect(70, 70, 120, 120));
	FontFamily fontFamily(_T("Arial"));
	path.AddString(_T("Test String"), -1,
					&fontFamily,
					FontStyleBold,
					48,
					Point(20, 20),
					NULL);

	graphics.DrawPath(&pen, &path);

	Region Rgn(&path);
	graphics.SetClip(&Rgn);

	Font font(_T("Arial"), 100, FontStyleBold, UnitPixel);
	HatchBrush htbrush(HatchStyleDiagonalBrick,
		Color::Black, Color::Chocolate);
	graphics.DrawString(_T("Test String"), -1, &font,
						PointF(10, 10),
						&htbrush);
*/
