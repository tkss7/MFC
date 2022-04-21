
// MemberMgrDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MemberMgrDlg.h"
#include "afxdialogex.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemberMgrDlg 대화 상자

CMemberMgrDlg::CMemberMgrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMBERMGR_DIALOG, pParent)
	, m_strID(_T(""))
	, m_strName(_T(""))
	, m_nPostCode(0)
	, m_strAddress(_T(""))
	, m_bMale(FALSE)
	, m_bFemale(FALSE)
	, m_strPhone1(_T(""))
	, m_strPhone2(_T(""))
	, m_strPhone3(_T(""))
	, m_nAge(0)
	, m_nHobby(0)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemberMgrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_POST_CODE, m_nPostCode);
	DDX_Text(pDX, IDC_EDIT_ADRESS, m_strAddress);
	DDX_Check(pDX, IDC_CHECK_MALE, m_bMale);
	DDX_Check(pDX, IDC_CHECK_FEMALE, m_bFemale);
	DDX_Text(pDX, IDC_EDIT_PHONE1, m_strPhone1);
	DDX_Text(pDX, IDC_EDIT_PHONE2, m_strPhone2);
	DDX_Text(pDX, IDC_EDIT_PHONE3, m_strPhone3);
	DDX_Text(pDX, IDC_EDIT_AGE, m_nAge);
	DDX_Radio(pDX, IDC_RADIO_HOBBY1, m_nHobby);

	DDX_Control(pDX, IDC_EDIT_ID, m_wndId);
}

