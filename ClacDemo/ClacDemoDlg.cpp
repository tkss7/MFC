
// ClacDemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ClacDemo.h"
#include "ClacDemoDlg.h"
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
public:
	afx_msg void OnBnClickedButton0();
};

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//ON_BN_CLICKED(IDC_BUTTON_0, &CAboutDlg::OnBnClickedButton0)
END_MESSAGE_MAP()


// CClacDemoDlg 대화 상자



CClacDemoDlg::CClacDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CLACDEMO_DIALOG, pParent)
	
	, m_Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClacDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, m_Result);
}

BEGIN_MESSAGE_MAP(CClacDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CClacDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_0, &CClacDemoDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_2, &CClacDemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CClacDemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CClacDemoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CClacDemoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CClacDemoDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CClacDemoDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CClacDemoDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CClacDemoDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CClacDemoDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CClacDemoDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CClacDemoDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CClacDemoDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CClacDemoDlg 메시지 처리기

BOOL CClacDemoDlg::OnInitDialog()
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

void CClacDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CClacDemoDlg::OnPaint()
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
HCURSOR CClacDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CAboutDlg::OnBnClickedButton0()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CString str;
//	GetDlgItemText(IDC_EDIT1, str);
//	SetDlgItemText(IDC_EDIT1, str + L"0");
//
//
//
//}


void CClacDemoDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	UpdateData();
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("1"));

}


void CClacDemoDlg::OnBnClickedButton0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("0"));
}
//wtof(str)

void CClacDemoDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("2"));
}


void CClacDemoDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("3"));
}


void CClacDemoDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("4"));
}


void CClacDemoDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("5"));
}


void CClacDemoDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("6"));
}


void CClacDemoDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("7"));
}


void CClacDemoDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("8"));
}


void CClacDemoDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("9"));
}


void CClacDemoDlg::OnBnClickedButtonDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("/"));
}


void CClacDemoDlg::OnBnClickedButtonMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("*"));
}


void CClacDemoDlg::OnBnClickedButtonSub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("-"));
}


void CClacDemoDlg::OnBnClickedButtonAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	SetDlgItemText(IDC_EDIT1, str + _T("+"));
}
