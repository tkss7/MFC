
// LogonDemo2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "LogonDemo2.h"
#include "LogonDemo2Dlg.h"
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


// CLogonDemo2Dlg 대화 상자



CLogonDemo2Dlg::CLogonDemo2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LOGONDEMO2_DIALOG, pParent)
	, m_strId(_T(""))
	, m_strPwd(_T(""))
	, m_strLinkAddress(_T("http://naver.com"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLogonDemo2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strId);
	DDV_MaxChars(pDX, m_strId, 12);
	DDX_Text(pDX, IDC_EDIT2, m_strPwd);
	DDV_MaxChars(pDX, m_strPwd, 32);
	DDX_Text(pDX, IDC_EDIT3, m_strLinkAddress);
	DDX_Control(pDX, IDC_SYSLINK1, m_linkCtrl);
}

BEGIN_MESSAGE_MAP(CLogonDemo2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLogonDemo2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLogonDemo2Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT3, &CLogonDemo2Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CLogonDemo2Dlg::OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_SYSLINK1, &CLogonDemo2Dlg::OnNMClickSyslink1)
END_MESSAGE_MAP()


// CLogonDemo2Dlg 메시지 처리기
                                     //WM_CREATE
BOOL CLogonDemo2Dlg::OnInitDialog()  //WM_INITDIALOG
{
	CDialog::OnInitDialog(); // 자동으로 호출함 (UpdateData(false)) 

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
	//CString strText = _T("id 입력");
	//SetDlgItemText(IDC_EDIT1, strText); //변수값을 화면에 출력 
	m_strId = _T("id 입력");
	UpdateData(FALSE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CLogonDemo2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLogonDemo2Dlg::OnPaint()
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
HCURSOR CLogonDemo2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLogonDemo2Dlg::OnBnClickedOk()
{
	//CString strId;
	//CString strPwd;
	//GetDlgItemText(IDC_EDIT1, strId); //화면의 값을 변수로 읽어 들인다 
	//GetDlgItemText(IDC_EDIT2, strPwd);
	UpdateData();

	if (m_strId == _T("aaaa") && m_strPwd == _T("1234")) {
		CDialog::OnOK();
	}
	else {
		MessageBox(_T("아이디 또는 비밀번호가 잘못되었습니다"));
	}

	//CDialog::OnOK();
}


void CLogonDemo2Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialog::OnCancel();
}


void CLogonDemo2Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CLogonDemo2Dlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	if (m_strLinkAddress.IsEmpty()) { // 문자열의 길이가 0
		MessageBox(_T("주소를 입력해주세요"));
		return;
	}

	// 새로운 브라우저 실행
	::ShellExecute(NULL, _T("open"), m_strLinkAddress, NULL, NULL, SW_SHOW);
}


void CLogonDemo2Dlg::OnNMClickSyslink1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	UpdateData(); // 데이터를 읽어옴
	CString strUrl;
	m_linkCtrl.GetItemUrl(0, strUrl);
	::ShellExecute(NULL, _T("open"), strUrl, NULL, NULL, SW_SHOW);

	*pResult = 0;
}
