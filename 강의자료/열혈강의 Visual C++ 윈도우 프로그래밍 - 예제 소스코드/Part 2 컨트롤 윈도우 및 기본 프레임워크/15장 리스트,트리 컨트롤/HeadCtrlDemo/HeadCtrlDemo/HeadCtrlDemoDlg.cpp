
// HeadCtrlDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "HeadCtrlDemo.h"
#include "HeadCtrlDemoDlg.h"

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


// CHeadCtrlDemoDlg 대화 상자




CHeadCtrlDemoDlg::CHeadCtrlDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHeadCtrlDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bAscending = TRUE;
}

void CHeadCtrlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CHeadCtrlDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CHeadCtrlDemoDlg::OnHdnItemclickList1)
END_MESSAGE_MAP()


// CHeadCtrlDemoDlg 메시지 처리기

BOOL CHeadCtrlDemoDlg::OnInitDialog()
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

	//아이콘 이미지 리스트 생성.
	static CImageList ImgList, ImgListSmall;
	ImgList.Create(48, 48, ILC_COLOR32, 5, 0);
	ImgListSmall.Create(16, 16, ILC_COLOR32, 5, 0);

	//이미지 리스트를 리스트 컨트롤에 설정함.
	m_List.SetImageList(&ImgList, LVSIL_NORMAL);
	m_List.SetImageList(&ImgListSmall, LVSIL_SMALL);

	//컬럼을 추가하고 리포트 스타일로 변경
	m_List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 150);
	m_List.InsertColumn(1, _T("Data"), LVCFMT_LEFT, 150);
	m_List.InsertColumn(2, _T("Description"), LVCFMT_LEFT, 150);
	m_List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	//아이템 추가
	CString strItem = _T("");
	DWORD dwSeed = ::GetTickCount();
	LVITEM item;
	::ZeroMemory(&item, sizeof(item));
	item.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM;
	for(int i = 0; i < 5; ++i)
	{
		ImgList.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));
		ImgListSmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1 + i));

		strItem.Format(_T("%dth Item"), i);

		item.pszText = strItem.GetBuffer();
		item.iItem = i;
		item.iImage = i;
		item.lParam = dwSeed + i;
		m_List.InsertItem(&item);

		strItem.Format(_T("%dth Data"), i);
		m_List.SetItemText(i, 1, strItem);

		strItem.Format(_T("%dth Desc"), i);
		m_List.SetItemText(i, 2, strItem);
	}

	//헤더 컨트롤 드래그-앤-드롭 가능
	DWORD dwExStyle = m_List.GetExtendedStyle();
	m_List.SetExtendedStyle(dwExStyle | LVS_EX_HEADERDRAGDROP );

	m_bAscending = FALSE;
	m_List.SortItems(&CHeadCtrlDemoDlg::CompareItem, (DWORD_PTR)this);
	UpdateArrow();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CHeadCtrlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHeadCtrlDemoDlg::OnPaint()
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
HCURSOR CHeadCtrlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CHeadCtrlDemoDlg::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);

	if(phdr->iItem == 0)
	{
		m_bAscending = !m_bAscending;
		UpdateArrow();
		m_List.SortItems(&CHeadCtrlDemoDlg::CompareItem, (DWORD_PTR)this);
	}

	*pResult = 0;
}

int CALLBACK CHeadCtrlDemoDlg::CompareItem(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CHeadCtrlDemoDlg* pDlg = (CHeadCtrlDemoDlg*)lParamSort;

	LVFINDINFO lvFind1, lvFind2;
	lvFind1.flags	= LVFI_PARAM;
	lvFind1.lParam	= lParam1;
	lvFind2.flags	= LVFI_PARAM;
	lvFind2.lParam	= lParam2;

	int nIndex1 = pDlg->m_List.FindItem(&lvFind1);
	int nIndex2 = pDlg->m_List.FindItem(&lvFind2);

	CString strText1 = pDlg->m_List.GetItemText(nIndex1, 0);
	CString strText2 = pDlg->m_List.GetItemText(nIndex2, 0);

	int nResult = 0;
	if(pDlg->m_bAscending)	nResult = strText2.Compare(strText1);
	else					nResult = strText1.Compare(strText2);

	return nResult;
}

void CHeadCtrlDemoDlg::UpdateArrow(void)
{
	CHeaderCtrl* pHeaderCtrl = m_List.GetHeaderCtrl();
	HDITEM hdItem;
	TCHAR szBuffer[256];
	::ZeroMemory(&hdItem, sizeof(hdItem));
	::ZeroMemory(szBuffer, 256);

	hdItem.mask = -1;
	hdItem.pszText = szBuffer;
	hdItem.cchTextMax = 256;
	pHeaderCtrl->GetItem(0, &hdItem);

	hdItem.fmt &= ~(HDF_SORTDOWN | HDF_SORTUP);

	if(m_bAscending)	hdItem.fmt |= HDF_SORTDOWN;
	else				hdItem.fmt |= HDF_SORTUP;
	pHeaderCtrl->SetItem(0, &hdItem);
}
