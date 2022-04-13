
// MdiDemoView.cpp : CMdiDemoView 클래스의 구현
//

#include "stdafx.h"
#include "MdiDemo.h"

#include "MdiDemoDoc.h"
#include "MdiDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMdiDemoView

IMPLEMENT_DYNCREATE(CMdiDemoView, CView)

BEGIN_MESSAGE_MAP(CMdiDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMdiDemoView 생성/소멸

CMdiDemoView::CMdiDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMdiDemoView::~CMdiDemoView()
{
}

BOOL CMdiDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMdiDemoView 그리기

void CMdiDemoView::OnDraw(CDC* /*pDC*/)
{
	CMdiDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMdiDemoView 인쇄

BOOL CMdiDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMdiDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMdiDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMdiDemoView 진단

#ifdef _DEBUG
void CMdiDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMdiDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMdiDemoDoc* CMdiDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMdiDemoDoc)));
	return (CMdiDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMdiDemoView 메시지 처리기

int CMdiDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CFrameWnd* pFrame = GetParentFrame();

	return 0;
}
