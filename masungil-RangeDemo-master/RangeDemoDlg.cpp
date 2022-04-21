﻿
// RangeDemoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "RangeDemo.h"
#include "RangeDemoDlg.h"
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


// CRangeDemoDlg 대화 상자



CRangeDemoDlg::CRangeDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RANGEDEMO_DIALOG, pParent)
	, m_nPos(0)
	, m_nEditPos(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRangeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progressCtrl);
	DDX_Control(pDX, IDC_BUTTON1, m_wndInc);
	DDX_Control(pDX, IDC_BUTTON2, m_wndDec);
	DDX_Slider(pDX, IDC_SLIDER1, m_nPos);
	DDX_Control(pDX, IDC_SLIDER1, m_sliderCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_nEditPos);
	DDX_Control(pDX, IDC_SPIN1, m_wndSpin);
}

BEGIN_MESSAGE_MAP(CRangeDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRangeDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRangeDemoDlg::OnBnClickedButton2)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CRangeDemoDlg::OnTRBNThumbPosChangingSlider1)
	ON_EN_CHANGE(IDC_EDIT1, &CRangeDemoDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CRangeDemoDlg 메시지 처리기

BOOL CRangeDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog(); //UpdateData(FALSE);//

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
	m_progressCtrl.SetRange(0, 100);
	m_progressCtrl.SetPos(50);

	m_sliderCtrl.SetRange(0, 100);
	m_sliderCtrl.SetPos(0);
	m_sliderCtrl.SetTicFreq(2);

	m_wndSpin.SetRange(0, 100);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CRangeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRangeDemoDlg::OnPaint()
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
HCURSOR CRangeDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRangeDemoDlg::OnBnClickedButton1()
{
	int nPos = m_progressCtrl.GetPos();
	m_progressCtrl.SetPos(nPos + 10);
	if (nPos == 90) {
		m_wndInc.EnableWindow(FALSE);
	}
	else {
		m_wndInc.EnableWindow(TRUE);
	}
	m_wndDec.EnableWindow(TRUE);
}


void CRangeDemoDlg::OnBnClickedButton2()
{
	int nPos = m_progressCtrl.GetPos();
	m_progressCtrl.SetPos(0);
	m_progressCtrl.SetPos(nPos - 10);
	if (nPos == 10) {
		m_wndDec.EnableWindow(FALSE);
	}
	else {
		m_wndDec.EnableWindow(TRUE);
	}
	m_wndInc.EnableWindow(TRUE);
}

//class A{
//public:
//	int a;
//	virtual void func() {}  //__vfptr
//};
//
//class B {
//public:
//	int a;
//	virtual void func() {}  //__vfptr
//};
//
//A* p = new A;
//B* q = reinterpret_cast<B*>(p);
//q->func();

void CRangeDemoDlg::OnTRBNThumbPosChangingSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// 이 기능을 사용하려면 Windows Vista 이상이 있어야 합니다.
	// _WIN32_WINNT 기호는 0x0600보다 크거나 같아야 합니다.
	NMTRBTHUMBPOSCHANGING* pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING*>(pNMHDR);
	//OLE2, COM 
	//NMTRBTHUMBPOSCHANGING data;

	//&data -> void*,  NMHDR*, NMTRBTHUMBPOSCHANGING*

//	int a = 10;
//	int b = 10;
//	int c = 10;
//	int* p = &a;
//	//a type -> int, & a -> 0xff12;, & b -> 0xff16; & a -> 0xff1a;
//
//	//p의 type  -> int*, void*;
//	//p에 저장되는 값 -> 0xff12
//	//0xff12 -> 주소, 이해 
//	p = (int*)0xff16;
//	*p = 20;
//
//class A { public: int a; };
//	class B : public A { public: int b; };
//	B objB;
//	A* p = new A;
//	B* pObjB = (B*)p;
//	B* pObjB = dynamic_cast<B*>(p);
//	reinterpret_cast
//	pObjB->b = 10;

	UpdateData();

	//m_nEditPos = m_nPos;// m_sliderCtrl.GetPos();
	m_nEditPos = pNMTPC->dwPos;
	m_progressCtrl.SetPos(m_nEditPos);

	UpdateData(FALSE);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CRangeDemoDlg::OnEnChangeEdit1()
{
	//GetDlgItemInt()/GetDlgItemText() //변경된 요소 대상으로 값을 읽을 때 사용하는 것 
	if (m_progressCtrl.GetSafeHwnd() == NULL ||
		m_wndInc.GetSafeHwnd() == NULL ||
		m_wndDec.GetSafeHwnd() == NULL || 
		m_sliderCtrl.GetSafeHwnd() == NULL || 
		m_wndSpin.GetSafeHwnd() == NULL) return;

	if (UpdateData() == FALSE) {
		return;
	}

	m_progressCtrl.SetPos(m_nEditPos);

}
