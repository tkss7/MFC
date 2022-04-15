
// SwitchViewDemoView.cpp : CSwitchViewDemoView 클래스의 구현
//

#include "stdafx.h"
#include "SwitchViewDemo.h"

#include "SwitchViewDemoDoc.h"
#include "SwitchViewDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSwitchViewDemoView

IMPLEMENT_DYNCREATE(CSwitchViewDemoView, CView)

BEGIN_MESSAGE_MAP(CSwitchViewDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSwitchViewDemoView 생성/소멸

CSwitchViewDemoView::CSwitchViewDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSwitchViewDemoView::~CSwitchViewDemoView()
{
}

BOOL CSwitchViewDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSwitchViewDemoView 그리기

void CSwitchViewDemoView::OnDraw(CDC* /*pDC*/)
{
	CSwitchViewDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CSwitchViewDemoView 인쇄

BOOL CSwitchViewDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSwitchViewDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSwitchViewDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSwitchViewDemoView 진단

#ifdef _DEBUG
void CSwitchViewDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSwitchViewDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSwitchViewDemoDoc* CSwitchViewDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSwitchViewDemoDoc)));
	return (CSwitchViewDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSwitchViewDemoView 메시지 처리기
