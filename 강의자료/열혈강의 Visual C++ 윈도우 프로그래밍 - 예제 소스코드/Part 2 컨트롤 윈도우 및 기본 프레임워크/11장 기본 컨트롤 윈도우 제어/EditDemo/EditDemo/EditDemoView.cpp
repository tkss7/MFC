
// EditDemoView.cpp : CEditDemoView 클래스의 구현
//

#include "stdafx.h"
#include "EditDemo.h"

#include "EditDemoDoc.h"
#include "EditDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDemoView

IMPLEMENT_DYNCREATE(CEditDemoView, CView)

BEGIN_MESSAGE_MAP(CEditDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CEditDemoView 생성/소멸

CEditDemoView::CEditDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CEditDemoView::~CEditDemoView()
{
}

BOOL CEditDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CEditDemoView 그리기

void CEditDemoView::OnDraw(CDC* /*pDC*/)
{
	CEditDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CEditDemoView 인쇄

BOOL CEditDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CEditDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CEditDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CEditDemoView 진단

#ifdef _DEBUG
void CEditDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CEditDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditDemoDoc* CEditDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditDemoDoc)));
	return (CEditDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditDemoView 메시지 처리기

int CEditDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndEdit.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER |
					ES_AUTOHSCROLL,
					CRect(20, 20, 220, 36), this, 1234);

	return 0;
}
