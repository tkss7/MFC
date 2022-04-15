
// DuplicationCheckView.cpp : CDuplicationCheckView 클래스의 구현
//

#include "stdafx.h"
#include "DuplicationCheck.h"

#include "DuplicationCheckDoc.h"
#include "DuplicationCheckView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDuplicationCheckView

IMPLEMENT_DYNCREATE(CDuplicationCheckView, CView)

BEGIN_MESSAGE_MAP(CDuplicationCheckView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDuplicationCheckView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDuplicationCheckView 생성/소멸

CDuplicationCheckView::CDuplicationCheckView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDuplicationCheckView::~CDuplicationCheckView()
{
}

BOOL CDuplicationCheckView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDuplicationCheckView 그리기

void CDuplicationCheckView::OnDraw(CDC* /*pDC*/)
{
	CDuplicationCheckDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDuplicationCheckView 인쇄


void CDuplicationCheckView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDuplicationCheckView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDuplicationCheckView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDuplicationCheckView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CDuplicationCheckView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDuplicationCheckView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CDuplicationCheckView 진단

#ifdef _DEBUG
void CDuplicationCheckView::AssertValid() const
{
	CView::AssertValid();
}

void CDuplicationCheckView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDuplicationCheckDoc* CDuplicationCheckView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDuplicationCheckDoc)));
	return (CDuplicationCheckDoc*)m_pDocument;
}
#endif //_DEBUG


// CDuplicationCheckView 메시지 처리기
