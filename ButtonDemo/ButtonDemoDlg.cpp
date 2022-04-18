
// ButtonDemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ButtonDemo.h"
#include "ButtonDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CButtonDemoDlg 대화 상자



CButtonDemoDlg::CButtonDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_BUTTONDEMO_DIALOG, pParent)
	, m_bAuto(FALSE)
	, m_bUpdate(FALSE)
	, m_bSystem(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_AUTO, m_bAuto);
	DDX_Check(pDX, IDC_CHECK_UPDATE, m_bUpdate);
	DDX_Check(pDX, IDC_CHECK_SYSTEM, m_bSystem);
	DDX_Control(pDX, IDC_CHECK_UPDATE, m_wndUpdate);
	DDX_Control(pDX, IDC_CHECK_SYSTEM, m_wndSystem);
}

BEGIN_MESSAGE_MAP(CButtonDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_AUTO, &CButtonDemoDlg::OnBnClickedCheckAuto)
	ON_BN_CLICKED(IDC_CHECK_SYSTEM, &CButtonDemoDlg::OnBnClickedCheckSystem)
END_MESSAGE_MAP()


// CButtonDemoDlg 메시지 처리기

BOOL CButtonDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CButtonDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CButtonDemoDlg::OnBnClickedCheckAuto()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(); // 데이터가 읽힌다. == UI에 있는 변수의 상태값들이 읽혀온다.

	//if (m_bAuto) {
	//	CWnd* pWnd = GetDlgItem(IDC_CHECK_UPDATE);
	//	if (pWnd != nullptr) {
	//		pWnd->EnableWindow(FALSE); // 비활성화
	//	}
	//}
	//else {
	//	CWnd* pWnd = GetDlgItem(IDC_CHECK_UPDATE);
	//	if (pWnd != nullptr) {
	//		pWnd->EnableWindow(TRUE); // 활성화
	//	}
	//}

	//CWnd* pWndUpdate = GetDlgItem(IDC_CHECK_UPDATE);
	//CWnd* pWndSystem = GetDlgItem(IDC_CHECK_SYSTEM);
	//if (pWndUpdate != nullptr&&pWndSystem!=nullptr) {
	//	pWndUpdate->EnableWindow(!m_bAuto); // 비활성화
	//	pWndSystem->EnableWindow(!m_bAuto); // 비활성화
	//	m_bUpdate = m_bAuto;
	//	m_bSystem = m_bAuto;
	//}
	m_wndUpdate.EnableWindow(!m_bAuto); // 값이 아닌 컨트롤로 했을 때
	m_wndSystem.EnableWindow(!m_bAuto);

	m_bUpdate = m_bAuto;
	m_bSystem = m_bAuto;

	UpdateData(FALSE);
	
}


