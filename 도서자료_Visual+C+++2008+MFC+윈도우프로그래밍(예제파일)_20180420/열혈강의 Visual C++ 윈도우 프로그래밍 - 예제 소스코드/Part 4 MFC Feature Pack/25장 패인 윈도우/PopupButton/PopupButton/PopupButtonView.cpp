
// PopupButtonView.cpp : CPopupButtonView 클래스의 구현
//

#include "stdafx.h"
#include "PopupButton.h"

#include "PopupButtonDoc.h"
#include "PopupButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPopupButtonView

IMPLEMENT_DYNCREATE(CPopupButtonView, CView)

BEGIN_MESSAGE_MAP(CPopupButtonView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPopupButtonView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPopupButtonView 생성/소멸

CPopupButtonView::CPopupButtonView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPopupButtonView::~CPopupButtonView()
{
}

BOOL CPopupButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPopupButtonView 그리기

void CPopupButtonView::OnDraw(CDC* /*pDC*/)
{
	CPopupButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPopupButtonView 인쇄


void CPopupButtonView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CPopupButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPopupButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPopupButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPopupButtonView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPopupButtonView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CPopupButtonView 진단

#ifdef _DEBUG
void CPopupButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CPopupButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopupButtonDoc* CPopupButtonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopupButtonDoc)));
	return (CPopupButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CPopupButtonView 메시지 처리기
