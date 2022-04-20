
// ComboExDemoDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ComboExDemo.h"
#include "ComboExDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CComboExDemoDlg ��ȭ ����




CComboExDemoDlg::CComboExDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboExDemoDlg::IDD, pParent)
	, m_strInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboExDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_ComboEx);
	DDX_Text(pDX, IDC_EDIT1, m_strInput);
	DDX_Control(pDX, IDC_COMBOBOXEX3, m_comboBoxEx);
}

BEGIN_MESSAGE_MAP(CComboExDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CComboExDemoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CComboExDemoDlg �޽��� ó����

BOOL CComboExDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ���� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� 
	// �ƴ� ��쿡�� �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	//1. �̹��� ����Ʈ ����
	CBitmap Bmp;
	Bmp.LoadBitmap(IDB_Imagelist);

	m_ImgList.Create(16, 16, ILC_COLOR24, 7, 7);
	m_ImgList.Add(&Bmp, RGB(255, 0, 0));
	m_ComboEx.SetImageList(&m_ImgList);
	m_comboBoxEx.SetImageList(&m_ImgList);

	//m_comboBox.AddString("aaa");

	//2. ������ �߰�
	CString strTmp = _T("");
	COMBOBOXEXITEM cbi = { 0 };
//	::ZeroMemory(&cbi, sizeof(cbi));

	cbi.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
	for(int i = 0; i < 7; ++i)
	{
		strTmp.Format(_T("%dth abcdefghijklmnopqrstuvwxyz0123456789abcdefghijklmnopqrstuvwxyz0123456789abcdefghijklmnopqrstuvwxyz0123456789abcdefghijklmnopqrstuvwxyz0123456789"), i);

		cbi.iItem			= i;
		cbi.iImage			= i;
		cbi.iSelectedImage	= i;

		cbi.pszText			= strTmp.GetBuffer();

		m_ComboEx.InsertItem(&cbi);
		m_comboBoxEx.InsertItem(&cbi);
	}

	m_ComboEx.SetCurSel(0);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CComboExDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CComboExDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CComboExDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CComboExDemoDlg::OnBnClickedButton1()
{
	if (UpdateData() == FALSE) {
		return;
	}

	COMBOBOXEXITEM cbi = { 0 };
	const int count = m_ComboEx.GetCount();
	TCHAR szText[12];
	cbi.mask = CBEIF_TEXT | CBEIF_IMAGE | CBEIF_SELECTEDIMAGE;
	cbi.pszText = szText;
	cbi.cchTextMax = 11;

	for (int i=0;i<count;i++) {
		cbi.iItem = i;
		m_ComboEx.GetItem(&cbi);
		
		cbi.iImage;
		cbi.pszText;
		cbi.iSelectedImage;

		AfxMessageBox(szText);
		//m_ComboEx.GetLBText(index, CString);
		//m_listEx.GetText(index, CString);
//		if (m_strInput == szText) {
//			m_ComboEx.SetCurSel(i);
//			break;
//		}
	}
}