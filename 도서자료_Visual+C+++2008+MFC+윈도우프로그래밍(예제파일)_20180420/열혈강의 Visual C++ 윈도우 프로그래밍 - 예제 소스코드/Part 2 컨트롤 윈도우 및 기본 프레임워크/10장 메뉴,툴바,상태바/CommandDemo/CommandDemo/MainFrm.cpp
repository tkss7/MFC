
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "CommandDemo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_Menu_Start, &CMainFrame::OnMenuStart)
	ON_COMMAND(ID_Menu_Stop, &CMainFrame::OnMenuStop)
	ON_UPDATE_COMMAND_UI(ID_Menu_Start, &CMainFrame::OnUpdateMenuStart)
	ON_UPDATE_COMMAND_UI(ID_Menu_Stop, &CMainFrame::OnUpdateMenuStop)
	ON_COMMAND(ID_Menu_Pause, &CMainFrame::OnMenuPause)
	ON_UPDATE_COMMAND_UI(ID_Menu_Pause, &CMainFrame::OnUpdateMenuPause)
	ON_COMMAND(ID_Menu_Sub1, &CMainFrame::OnMenuSub1)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	m_bRunning = FALSE;
	m_bPause = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기

void CMainFrame::OnMenuStart()
{
	//실행중임을 의미하는 플래그를 TRUE 세트함.
	m_bRunning = TRUE;
	AfxMessageBox(_T("시작 메뉴를 선택하였습니다. - CMainFrame"));
}

void CMainFrame::OnMenuStop()
{
	//실행이 종료되었다는 의미로 플래그를 FALSE로 세트함.
	m_bRunning = FALSE;
	AfxMessageBox(_T("종료 메뉴를 선택하였습니다. - CMainFrame"));
}

void CMainFrame::OnUpdateMenuStart(CCmdUI *pCmdUI)
{
	//이미 실행중(TRUE)이면 !연산으로 FALSE가 되므로 "시작"메뉴가 Disable됨.
	pCmdUI->Enable(!m_bRunning);
}

void CMainFrame::OnUpdateMenuStop(CCmdUI *pCmdUI)
{
	//이미 실행중이므로 "종료"메뉴를 선택할 수 있도록 활성화함.
	pCmdUI->Enable(m_bRunning);
}

void CMainFrame::OnMenuPause()
{
	if(m_bPause)	AfxMessageBox(_T("다시 시작합니다."));
	else			AfxMessageBox(_T("일시 정지합니다."));

	m_bPause = !m_bPause;
}

void CMainFrame::OnUpdateMenuPause(CCmdUI *pCmdUI)
{
//	if(m_bPause)	pCmdUI->SetText(_T("다시 시작"));
//	else			pCmdUI->SetText(_T("일시 정지"));
	if(m_bPause)	pCmdUI->SetCheck(TRUE);
	else			pCmdUI->SetCheck(FALSE);
}

void CMainFrame::OnMenuSub1()
{
	AfxMessageBox(_T("서브 메뉴를 선택하였습니다."));
}
