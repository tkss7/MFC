
// TestAppMfcFpView.cpp : CTestAppMfcFpView 클래스의 구현
//

#include "stdafx.h"
#include "TestAppMfcFp.h"

#include "TestAppMfcFpDoc.h"
#include "TestAppMfcFpView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestAppMfcFpView

IMPLEMENT_DYNCREATE(CTestAppMfcFpView, CView)

BEGIN_MESSAGE_MAP(CTestAppMfcFpView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestAppMfcFpView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTestAppMfcFpView 생성/소멸

CTestAppMfcFpView::CTestAppMfcFpView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTestAppMfcFpView::~CTestAppMfcFpView()
{
}

BOOL CTestAppMfcFpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTestAppMfcFpView 그리기

void CTestAppMfcFpView::OnDraw(CDC* /*pDC*/)
{
	CTestAppMfcFpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTestAppMfcFpView 인쇄


void CTestAppMfcFpView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CTestAppMfcFpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTestAppMfcFpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTestAppMfcFpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTestAppMfcFpView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestAppMfcFpView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// CTestAppMfcFpView 진단

#ifdef _DEBUG
void CTestAppMfcFpView::AssertValid() const
{
	CView::AssertValid();
}

void CTestAppMfcFpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestAppMfcFpDoc* CTestAppMfcFpView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestAppMfcFpDoc)));
	return (CTestAppMfcFpDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestAppMfcFpView 메시지 처리기