BEGIN_MESSAGE_MAP(CMemberMgrDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_MALE, &CMemberMgrDlg::OnBnClickedCheckMale)
	//ON_BN_CLICKED(IDC_BUTTON_NEW, &CMemberMgrDlg::OnBnClickedButtonNew)
	//ON_BN_CLICKED(IDC_BTN_FIND, &CMemberMgrDlg::OnBnClickedBtnFind)
	//ON_BN_CLICKED(IDC_BTN_ADD, &CMemberMgrDlg::OnBnClickedBtnAdd)
	//ON_BN_CLICKED(IDC_BTN_UPDATE, &CMemberMgrDlg::OnBnClickedBtnUpdate)
	//ON_BN_CLICKED(IDC_BTN_DELETE, &CMemberMgrDlg::OnBnClickedBtnDelete)
	ON_BN_CLICKED(IDOK, &CMemberMgrDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMemberMgrDlg 메시지 처리기

BOOL CMemberMgrDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMemberMgrDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMemberMgrDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMemberMgrDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMemberMgrDlg::OnBnClickedCheckMale()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMemberMgrDlg::OnBnClickedButtonNew()
{
	m_strID = _T("");
	m_strName = _T("");
	m_nPostCode = 0;
	m_strAddress = _T("");
	m_bMale = FALSE;
	m_bFemale = FALSE;
	m_strPhone1 = _T("");
	m_strPhone2 = _T("");
	m_strPhone3 = _T("");
	m_nAge = 0;
	m_nHobby = 0;

	UpdateData(FALSE);

	m_wndId.EnableWindow(TRUE);
	m_wndId.SetFocus();

}

void CMemberMgrDlg::OnBnClickedBtnFind()
{
	/*
	1. 검색값을 입력받는다 
	2. 검색값의 존재여부 확인 
	3. 검색값으로 배열에서 찾는다 
	4. 찾은 자료가 존재하면 화면에 출력한다
	5. 찾은 자료가 존재하지 않은 경고 메시지 출력한다 
	*/

	//1. 검색값을 입력받는다
	if (!UpdateData()) return;

	//2. 검색값의 존재여부 확인
	if (m_strID.IsEmpty()) {
		AfxMessageBox(_T("찾고자 하는 아이디를 입력해주세요"));
		m_wndId.EnableWindow(TRUE);
		return;
	}

	//3. 검색값으로 배열에서 찾는다
	
	//for (const auto& pMember : m_array) {
	//	if (pMember->m_strId == m_strID) {
	//		
	//		m_strID	= pMember->m_strId;
	//		m_strName = pMember->m_strName;
	//		m_nPostCode = pMember->m_nPostCode;
	//		m_strAddress = pMember->m_strAddress;
	//		m_bMale = pMember->m_bSex ;
	//		m_bFemale = pMember->m_bSex == FALSE;
	//		m_strPhone1 = pMember->m_strPhone1;
	//		m_strPhone2 = pMember->m_strPhone2;
	//		m_strPhone3 = pMember->m_strPhone3;
	//		m_nAge = pMember->m_nAge;
	//		m_nHobby = pMember->m_nHobby;

	//		//4. 찾은 자료가 존재하면 화면에 출력한다
	//		UpdateData(FALSE);
	//		m_wndId.EnableWindow(FALSE);

	//		return;
	//	}
	//}

	AfxMessageBox(_T("찾고하는 아이디가 존재하지 않습니다"));

}


void CMemberMgrDlg::OnBnClickedBtnAdd()
{
	/*1. UI에 입력된 값을 변수로 읽는다.
	* 2. 입력된 값을 이용하여 Member 객체를 생성한다
	* 3. 어디가 저장될 공간(1. vector, 2. map, 3.db) 에 저장한다
	* 4. vector에 저장을 한다고 생각하고 어떤 객체를 저장할지?
	* 5. 저장 방법 : 1. 객체 vector<CMember>
	*				 2. 포인터 (동적객체) vector<CMember*>, 소멸자에서 객체 해제 반드시 할 것 
	                 3. 스마트 포인터 vector<CMemberPtr>
	*/

	//1. UI에 입력된 값을 변수로 읽는다.
	if (!UpdateData()) return;

	////2. 입력된 값을 이용하여 Member 객체를 생성한다
	//CMemberPtr pMember = make_shared<CMember>();
	//
	//pMember->m_strId = m_strID;
	//pMember->m_strName = m_strName;
	//pMember->m_nPostCode = m_nPostCode;
	//pMember->m_strAddress = m_strAddress;
	//pMember->m_bSex = m_bMale ? TRUE : FALSE;
	//pMember->m_strPhone1 = m_strPhone1;
	//pMember->m_strPhone2 = m_strPhone2;
	//pMember->m_strPhone3 = m_strPhone3;
	//pMember->m_nAge = m_nAge;
	//pMember->m_nHobby = m_nHobby;

	////3. 어디가 저장될 공간(1. vector, 2. map, 3.db) 에 저장한다
	//m_array.push_back(pMember);

	AfxMessageBox(_T("고객정보가 등록되었습니다"));

	OnBnClickedButtonNew();
}


void CMemberMgrDlg::OnBnClickedBtnUpdate()
{
	//1. UI에 입력된 값을 변수로 읽는다.
	if (!UpdateData()) return;

	//CString& strId = m_strID;
	//auto& it = find_if(m_array.begin(), m_array.end(),
	//	[strId](auto& pMember) -> int {return pMember->m_strId == strId; });
	//if (it != m_array.cend()) {
	//	CMemberPtr pMember = *it;

	//	pMember->m_strId = m_strID;
	//	pMember->m_strName = m_strName;
	//	pMember->m_nPostCode = m_nPostCode;
	//	pMember->m_strAddress = m_strAddress;
	//	pMember->m_bSex = m_bMale ? TRUE : FALSE;
	//	pMember->m_strPhone1 = m_strPhone1;
	//	pMember->m_strPhone2 = m_strPhone2;
	//	pMember->m_strPhone3 = m_strPhone3;
	//	pMember->m_nAge = m_nAge;
	//	pMember->m_nHobby = m_nHobby;

	//	AfxMessageBox(_T("수정되었습니다"));

	//}
	//else {
	//	AfxMessageBox(_T("찾고하는 아이디가 존재하지 않습니다"));
	//}
}

void CMemberMgrDlg::OnBnClickedBtnDelete()
{
	//const auto& it = find_if(m_array.cbegin(), m_array.cend(), [this](const auto& pMember) -> int {return pMember->m_strId == m_strID; });
	//if (it != m_array.end()) {
	//	m_array.erase(it);
	//}

	/*
	1. 검색값을 입력받는다
	2. 검색값의 존재여부 확인
	3. 검색값으로 배열에서 찾는다
	4. 찾은 자료가 존재하면 삭제한다
	5. 찾은 자료가 존재하지 않은 경고 메시지 출력한다
	*/

	//1. 검색값을 입력받는다
	if (!UpdateData()) return;

	//2. 검색값의 존재여부 확인
	if (m_strID.IsEmpty()) {
		AfxMessageBox(_T("찾고자 하는 아이디를 입력해주세요"));
		m_wndId.EnableWindow(TRUE);
		return;
	}

	//3. 검색값으로 배열에서 찾는다
	//for (auto& it = m_array.cbegin(); it != m_array.cend();it++) {
	//	//const auto& pMember = *it;
	//	if ((*it)->m_strId == m_strID) {
	//		//4. 찾은 자료가 존재하면 삭제한다 
	//		m_array.erase(it);

	//		OnBnClickedButtonNew();

	//		AfxMessageBox(_T("자료를 찾아서 삭제했습니다"));

	//		return;
	//	}
	//}
	//CString& strId = m_strID;
	//const auto& it = find_if(m_array.cbegin(), m_array.cend(), 
	//	[strId](const auto& pMember) -> int {return pMember->m_strId == strId; });
	//if (it != m_array.cend()) {
	//	OnBnClickedButtonNew();
	//	AfxMessageBox(_T("자료를 찾아서 삭제했습니다"));
	//	m_array.erase(it);
	//}
	//else {
	//	AfxMessageBox(_T("찾고하는 아이디가 존재하지 않습니다"));
	//}

	//람다 구문 
	//[켑쳐구문](인자부분) -> {return xxx};
	//auto func = [켑쳐구문](인자부분) -> {return xxx};

//	int result = add(10, 20);

	//
	//auto add_function = [](int a, int b) -> int {return a + b; };
	//result = add_function(10, 20);

	//CMember member(_T("1234"));
	//member.find(10, 20);
	//member.find(20, 30);



}


void CMemberMgrDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (UpdateData() == FALSE) {
		return;
	}

	//공백을 제거한다
	m_strID = m_strID.Trim();
	m_strName = m_strName.Trim();
	m_strAddress = m_strAddress.Trim();
	m_strPhone1 = m_strPhone1.Trim();
	m_strPhone2 = m_strPhone2.Trim();
	m_strPhone3 = m_strPhone3.Trim();

	//값입력 여부 확인
	if (IsEmpty(m_strID, _T("아이디를 입력해주세요"), IDC_EDIT_ID)) return;
	if (IsEmpty(m_strName, _T("이름을 입력해주세요"), IDC_EDIT_NAME)) return;
	if (IsEmpty(m_strAddress, _T("주소를 입력해주세요"), IDC_EDIT_ADRESS)) return;
	if (IsEmpty(m_strPhone1, _T("전화번호를 입력해주세요"), IDC_EDIT_PHONE1)) return;
	if (IsEmpty(m_strPhone2, _T("전화번호를 입력해주세요"), IDC_EDIT_PHONE2)) return;
	if (IsEmpty(m_strPhone3, _T("전화번호를 입력해주세요"), IDC_EDIT_PHONE3)) return;

	CDialogEx::OnOK();
}

bool CMemberMgrDlg::IsEmpty(const CString& strText, LPCTSTR lpszMsg, UINT id) const {
	if (strText.GetLength() == 0) {
		AfxMessageBox(lpszMsg);
		GetDlgItem(id)->SetFocus();
		return true;
	}
	return false;
}

