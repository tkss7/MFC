
// NewStatusBarView.cpp : CNewStatusBarView 클래스의 구현
//

#include "stdafx.h"
#include "NewStatusBar.h"

#include "NewStatusBarDoc.h"
#include "NewStatusBarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNewStatusBarView

IMPLEMENT_DYNCREATE(CNewStatusBarView, CView)

BEGIN_MESSAGE_MAP(CNewStatusBarView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNewStatusBarView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CNewStatusBarView 생성/소멸

CNewStatusBarView::CNewStatusBarView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CNewStatusBarView::~CNewStatusBarView()
{
}

BOOL CNewStatusBarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNewStatusBarView 그리기

void CNewStatusBarView::OnDraw(CDC* /*pDC*/)
{
	CNewStatusBarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CNewStatusBarView 인쇄


void CNewStatusBarView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CNewStatusBarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNewStatusBarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CNewStatusBarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CNewStatusBarView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNewStatusBarView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CNewStatusBarView 진단

#ifdef _DEBUG
void CNewStatusBarView::AssertValid() const
{
	CView::AssertValid();
}

void CNewStatusBarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNewStatusBarDoc* CNewStatusBarView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNewStatusBarDoc)));
	return (CNewStatusBarDoc*)m_pDocument;
}
#endif //_DEBUG


// CNewStatusBarView 메시지 처리기
