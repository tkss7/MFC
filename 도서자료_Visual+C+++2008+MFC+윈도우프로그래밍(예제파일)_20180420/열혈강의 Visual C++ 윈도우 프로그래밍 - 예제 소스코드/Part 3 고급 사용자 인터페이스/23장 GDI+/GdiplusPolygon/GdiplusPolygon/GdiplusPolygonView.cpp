
// GdiplusPolygonView.cpp : CGdiplusPolygonView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusPolygon.h"

#include "GdiplusPolygonDoc.h"
#include "GdiplusPolygonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusPolygonView

IMPLEMENT_DYNCREATE(CGdiplusPolygonView, CView)

BEGIN_MESSAGE_MAP(CGdiplusPolygonView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusPolygonView 생성/소멸

CGdiplusPolygonView::CGdiplusPolygonView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusPolygonView::~CGdiplusPolygonView()
{
}

BOOL CGdiplusPolygonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusPolygonView 그리기

void CGdiplusPolygonView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusPolygonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusPolygonView 인쇄

BOOL CGdiplusPolygonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusPolygonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusPolygonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusPolygonView 진단

#ifdef _DEBUG
void CGdiplusPolygonView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusPolygonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusPolygonDoc* CGdiplusPolygonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusPolygonDoc)));
	return (CGdiplusPolygonDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusPolygonView 메시지 처리기

void CGdiplusPolygonView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen RedPen(Color(255, 192, 0, 0), 2.0f);

	Point points[6] = {Point(30, 30), Point(180, 30), Point(180, 130),
						Point(130, 130), Point(130, 80), Point(30, 80)};
	graphics.DrawPolygon(&RedPen, points, 6);
}


/*
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen BlackPen(Color(255, 0, 0, 0), 20.0f);
	graphics.DrawRectangle(&BlackPen, 30, 30, 100, 100);

	BlackPen.SetLineJoin(LineJoinRound);
	graphics.DrawRectangle(&BlackPen, 170, 30, 100, 100);
*/

/*
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen BlackPen(Color(255, 0, 0, 0), 10.0f);
	graphics.DrawEllipse(&BlackPen, 30, 30, 100, 100);
	graphics.DrawEllipse(&BlackPen, 150, 30, 200, 100);
*/

/*
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen RedPen(Color(255, 192, 0, 0), 2.0f);
	Pen GrayPen(Color(255, 192, 192, 192), 15.0f);

	graphics.DrawEllipse(&GrayPen, 30, 30, 150, 150);

	graphics.DrawArc(&RedPen, 30, 30, 150, 150, 0.0f, 90.0f);
	graphics.DrawPie(&RedPen, 30, 30, 150, 150, 180.0f, 90.0f);
*/