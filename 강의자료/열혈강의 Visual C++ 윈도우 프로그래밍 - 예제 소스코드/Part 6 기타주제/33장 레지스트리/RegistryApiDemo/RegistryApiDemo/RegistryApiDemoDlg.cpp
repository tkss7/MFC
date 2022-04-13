
// RegistryApiDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "RegistryApiDemo.h"
#include "RegistryApiDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CRegistryApiDemoDlg 대화 상자




CRegistryApiDemoDlg::CRegistryApiDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegistryApiDemoDlg::IDD, pParent)
	, m_strName(_T("Ho-sung Choi"))
	, m_dwNumber(7)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegistryApiDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Edit_Name, m_strName);
	DDX_Text(pDX, IDC_Edit_Number, m_dwNumber);
}

BEGIN_MESSAGE_MAP(CRegistryApiDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Button_CreateKey, &CRegistryApiDemoDlg::OnBnClickedButtonCreatekey)
	ON_BN_CLICKED(IDC_Button_SetName, &CRegistryApiDemoDlg::OnBnClickedButtonSetname)
	ON_BN_CLICKED(IDC_Button_SetNumber, &CRegistryApiDemoDlg::OnBnClickedButtonSetnumber)
	ON_BN_CLICKED(IDC_Button_SetData, &CRegistryApiDemoDlg::OnBnClickedButtonSetdata)
	ON_BN_CLICKED(IDC_Button_LoadAll, &CRegistryApiDemoDlg::OnBnClickedButtonLoadall)
END_MESSAGE_MAP()


// CRegistryApiDemoDlg 메시지 처리기

BOOL CRegistryApiDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRegistryApiDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CRegistryApiDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

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
HCURSOR CRegistryApiDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRegistryApiDemoDlg::OnBnClickedButtonCreatekey()
{
	DWORD dwReturn = 0;
	HKEY hKey = NULL;

	dwReturn = ::RegCreateKeyEx(HKEY_CURRENT_USER,
								_T("Software\\RegistryApiDemo"),
								0,
								NULL,
								REG_OPTION_NON_VOLATILE,
								KEY_ALL_ACCESS,
								NULL,
								&hKey,
								NULL);
	if(dwReturn != ERROR_SUCCESS)
	{
		AfxMessageBox(_T("ERROR: Failed to create new registry key!"));
		return;
	}

	::RegCloseKey(hKey);
}

void CRegistryApiDemoDlg::OnBnClickedButtonSetname()
{
	UpdateData(TRUE);

	DWORD dwReturn = 0;
	HKEY hKey = NULL;
	dwReturn = ::RegOpenKeyEx(HKEY_CURRENT_USER,
							_T("Software\\RegistryApiDemo"),
							0,
							KEY_WRITE,
							&hKey);
	if(dwReturn == ERROR_SUCCESS)
	{
		::RegSetValueEx(hKey,
						_T("Name"),
						NULL,
						REG_SZ,
						(BYTE*)m_strName.GetBuffer(m_strName.GetLength()),
						m_strName.GetLength() * sizeof(TCHAR));

		::RegCloseKey(hKey);
	}
}

void CRegistryApiDemoDlg::OnBnClickedButtonSetnumber()
{
	UpdateData(TRUE);

	DWORD dwReturn = 0;
	HKEY hKey = NULL;
	dwReturn = ::RegOpenKeyEx(HKEY_CURRENT_USER,
							_T("Software\\RegistryApiDemo"),
							0,
							KEY_WRITE,
							&hKey);
	if(dwReturn == ERROR_SUCCESS)
	{
		::RegSetValueEx(hKey,
						_T("Number"),
						NULL,
						REG_DWORD,
						(BYTE*)&m_dwNumber,
						sizeof(m_dwNumber));

		::RegCloseKey(hKey);
	}
}

void CRegistryApiDemoDlg::OnBnClickedButtonSetdata()
{
	TEST_DATA TestData;
	::ZeroMemory(&TestData, sizeof(TestData));
	TestData.nType	= 10;
	TestData.dwData	= 15;
	wsprintf(TestData.szData, _T("%s"), _T("TEST DATA STRING"));

	DWORD dwReturn = 0;
	HKEY hKey = NULL;
	dwReturn = ::RegOpenKeyEx(HKEY_CURRENT_USER,
							_T("Software\\RegistryApiDemo"),
							0,
							KEY_WRITE,
							&hKey);
	if(dwReturn == ERROR_SUCCESS)
	{
		::RegSetValueEx(hKey,
						_T("Data"),
						NULL,
						REG_BINARY,
						(BYTE*)&TestData,
						sizeof(TestData));

		::RegCloseKey(hKey);
	}
}

void CRegistryApiDemoDlg::OnBnClickedButtonLoadall()
{
	DWORD dwReturn = 0, dwBufferSize = 0;
	HKEY hKey = NULL;

	TCHAR szName[256] = {0};
	DWORD dwNumber = 0;
	TEST_DATA TestData;
	::ZeroMemory(&TestData, sizeof(TestData));

	dwReturn = ::RegOpenKeyEx(HKEY_CURRENT_USER,
							_T("Software\\RegistryApiDemo"),
							0,
							KEY_READ,
							&hKey);
	if(dwReturn == ERROR_SUCCESS)
	{
		dwBufferSize = sizeof(szName);
		dwReturn = ::RegQueryValueEx(hKey, TEXT("Name"), NULL, NULL, 
								(BYTE*)szName, &dwBufferSize);

		dwBufferSize = sizeof(dwNumber);
		dwReturn = ::RegQueryValueEx(hKey, TEXT("Number"), NULL, NULL, 
								(BYTE*)&dwNumber, &dwBufferSize);

		dwBufferSize = sizeof(TestData);
		dwReturn = ::RegQueryValueEx(hKey, TEXT("Data"), NULL, NULL, 
								(BYTE*)&TestData, &dwBufferSize);

		::RegCloseKey(hKey);
	}
}
