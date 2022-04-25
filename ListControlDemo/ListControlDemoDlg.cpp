
// ListControlDemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ListControlDemo.h"
#include "ListControlDemoDlg.h"
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


// CListControlDemoDlg 대화 상자



CListControlDemoDlg::CListControlDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LISTCONTROLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListControlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listCtrl);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
}

BEGIN_MESSAGE_MAP(CListControlDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CListControlDemoDlg::OnLvnItemchangedList1)
ON_CBN_SELCHANGE(IDC_COMBO1, &CListControlDemoDlg::OnCbnSelchangeCombo1)
ON_NOTIFY(LVN_ENDLABELEDIT, IDC_LIST1, &CListControlDemoDlg::OnLvnEndlabeleditList1)
END_MESSAGE_MAP()


// CListControlDemoDlg 메시지 처리기

BOOL CListControlDemoDlg::OnInitDialog()
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
	//static CImageList imageList; // 이렇게 해야 소멸되지않는다.

	//imageList.Create(48, 48, ILC_COLOR32, 1, 1);
	//imageList.Add(AfxGetApp()->LoadIconW(IDR_MAINFRAME));

	//m_listCtrl.SetImageList(&imageList, LVSIL_NORMAL);

	//m_listCtrl.InsertItem(0, _T("1th Test Item"));
	//m_listCtrl.InsertItem(1, _T("안녕하세요"));


	//static CImageList imageList; // 이렇게 해야 소멸되지않는다.

	imageList.Create(48, 48, ILC_COLOR32, 5, 5);
	imageListSmall.Create(16, 16, ILC_COLOR32, 5, 5);
	//imageList.Add(AfxGetApp()->LoadIconW(IDR_MAINFRAME));

	for (int i = 0; i < 5; i++) {
		imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));
		imageListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));
	}
	
	m_listCtrl.InsertColumn(0, _T("이름"), LVCFMT_LEFT, 200); // 200 = 컬럼의 폭
	m_listCtrl.InsertColumn(1, _T("가격"), LVCFMT_RIGHT, 200); // LVCFMT_RIGHT = 오른쪽 정렬 
	m_listCtrl.InsertColumn(2, _T("설명"), LVCFMT_LEFT, 300);

	//컬럼 정보 출력
	m_listCtrl.SetImageList(&imageList, LVSIL_NORMAL);
	m_listCtrl.SetImageList(&imageListSmall, LVSIL_SMALL);

	//실제 자료 추가
	CString strItem;
	for (int i = 0; i < 5; i++) {
		strItem.Format(_T("%dth Test Item"), i);
		m_listCtrl.InsertItem(i, strItem, i);
	}

	LVITEM item = { 0 };
	item.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	item.pszText = _T("TEST ITEM");
	item.iItem = 5;
	item.iImage = 1;
	item.state = LVIS_SELECTED | LVIS_FOCUSED;
	m_listCtrl.InsertItem(&item);

	//5행의 1열에 금액을 추가함( 0을 기준으로하니깐 1 열)
	m_listCtrl.SetItemText(5, 1, _T("1000"));

	//5행의 2열에 설명을 추가함( 0을 기준으로하니깐 1 열)
	m_listCtrl.SetItemText(5, 2, _T("설명을 추가함"));


	//m_comboBox.InsertString(0, _T("Icon"));
	//m_comboBox.InsertString(1, _T("Small Icon"));
	//m_comboBox.InsertString(2, _T("List"));
	//m_comboBox.InsertString(3, _T("Report"));

	m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
	//m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
	//m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
	//m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListControlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListControlDemoDlg::OnPaint()
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
HCURSOR CListControlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CListControlDemoDlg::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	switch (m_comboBox.GetCurSel()) {
	case 0:
		m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_ICON);
		break;
	case 1:
		m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_SMALLICON);
		break;
	case 2:
		m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_LIST);
		break;
	case 3:
		m_listCtrl.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
		break;
	}
	
	//
	//
	//
}


void CListControlDemoDlg::OnLvnEndlabeleditList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit* pEdit = m_listCtrl.GetEditControl();
	CString strText;


	*pResult = 0;
}
