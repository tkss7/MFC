
// GroupListDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "GroupListDemo.h"
#include "GroupListDemoDlg.h"

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


// CGroupListDemoDlg 대화 상자




CGroupListDemoDlg::CGroupListDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGroupListDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGroupListDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CGroupListDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CGroupListDemoDlg 메시지 처리기

BOOL CGroupListDemoDlg::OnInitDialog()
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

	//1.컬럼 추가
	m_List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 200);

	//2.아이콘 이미지 리스트 생성 및 설정
	static CImageList ImgList, ImgListSmall;
	ImgList.Create(48, 48, ILC_COLOR32, 5, 0);
	ImgListSmall.Create(16, 16, ILC_COLOR32, 5, 0);

	m_List.SetImageList(&ImgList, LVSIL_NORMAL);
	m_List.SetImageList(&ImgListSmall, LVSIL_SMALL);

	//3.그룹 생성 및 추가
	LVGROUP group;
	::ZeroMemory(&group, sizeof(group));
	group.cbSize	= sizeof(group);
	group.mask		= LVGF_HEADER | LVGF_GROUPID;
	group.pszHeader	= _T("First Group");
	group.iGroupId	= 10;
	m_List.InsertGroup(-1, &group);

	group.pszHeader	= _T("Second Group");
	group.iGroupId	= 20;
	m_List.InsertGroup(-1, &group);

	//4.아이템 추가
	LVITEM item;
	::ZeroMemory(&item, sizeof(item));
	item.mask		= LVIF_TEXT | LVIF_IMAGE | LVIF_GROUPID;
	CString strItem = _T("");
	for(int i = 0; i < 5; ++i)
	{
		ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));
		ImgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));
		strItem.Format(_T("%dth Item"), i);

		item.pszText	= strItem.GetBuffer();
		item.iItem		= i;
		item.iImage		= i;
		item.iGroupId	= 10;
		m_List.InsertItem(&item);

		item.iGroupId	= 20;
		m_List.InsertItem(&item);
	}

	//5.그룹 뷰 활성화 및 확장 스타일 적용
	m_List.EnableGroupView(TRUE);

	DWORD dwExStyle = m_List.GetExtendedStyle();
	m_List.SetExtendedStyle(dwExStyle |
						LVS_EX_CHECKBOXES | LVS_EX_BORDERSELECT);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGroupListDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGroupListDemoDlg::OnPaint()
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
HCURSOR CGroupListDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

