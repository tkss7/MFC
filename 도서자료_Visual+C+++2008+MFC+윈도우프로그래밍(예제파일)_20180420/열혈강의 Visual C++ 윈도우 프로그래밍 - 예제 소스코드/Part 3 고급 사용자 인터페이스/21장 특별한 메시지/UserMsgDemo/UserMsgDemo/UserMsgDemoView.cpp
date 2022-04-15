
// UserMsgDemoView.cpp : CUserMsgDemoView 클래스의 구현
//

#include "stdafx.h"
#include "UserMsgDemo.h"

#include "UserMsgDemoDoc.h"
#include "UserMsgDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CUserMsgDemoView

IMPLEMENT_DYNCREATE(CUserMsgDemoView, CView)

BEGIN_MESSAGE_MAP(CUserMsgDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(UM_TESTMESSAGE, &CUserMsgDemoView::OnTestMessage)
END_MESSAGE_MAP()

// CUserMsgDemoView 생성/소멸

CUserMsgDemoView::CUserMsgDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CUserMsgDemoView::~CUserMsgDemoView()
{
}

BOOL CUserMsgDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CUserMsgDemoView 그리기

void CUserMsgDemoView::OnDraw(CDC* /*pDC*/)
{
	CUserMsgDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CUserMsgDemoView 인쇄

BOOL CUserMsgDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CUserMsgDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CUserMsgDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CUserMsgDemoView 진단

#ifdef _DEBUG
void CUserMsgDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CUserMsgDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserMsgDemoDoc* CUserMsgDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserMsgDemoDoc)));
	return (CUserMsgDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserMsgDemoView 메시지 처리기

LRESULT CUserMsgDemoView::OnTestMessage(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(_T("CUserMsgDemoView::OnTestMessage()"));
	return 0;
}
