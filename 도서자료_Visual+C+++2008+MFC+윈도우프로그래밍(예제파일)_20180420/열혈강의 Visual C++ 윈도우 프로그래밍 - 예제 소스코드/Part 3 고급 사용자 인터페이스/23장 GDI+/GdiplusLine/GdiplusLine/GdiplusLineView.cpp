
// GdiplusLineView.cpp : CGdiplusLineView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusLine.h"

#include "GdiplusLineDoc.h"
#include "GdiplusLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusLineView

IMPLEMENT_DYNCREATE(CGdiplusLineView, CView)

BEGIN_MESSAGE_MAP(CGdiplusLineView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusLineView 생성/소멸

CGdiplusLineView::CGdiplusLineView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusLineView::~CGdiplusLineView()
{
}

BOOL CGdiplusLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusLineView 그리기

void CGdiplusLineView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusLineView 인쇄

BOOL CGdiplusLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusLineView 진단

#ifdef _DEBUG
void CGdiplusLineView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusLineDoc* CGdiplusLineView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusLineDoc)));
	return (CGdiplusLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusLineView 메시지 처리기

void CGdiplusLineView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen RedPen(Color(255, 255, 0, 0), 2.0f);
	Pen GreenPen(Color(255, 0, 255, 0), 2.0f);
	Pen BluePen(Color(255, 0, 0, 255), 2.0f);

	Point points[6] = {Point(10, 150), Point(110, 10), Point(170, 250),
						Point(220, 120), Point(270, 150), Point(350, 150)};
	graphics.DrawCurve(&RedPen, points, 6, 0.0f);
	graphics.DrawCurve(&GreenPen, points, 6, 0.5f);
	graphics.DrawCurve(&BluePen, points, 6, 1.0f);
}

/*
	Graphics graphics(dc);

	Pen BluePen(Color(255, 0, 0, 255), 20.0f);
	Pen BlackPen(Color(128, 0, 0, 0), 20.0f);

	graphics.DrawLine(&BluePen, Point(10,  50), Point(210, 50));
	graphics.DrawLine(&BlackPen, Point(20,  60), Point(220, 60));
*/

/*
	Graphics graphics(dc);

	Pen BluePen(Color(255, 0, 0, 255), 10.0f);

	Point point1(30, 10);
	Point point2(30, 110);
	Point point3(230, 20);
	Point point4(230, 120);
	Point points[4] = {point1, point2, point3, point4};

	BluePen.SetLineJoin(LineJoinRound);
//	BluePen.SetDashStyle(DashStyleDot);
	BluePen.SetStartCap(LineCapRoundAnchor);
	BluePen.SetEndCap(LineCapArrowAnchor);
	graphics.DrawLines(&BluePen, points, 4);
*/

