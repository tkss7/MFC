
// TextRgnView.cpp : CTextRgnView 클래스의 구현
//

#include "stdafx.h"
#include "TextRgn.h"

#include "TextRgnDoc.h"
#include "TextRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextRgnView

IMPLEMENT_DYNCREATE(CTextRgnView, CView)

BEGIN_MESSAGE_MAP(CTextRgnView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTextRgnView 생성/소멸

CTextRgnView::CTextRgnView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTextRgnView::~CTextRgnView()
{
}

BOOL CTextRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTextRgnView 그리기

void CTextRgnView::OnDraw(CDC* /*pDC*/)
{
	CTextRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTextRgnView 인쇄

BOOL CTextRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTextRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTextRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTextRgnView 진단

#ifdef _DEBUG
void CTextRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CTextRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextRgnDoc* CTextRgnView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextRgnDoc)));
	return (CTextRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextRgnView 메시지 처리기

void CTextRgnView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//임의의 두 사각형을 
	//각기 다른 색상(붉은색과 회색)으로 칠한다.
	CRect rectLeft	= CRect(50, 50, 250, 150);
	CRect rectRight	= CRect(250, 50, 450, 150);
	dc.FillSolidRect(&rectLeft, RGB(192, 0, 0));
	dc.FillSolidRect(&rectRight, RGB(192, 192, 192));

	//앞서 만든 두 사각형을 별도의 영역으로 만든다.
	CRgn rgnLeft, rgnRight;
	rgnLeft.CreateRectRgnIndirect(rectLeft);
	rgnRight.CreateRectRgnIndirect(rectRight);

	//DC의 폰트를 Arial Black(높이 72)으로 바꾼다.
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 72;
	wsprintf(lf.lfFaceName, _T("%s"), _T("Arial Black"));
	CFont NewFont;
	NewFont.CreateFontIndirect(&lf);
	CFont* pOldFont = dc.SelectObject(&NewFont);

	dc.SetBkMode(TRANSPARENT);
//	dc.TextOut(60, 65, TEXT("TEST STRING"));

	//왼쪽 영역을 선택하여 문자열을 출력한다.
	dc.SetTextColor(RGB(192, 192, 192));
	dc.SelectClipRgn(&rgnLeft);
	dc.TextOut(60, 65, TEXT("TEST STRING"));

	//오른쪽 영역을 선택하여 문자열을 출력한다.
	dc.SetTextColor(RGB(192, 0, 0));
	dc.SelectClipRgn(&rgnRight);
	dc.TextOut(60, 65, TEXT("TEST STRING"));

	dc.SelectObject(pOldFont);
}
