
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
	ON_LBN_SELCHANGE(IDC_LIST1, &CModalDemoView::OnLbnSelchangeList1)
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
	DDX_Control(pDX, IDC_LIST1, m_listBox);
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

void CModalDemoView::OnBnClickedButtonInsert()
{
	/*
	* 1. 고객관리를 위한 대화상자를 출력한다
	* 2. 관리자가 대화상자를 이용하여 입력한 값을 얻는다
	* 3. 입력한 값을 이용하여 CMember객체를 생성한다
	* 4. 생성된 CMember 객체를 Document에 추가한다
	*/

	CMemberMgrDlg dlg;
	
	if (dlg.DoModal() == IDOK) {
		//2. 입력된 값을 이용하여 Member 객체를 생성한다
//		CMemberPtr pMember = dlg.GetMemberPtr();

		//CModalDemoDoc* pDoc = GetDocument();
		//pDoc->m_memberMgr.InsertMember(dlg.GetMemberPtr());
		CMemberPtr pMember = dlg.GetMemberPtr();
		GetDocument()->InsertMember(pMember);

		m_listBox.AddString(pMember->m_strId.GetBuffer());
	}
}

//cpp 클래스 -> 멤버 변수 
//객체화 될때 멤버 변수 확보가 됨 
//HWND -> CreateWindow() 
//CWnd은 HWND을 가지고 Window API를 사용할 수 있음 

void CModalDemoView::OnBnClickedButton2()
{
	static CUserDlg dlg;

	if (dlg.GetSafeHwnd() == NULL) {
		//윈도우 생성 
		dlg.Create(IDD_DIALOG1);
	}
	dlg.ShowWindow(SW_SHOW);

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
	int nCurSel = m_listBox.GetCurSel();

	//2. 선택된 위치가 0보다 작으면 리턴
	if (nCurSel < 0) return;

	//3. 위치에 해당하는 문자열을 얻는다
	CString strId;
	m_listBox.GetText(nCurSel, strId);

	//4. 문자열을 이용하여 Document에서 삭제한다
	GetDocument()->DeleteMember(strId);

	//5. 선택된 위치를 이용하여 리스트 박스에서 삭제한다
	m_listBox.DeleteString(nCurSel);

	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
}


void CModalDemoView::OnLbnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}
