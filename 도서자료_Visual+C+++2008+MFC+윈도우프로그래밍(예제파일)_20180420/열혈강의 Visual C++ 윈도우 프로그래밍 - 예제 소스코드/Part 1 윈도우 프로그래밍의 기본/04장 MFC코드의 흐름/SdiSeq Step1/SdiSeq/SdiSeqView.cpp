
// SdiSeqView.cpp : CSdiSeqView 클래스의 구현
//

#include "stdafx.h"
#include "SdiSeq.h"

#include "SdiSeqDoc.h"
#include "SdiSeqView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSdiSeqView

IMPLEMENT_DYNCREATE(CSdiSeqView, CView)

BEGIN_MESSAGE_MAP(CSdiSeqView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()

// CSdiSeqView 생성/소멸

CSdiSeqView::CSdiSeqView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSdiSeqView::~CSdiSeqView()
{
}

BOOL CSdiSeqView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSdiSeqView 그리기

void CSdiSeqView::OnDraw(CDC* /*pDC*/)
{
	CSdiSeqDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSdiSeqView 인쇄

BOOL CSdiSeqView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSdiSeqView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSdiSeqView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSdiSeqView 진단

#ifdef _DEBUG
void CSdiSeqView::AssertValid() const
{
	CView::AssertValid();
}

void CSdiSeqView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSdiSeqDoc* CSdiSeqView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSdiSeqDoc)));
	return (CSdiSeqDoc*)m_pDocument;
}
#endif //_DEBUG


// CSdiSeqView 메시지 처리기

BOOL CSdiSeqView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL CSdiSeqView::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class

	return CView::DestroyWindow();
}

void CSdiSeqView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}

void CSdiSeqView::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class

	CView::PostNcDestroy();
}

int CSdiSeqView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}

void CSdiSeqView::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	CView::OnClose();
}

void CSdiSeqView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
}

void CSdiSeqView::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CView::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
}
