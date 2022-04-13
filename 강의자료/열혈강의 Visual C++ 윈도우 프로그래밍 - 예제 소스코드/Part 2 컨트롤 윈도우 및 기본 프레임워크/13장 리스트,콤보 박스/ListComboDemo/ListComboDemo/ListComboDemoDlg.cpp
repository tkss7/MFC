
// ListComboDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ListComboDemo.h"
#include "ListComboDemoDlg.h"

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


// CListComboDemoDlg 대화 상자




CListComboDemoDlg::CListComboDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListComboDemoDlg::IDD, pParent)
	, m_strInput(_T(""))
	, m_strSelected(_T(""))
	, m_strAddress(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListComboDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_Edit_Input, m_strInput);
	DDX_Text(pDX, IDC_Static_Selected, m_strSelected);
	DDX_Control(pDX, IDC_Combo_Address, m_Combo_Address);
	DDX_CBString(pDX, IDC_Combo_Address, m_strAddress);
}

BEGIN_MESSAGE_MAP(CListComboDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Button_InsertString, &CListComboDemoDlg::OnBnClickedButtonInsertstring)
	ON_BN_CLICKED(IDC_Button_AddString, &CListComboDemoDlg::OnBnClickedButtonAddstring)
	ON_BN_CLICKED(IDC_Button_Find, &CListComboDemoDlg::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_Button_FindExact, &CListComboDemoDlg::OnBnClickedButtonFindexact)
	ON_LBN_SELCHANGE(IDC_LIST1, &CListComboDemoDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_Button_AddAddress, &CListComboDemoDlg::OnBnClickedButtonAddaddress)
END_MESSAGE_MAP()


// CListComboDemoDlg 메시지 처리기

BOOL CListComboDemoDlg::OnInitDialog()
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

	m_Combo_Address.AddString(_T("www.freelec.co.kr"));
	m_Combo_Address.AddString(_T("cafe.naver.com/windev"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListComboDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListComboDemoDlg::OnPaint()
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
HCURSOR CListComboDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListComboDemoDlg::OnBnClickedButtonInsertstring()
{
	UpdateData();
	m_List.InsertString(0, m_strInput);
}

void CListComboDemoDlg::OnBnClickedButtonAddstring()
{
	UpdateData();
	m_List.AddString(m_strInput);
}

void CListComboDemoDlg::OnBnClickedButtonFind()
{
	UpdateData();
	CString strTmp = _T(""), strFind = _T("");
	int nIndex = m_List.FindString(-1, m_strInput);
	if(nIndex != LB_ERR)
	{
		m_List.GetText(nIndex, strFind);
		strTmp.Format(_T("%d:%s"), nIndex, strFind);
		AfxMessageBox(strTmp);
	}
	else
	{
		AfxMessageBox(_T("일치하는 항목을 찾을 수 없습니다."));
	}
}

void CListComboDemoDlg::OnBnClickedButtonFindexact()
{
	UpdateData();
	CString strTmp = _T(""), strFind = _T("");
	int nIndex = m_List.FindStringExact(-1, m_strInput);
	if(nIndex != LB_ERR)
	{
		m_List.GetText(nIndex, strFind);
		strTmp.Format(_T("%d:%s"), nIndex, strFind);
		AfxMessageBox(strTmp);
	}
	else
	{
		AfxMessageBox(_T("일치하는 항목을 찾을 수 없습니다."));
	}
}

void CListComboDemoDlg::OnLbnSelchangeList1()
{
	int nIndex = m_List.GetCurSel();
	if(nIndex != LB_ERR)
	{
		m_List.GetText(nIndex, m_strSelected);
		UpdateData(FALSE);
	}
}

void CListComboDemoDlg::OnBnClickedButtonAddaddress()
{
	UpdateData(TRUE);
	//콤보 박스와 리스트 박스에 모두 추가
	m_Combo_Address.AddString(m_strAddress);
	m_List.AddString(m_strAddress);

	//입력 문자열 초기화
	m_Combo_Address.SetEditSel(0, -1);
	m_Combo_Address.Clear();
}
