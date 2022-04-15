
// Office2003StyleView.cpp : COffice2003StyleView 클래스의 구현
//

#include "stdafx.h"
#include "Office2003Style.h"

#include "Office2003StyleDoc.h"
#include "Office2003StyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COffice2003StyleView

IMPLEMENT_DYNCREATE(COffice2003StyleView, CView)

BEGIN_MESSAGE_MAP(COffice2003StyleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COffice2003StyleView::OnFilePrintPreview)
END_MESSAGE_MAP()

// COffice2003StyleView 생성/소멸

COffice2003StyleView::COffice2003StyleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COffice2003StyleView::~COffice2003StyleView()
{
}

BOOL COffice2003StyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COffice2003StyleView 그리기

void COffice2003StyleView::OnDraw(CDC* /*pDC*/)
{
	COffice2003StyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// COffice2003StyleView 인쇄


void COffice2003StyleView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL COffice2003StyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void COffice2003StyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void COffice2003StyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void COffice2003StyleView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COffice2003StyleView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// COffice2003StyleView 진단

#ifdef _DEBUG
void COffice2003StyleView::AssertValid() const
{
	CView::AssertValid();
}

void COffice2003StyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COffice2003StyleDoc* COffice2003StyleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COffice2003StyleDoc)));
	return (COffice2003StyleDoc*)m_pDocument;
}
#endif //_DEBUG


// COffice2003StyleView 메시지 처리기
