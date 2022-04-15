
// NewToolBarView.cpp : CNewToolBarView 클래스의 구현
//

#include "stdafx.h"
#include "NewToolBar.h"

#include "NewToolBarDoc.h"
#include "NewToolBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNewToolBarView

IMPLEMENT_DYNCREATE(CNewToolBarView, CView)

BEGIN_MESSAGE_MAP(CNewToolBarView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNewToolBarView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CNewToolBarView 생성/소멸

CNewToolBarView::CNewToolBarView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CNewToolBarView::~CNewToolBarView()
{
}

BOOL CNewToolBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNewToolBarView 그리기

void CNewToolBarView::OnDraw(CDC* /*pDC*/)
{
	CNewToolBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CNewToolBarView 인쇄


void CNewToolBarView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CNewToolBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNewToolBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CNewToolBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CNewToolBarView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNewToolBarView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CNewToolBarView 진단

#ifdef _DEBUG
void CNewToolBarView::AssertValid() const
{
	CView::AssertValid();
}

void CNewToolBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNewToolBarDoc* CNewToolBarView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNewToolBarDoc)));
	return (CNewToolBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CNewToolBarView 메시지 처리기
