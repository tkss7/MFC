
// DateTimeBtnView.cpp : CDateTimeBtnView 클래스의 구현
//

#include "stdafx.h"
#include "DateTimeBtn.h"

#include "DateTimeBtnDoc.h"
#include "DateTimeBtnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDateTimeBtnView

IMPLEMENT_DYNCREATE(CDateTimeBtnView, CView)

BEGIN_MESSAGE_MAP(CDateTimeBtnView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDateTimeBtnView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDateTimeBtnView 생성/소멸

CDateTimeBtnView::CDateTimeBtnView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDateTimeBtnView::~CDateTimeBtnView()
{
}

BOOL CDateTimeBtnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CDateTimeBtnView 그리기

void CDateTimeBtnView::OnDraw(CDC* /*pDC*/)
{
	CDateTimeBtnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CDateTimeBtnView 인쇄


void CDateTimeBtnView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CDateTimeBtnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CDateTimeBtnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CDateTimeBtnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CDateTimeBtnView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDateTimeBtnView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CDateTimeBtnView 진단

#ifdef _DEBUG
void CDateTimeBtnView::AssertValid() const
{
	CView::AssertValid();
}

void CDateTimeBtnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDateTimeBtnDoc* CDateTimeBtnView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDateTimeBtnDoc)));
	return (CDateTimeBtnDoc*)m_pDocument;
}
#endif //_DEBUG


// CDateTimeBtnView 메시지 처리기
