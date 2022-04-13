
// GdiplusTransformView.cpp : CGdiplusTransformView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusTransform.h"

#include "GdiplusTransformDoc.h"
#include "GdiplusTransformView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusTransformView

IMPLEMENT_DYNCREATE(CGdiplusTransformView, CView)

BEGIN_MESSAGE_MAP(CGdiplusTransformView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusTransformView 생성/소멸

CGdiplusTransformView::CGdiplusTransformView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusTransformView::~CGdiplusTransformView()
{
}

BOOL CGdiplusTransformView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusTransformView 그리기

void CGdiplusTransformView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusTransformDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusTransformView 인쇄

BOOL CGdiplusTransformView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusTransformView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusTransformView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusTransformView 진단

#ifdef _DEBUG
void CGdiplusTransformView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusTransformView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusTransformDoc* CGdiplusTransformView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusTransformDoc)));
	return (CGdiplusTransformDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusTransformView 메시지 처리기

void CGdiplusTransformView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Pen pen(Color::Black, 3);
	Pen pen2(Color(255, 192, 0, 0), 3);
	Pen penLine(Color(255, 192, 0, 0), 2);
	penLine.SetDashStyle(DashStyleDot);

	graphics.DrawRectangle(&pen, Rect(30, 30, 150, 100));

	graphics.TranslateTransform(100.0f, 100.0f);
	graphics.RotateTransform(45.0f);

	graphics.DrawLine(&penLine, Point(-200, 0), Point(200, 0));
	graphics.DrawLine(&penLine, Point(0, -200), Point(0, 200));
	graphics.DrawRectangle(&pen2, Rect(30, 30, 150, 100));
}

/*
	Pen pen(Color::Black, 3);
	Pen pen2(Color(255, 192, 0, 0), 3);
	Pen penLine(Color(255, 192, 0, 0), 2);
	penLine.SetDashStyle(DashStyleDot);

	graphics.DrawRectangle(&pen, Rect(30, 30, 150, 100));

	Matrix transformMatrix;
	transformMatrix.Translate(100.0f, 100.0f);
	transformMatrix.Rotate(45.0f);

	graphics.SetTransform(&transformMatrix);
	graphics.DrawLine(&penLine, Point(-200, 0), Point(200, 0));
	graphics.DrawLine(&penLine, Point(0, -200), Point(0, 200));
	graphics.DrawRectangle(&pen2, Rect(30, 30, 150, 100));
*/