
// TextOutDemoView.cpp : CTextOutDemoView 클래스의 구현
//

#include "stdafx.h"
#include "TextOutDemo.h"

#include "TextOutDemoDoc.h"
#include "TextOutDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextOutDemoView

IMPLEMENT_DYNCREATE(CTextOutDemoView, CView)

BEGIN_MESSAGE_MAP(CTextOutDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTextOutDemoView 생성/소멸

CTextOutDemoView::CTextOutDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTextOutDemoView::~CTextOutDemoView()
{
}

BOOL CTextOutDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTextOutDemoView 그리기

void CTextOutDemoView::OnDraw(CDC* /*pDC*/)
{
	CTextOutDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTextOutDemoView 인쇄

BOOL CTextOutDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTextOutDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTextOutDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTextOutDemoView 진단

#ifdef _DEBUG
void CTextOutDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTextOutDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextOutDemoDoc* CTextOutDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextOutDemoDoc)));
	return (CTextOutDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextOutDemoView 메시지 처리기

void CTextOutDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CFont Font;
	CFont* pOldFont;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 36;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));
	Font.CreateFontIndirect(&lf);
	pOldFont = dc.SelectObject(&Font);

	//TextOut을 이용하여 그냥 출력 '\t'가 반영되지 않는다.
	dc.TextOut(20, 20, TEXT("\tTest String!"));

	//TabbedTextOut이용하여 '\t'가 들어간 문자열 출력
	int nTabStop = 40;
	dc.TabbedTextOut(20, 70, TEXT("\tTest String!"), 1, &nTabStop, 20);
	dc.TabbedTextOut(20, 120, TEXT("\t\tTest String!"), 1, &nTabStop, 20);
	dc.SelectObject(pOldFont);
}


/*	//Test String 출력
	int nY = 0;
	CFont Font;
	CFont* pOldFont;

	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));

	for(int i = 10; i < 25; i++)
	{
		lf.lfHeight = i;
		nY += i;
		//Arial, 크기 10 ~ 24까지 폰트 객체를 생성한다.
		Font.CreateFontIndirect(&lf);
		//생성된 폰트로 "Test String!" 이라는 문자열을 출력한다.
		pOldFont = dc.SelectObject(&Font);
		dc.TextOut(10, nY, TEXT("Test String!"));
		dc.SelectObject(pOldFont);
		//폰트 객체를 삭제한다.
		Font.DeleteObject();
	}
*/