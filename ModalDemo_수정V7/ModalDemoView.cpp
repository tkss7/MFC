
// ModalDemoView.cpp: CModalDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ModalDemo.h"
#endif

#include "ModalDemoDoc.h"
#include "ModalDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDemoView

IMPLEMENT_DYNCREATE(CModalDemoView, CFormView)

BEGIN_MESSAGE_MAP(CModalDemoView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CModalDemoView::OnBnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON2, &CModalDemoView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CModalDemoView::OnBnClickedButton3)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CModalDemoView::OnLbnSelchangeList1)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CModalDemoView 생성/소멸

CModalDemoView::CModalDemoView() noexcept
	: CFormView(IDD_MODALDEMO_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CModalDemoView::~CModalDemoView()
{
}

void CModalDemoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Control(pDX, IDC_LISTCTRL, m_listCtrl);
}

BOOL CModalDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CModalDemoView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_imageListSmall.Create(16, 16, ILC_COLOR32, 1, 1);
	m_imageListSmall.Add(AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	m_listCtrl.SetImageList(&m_imageListSmall, LVSIL_SMALL);
	m_listCtrl.InsertColumn(0, _T("아이디"), LVCFMT_LEFT,  100);
	m_listCtrl.InsertColumn(1, _T("이름"), LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(2, _T("주소"), LVCFMT_LEFT, 200);
	m_listCtrl.InsertColumn(3, _T("나이"), LVCFMT_LEFT, 100);
	m_listCtrl.InsertColumn(4, _T("전화번호"), LVCFMT_LEFT, 100);

	DWORD dwExpendedStyle = m_listCtrl.GetExtendedStyle();
	m_listCtrl.SetExtendedStyle(dwExpendedStyle | LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	InsertMember(make_shared<CMember>(_T("12"), _T("홍길동"), _T("서울종로구"), _T("010"), _T("1234"), _T("5678"), 20));
	InsertMember(make_shared<CMember>(_T("13"), _T("홍길자"), _T("서울종로구"), _T("010"), _T("1235"), _T("5678"), 23));
	InsertMember(make_shared<CMember>(_T("14"), _T("이수신"), _T("서울종로구"), _T("010"), _T("1236"), _T("5678"), 25));
	InsertMember(make_shared<CMember>(_T("15"), _T("아중근"), _T("서울종로구"), _T("010"), _T("1237"), _T("5678"), 27));

}


// CModalDemoView 인쇄

BOOL CModalDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CModalDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CModalDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CModalDemoView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CModalDemoView 진단

#ifdef _DEBUG
void CModalDemoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CModalDemoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CModalDemoDoc* CModalDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDemoDoc)));
	return (CModalDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CModalDemoView 메시지 처리기

#include "CUserDlg.h"
#include "MemberMgrDlg.h"

void  CModalDemoView::OutputListCtrlMember(int nItem, CMemberPtr pMember)
{
	m_listCtrl.SetItemText(nItem, 1, pMember->m_strName);
	m_listCtrl.SetItemText(nItem, 2, pMember->m_strAddress);
	CString strAge;
	strAge.Format(_T("%d"), pMember->m_nAge);
	m_listCtrl.SetItemText(nItem, 3, strAge);
	CString strPhone;
	strPhone.Format(_T("%s-%s-%s"), pMember->m_strPhone1.GetBuffer(), pMember->m_strPhone2.GetBuffer(), pMember->m_strPhone3.GetBuffer());
	m_listCtrl.SetItemText(nItem, 4, strPhone);

}

void  CModalDemoView::InsertMember(CMemberPtr pMember)
{
	GetDocument()->InsertMember(pMember);

	int nItem = m_listCtrl.GetItemCount();
	m_listCtrl.InsertItem(nItem, pMember->m_strId, 0);
	OutputListCtrlMember(nItem, pMember);
}


void CModalDemoView::OnBnClickedButtonInsert()
{
	/*
	* 1. 고객관리를 위한 대화상자를 출력한다
	* 2. 관리자가 대화상자를 이용하여 입력한 값을 얻는다
	* 3. 입력한 값을 이용하여 CMember객체를 생성한다
	* 4. 생성된 CMember 객체를 Document에 추가한다
	*/

	CMemberMgrDlg dlg(GetDocument()->m_memberMgr);

	if (dlg.DoModal() == IDOK) {
		//2. 입력된 값을 이용하여 Member 객체를 생성한다
		InsertMember(dlg.GetMemberPtr());
	}
}

//cpp 클래스 -> 멤버 변수 
//객체화 될때 멤버 변수 확보가 됨 
//HWND -> CreateWindow() 
//CWnd은 HWND을 가지고 Window API를 사용할 수 있음 

void CModalDemoView::OnBnClickedButton2()
{
	//static CUserDlg dlg;

	//if (dlg.GetSafeHwnd() == NULL) {
	//	//윈도우 생성 
	//	dlg.Create(IDD_DIALOG1);
	//}
	//dlg.ShowWindow(SW_SHOW);
	CMemberMgrDlg dlg(GetDocument()->m_memberMgr);
//	CMemberMgrDlg dlg(nullptr);
	//1. 리스트 박스에서 선택된 위치를 얻는다
//	int nCurSel = m_listBox.GetCurSel();
	const int nSize = m_listCtrl.GetItemCount();
	if (nSize <= 0) return;

	CString strId;
	int nItem = -1;
	for (int i=0;i<nSize;++i) {
		if (m_listCtrl.GetCheck(i)) {
			strId = m_listCtrl.GetItemText(i, 0);
			nItem = i;
			break;
		}
	}
	//3. 위치에 해당하는 문자열을 얻는다
//	m_listBox.GetText(nCurSel, strId);

	CMemberPtr pMember = GetDocument()->GetMember(strId);
	if (pMember == nullptr) return;

	dlg.SetMemberPtr(pMember);

	if (dlg.DoModal() == IDOK) {
		*pMember = dlg.GetMemberPtr();

		OutputListCtrlMember(nItem, pMember);
	}
}


void CModalDemoView::OnBnClickedButton3()
{
	if (AfxMessageBox(_T("삭제하시겠습니까?"), MB_YESNO) != IDYES) {
		return;
	}

	/*
	1. 리스트 박스에서 선택된 위치를 얻는다
	2. 선택된 위치가 0보다 작으면 리턴
	3. 위치에 해당하는 문자열을 얻는다
	4. 문자열을 이용하여 Document에서 삭제한다 
	5. 선택된 위치를 이용하여 리스트 박스에서 삭제한다
	*/
	//1. 리스트 박스에서 선택된 위치를 얻는다
	//int nCurSel = m_listBox.GetCurSel();

	//2. 선택된 위치가 0보다 작으면 리턴
//	if (nCurSel < 0) return;

	//3. 위치에 해당하는 문자열을 얻는다
	CString strId;
	//m_listBox.GetText(nCurSel, strId);

	//4. 문자열을 이용하여 Document에서 삭제한다
	GetDocument()->DeleteMember(strId);

	//5. 선택된 위치를 이용하여 리스트 박스에서 삭제한다
	//m_listBox.DeleteString(nCurSel);

	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}


void CModalDemoView::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}


void CModalDemoView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CWnd* pButton = GetDlgItem(IDC_BUTTON_INSERT);
	if (pButton) {
		pButton->MoveWindow(cx - 120, 50, 100, 40);
	}
	pButton = GetDlgItem(IDC_BUTTON2);
	if (pButton) {
		pButton->MoveWindow(cx - 120, 100, 100, 40);
	}
	pButton = GetDlgItem(IDC_BUTTON3);
	if (pButton) {
		pButton->MoveWindow(cx - 120, 150, 100, 40);
	}
	if (m_listCtrl.GetSafeHwnd()) {
		m_listCtrl.MoveWindow(0, 0, cx - 130, cy);
	}
}
