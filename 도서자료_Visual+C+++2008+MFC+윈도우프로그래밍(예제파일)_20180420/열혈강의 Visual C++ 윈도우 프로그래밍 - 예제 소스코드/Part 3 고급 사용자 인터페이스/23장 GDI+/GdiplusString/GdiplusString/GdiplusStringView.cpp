
// GdiplusStringView.cpp : CGdiplusStringView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusString.h"

#include "GdiplusStringDoc.h"
#include "GdiplusStringView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusStringView

IMPLEMENT_DYNCREATE(CGdiplusStringView, CView)

BEGIN_MESSAGE_MAP(CGdiplusStringView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusStringView 생성/소멸

CGdiplusStringView::CGdiplusStringView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusStringView::~CGdiplusStringView()
{
}

BOOL CGdiplusStringView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusStringView 그리기

void CGdiplusStringView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusStringDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusStringView 인쇄

BOOL CGdiplusStringView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusStringView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusStringView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusStringView 진단

#ifdef _DEBUG
void CGdiplusStringView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusStringView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusStringDoc* CGdiplusStringView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusStringDoc)));
	return (CGdiplusStringDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusStringView 메시지 처리기

void CGdiplusStringView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Font font(_T("Arial"), 48, FontStyleBold, UnitPixel);
	SolidBrush sbrush(Color::Black);

	StringFormat format;
	format.SetHotkeyPrefix(HotkeyPrefixShow);

	graphics.DrawString(_T("Test &String"), -1, &font,
						RectF(10, 10, 300, 60),
						&format,
						&sbrush);
}


/*
	LinearGradientBrush lgBrush(Point(0, 0), Point(0, 200),
		Color::WhiteSmoke, Color::Chocolate);
	graphics.FillRectangle(&lgBrush, Rect(0, 0, 600, 150));

	Font font(_T("Arial"), 100, FontStyleBold, UnitPixel);
	PointF ptText(10.0f, 10.0f);
	HatchBrush brush(HatchStyleSmallCheckerBoard,
							Color(255, 128, 0, 0), Color::Transparent);
	graphics.DrawString(_T("Test String"), -1, &font, ptText, &brush);
*/

/*
	Font font(_T("Arial"), 48, FontStyleBold, UnitPixel);
	SolidBrush sbrush(Color::Black);
	Pen pen(Color::Blue);

	StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	format.SetLineAlignment(StringAlignmentCenter);

	graphics.DrawString(_T("Test String"), -1, &font,
						PointF(250, 10),
						&sbrush);

	graphics.DrawRectangle(&pen, RectF(10, 10, 200, 200));
	graphics.DrawString(_T("Test String"), -1, &font,
						RectF(10, 10, 200, 200),
						&format,
						&sbrush);
*/

/*
	Font font(_T("Arial"), 48, FontStyleBold, UnitPixel);
	SolidBrush sbrush(Color::Black);

	StringFormat format;
	format.SetTrimming( StringTrimmingEllipsisCharacter);

	graphics.DrawString(_T("Test String"), -1, &font,
						RectF(10, 10, 200, 50),
						&format,
						&sbrush);
*/