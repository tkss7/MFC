
// Vs2005StyleView.cpp : CVs2005StyleView 클래스의 구현
//

#include "stdafx.h"
#include "Vs2005Style.h"

#include "Vs2005StyleDoc.h"
#include "Vs2005StyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVs2005StyleView

IMPLEMENT_DYNCREATE(CVs2005StyleView, CView)

BEGIN_MESSAGE_MAP(CVs2005StyleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVs2005StyleView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CVs2005StyleView 생성/소멸

CVs2005StyleView::CVs2005StyleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CVs2005StyleView::~CVs2005StyleView()
{
}

BOOL CVs2005StyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CVs2005StyleView 그리기

void CVs2005StyleView::OnDraw(CDC* /*pDC*/)
{
	CVs2005StyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CVs2005StyleView 인쇄


void CVs2005StyleView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CVs2005StyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CVs2005StyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CVs2005StyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CVs2005StyleView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVs2005StyleView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CVs2005StyleView 진단

#ifdef _DEBUG
void CVs2005StyleView::AssertValid() const
{
	CView::AssertValid();
}

void CVs2005StyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVs2005StyleDoc* CVs2005StyleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVs2005StyleDoc)));
	return (CVs2005StyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CVs2005StyleView 메시지 처리기
