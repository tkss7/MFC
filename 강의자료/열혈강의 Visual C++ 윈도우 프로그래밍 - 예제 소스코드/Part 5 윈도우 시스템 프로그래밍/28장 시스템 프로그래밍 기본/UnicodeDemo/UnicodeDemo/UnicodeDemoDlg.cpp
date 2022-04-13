
// UnicodeDemoDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "UnicodeDemo.h"
#include "UnicodeDemoDlg.h"

#include <lm.h>
#pragma comment(lib, "NetApi32")

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


// CUnicodeDemoDlg 대화 상자




CUnicodeDemoDlg::CUnicodeDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUnicodeDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUnicodeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUnicodeDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_Button_Message, &CUnicodeDemoDlg::OnBnClickedButtonMessage)
	ON_BN_CLICKED(IDC_Button_Length, &CUnicodeDemoDlg::OnBnClickedButtonLength)
	ON_BN_CLICKED(IDC_Button_CString, &CUnicodeDemoDlg::OnBnClickedButtonCstring)
	ON_BN_CLICKED(IDC_Button_UniToMBCS, &CUnicodeDemoDlg::OnBnClickedButtonUnitombcs)
	ON_BN_CLICKED(IDC_Button_MBCSToUnicode, &CUnicodeDemoDlg::OnBnClickedButtonMbcstounicode)
	ON_BN_CLICKED(IDC_Button_NetUserGetInfo, &CUnicodeDemoDlg::OnBnClickedButtonNetusergetinfo)
END_MESSAGE_MAP()


// CUnicodeDemoDlg 메시지 처리기

BOOL CUnicodeDemoDlg::OnInitDialog()
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

void CUnicodeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUnicodeDemoDlg::OnPaint()
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
HCURSOR CUnicodeDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CUnicodeDemoDlg::OnBnClickedButtonMessage()
{
/*	WCHAR wszBuffer[128];
	wsprintf(wszBuffer, L"%s (Length %d, Size %d)",
										L"Test string!",
										lstrlen(L"Test string!"),
										sizeof(wszBuffer));
	AfxMessageBox(wszBuffer);
*/
}

void CUnicodeDemoDlg::OnBnClickedButtonLength()
{
	char szBuffer[128];
	sprintf_s(szBuffer, 128, "%s (Length %d, Size %d)",
										"Test string!",
										lstrlenA("Test string!"),
										sizeof(szBuffer));
	::MessageBoxA(m_hWnd, szBuffer, "Test", MB_OK);
}

void CUnicodeDemoDlg::OnBnClickedButtonCstring()
{
	CString strTmp = _T(""), strTest = _T("Test string!");
	strTmp.Format(_T("%s (Length %d)"), strTest, strTest.GetLength());
	AfxMessageBox(strTmp);
}

void CUnicodeDemoDlg::OnBnClickedButtonUnitombcs()
{
	WCHAR wszBuffer[128];
	char szDstBuffer[128];
	wsprintf(wszBuffer, _T("%s"), _T("Test String!"));
	::ZeroMemory(szDstBuffer, sizeof(szDstBuffer));

	::WideCharToMultiByte(CP_ACP, 0, wszBuffer, -1, szDstBuffer, 128, NULL, NULL);
	::MessageBoxA(m_hWnd, szDstBuffer, "Test", MB_OK);
}

void CUnicodeDemoDlg::OnBnClickedButtonMbcstounicode()
{
	WCHAR wszBuffer[128];
	char szSrcBuffer[128];
	sprintf_s(szSrcBuffer, 128, "%s", "Test String!");
	::ZeroMemory(wszBuffer, sizeof(wszBuffer));

	::MultiByteToWideChar(CP_ACP, 0, szSrcBuffer, lstrlenA(szSrcBuffer) + 1,
						wszBuffer, sizeof(wszBuffer)/sizeof(wszBuffer[0]) );

	AfxMessageBox(wszBuffer);
}

void CUnicodeDemoDlg::OnBnClickedButtonNetusergetinfo()
{
	CString strTmp = _T("");
	USER_INFO_2* pUserInfo = NULL;
	if(::NetUserGetInfo(NULL, L"Tester", 2, (LPBYTE*)&pUserInfo) == NERR_Success)
	{
		strTmp.Format(_T("%s (%s)"), pUserInfo->usri2_full_name,
									 pUserInfo->usri2_comment);
		AfxMessageBox(strTmp);
		::NetApiBufferFree(pUserInfo);
	}
}
