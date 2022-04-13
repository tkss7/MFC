
// DrawTextDemoView.cpp : CDrawTextDemoView 클래스의 구현
//

#include "stdafx.h"
#include "DrawTextDemo.h"

#include "DrawTextDemoDoc.h"
#include "DrawTextDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawTextDemoView

IMPLEMENT_DYNCREATE(CDrawTextDemoView, CView)

BEGIN_MESSAGE_MAP(CDrawTextDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CDrawTextDemoView 생성/소멸

CDrawTextDemoView::CDrawTextDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDrawTextDemoView::~CDrawTextDemoView()
{
}

BOOL CDrawTextDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDrawTextDemoView 그리기

void CDrawTextDemoView::OnDraw(CDC* /*pDC*/)
{
	CDrawTextDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDrawTextDemoView 인쇄

BOOL CDrawTextDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDrawTextDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDrawTextDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CDrawTextDemoView 진단

#ifdef _DEBUG
void CDrawTextDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawTextDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawTextDemoDoc* CDrawTextDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawTextDemoDoc)));
	return (CDrawTextDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawTextDemoView 메시지 처리기

void CDrawTextDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//문자열이 그려질 대상 사각형을 회색으로 칠한다.
	CRect Rect(50, 50, 250, 100);
	dc.FillSolidRect(&Rect, RGB(192, 192, 192));

	CFont Font;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 24;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));

	Font.CreateFontIndirect(&lf);
	CFont* pOldFont = dc.SelectObject(&Font);

	//문자열의 색상을 붉은 색으로 바꾼다.
	dc.SetTextColor(RGB(192, 0, 0));
	//대상 사각형에 문자열을 그린다.
	dc.DrawText(TEXT("This is the test string!!!!!!"), &Rect, DT_WORDBREAK);

	dc.SelectObject(pOldFont);
}
