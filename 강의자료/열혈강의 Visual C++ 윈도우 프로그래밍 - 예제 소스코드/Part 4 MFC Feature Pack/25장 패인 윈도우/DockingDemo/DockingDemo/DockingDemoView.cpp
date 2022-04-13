
// DockingDemoView.cpp : CDockingDemoView 클래스의 구현
//

#include "stdafx.h"
#include "DockingDemo.h"

#include "DockingDemoDoc.h"
#include "DockingDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDockingDemoView

IMPLEMENT_DYNCREATE(CDockingDemoView, CView)

BEGIN_MESSAGE_MAP(CDockingDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDockingDemoView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDockingDemoView 생성/소멸

CDockingDemoView::CDockingDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDockingDemoView::~CDockingDemoView()
{
}

BOOL CDockingDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDockingDemoView 그리기

void CDockingDemoView::OnDraw(CDC* /*pDC*/)
{
	CDockingDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDockingDemoView 인쇄


void CDockingDemoView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDockingDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDockingDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDockingDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CDockingDemoView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDockingDemoView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CDockingDemoView 진단

#ifdef _DEBUG
void CDockingDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDockingDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDockingDemoDoc* CDockingDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDockingDemoDoc)));
	return (CDockingDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDockingDemoView 메시지 처리기
