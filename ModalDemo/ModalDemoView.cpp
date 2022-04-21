
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
	ON_BN_CLICKED(IDC_BUTTON_REVISE, &CModalDemoView::OnBnClickedButtonRevise)
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

#include"CUserDlg.h"
#include"MemberMgrDlg.h"
void CModalDemoView::OnBnClickedButtonInsert()
{

	//1. 고객관리를 위한 대화상자를 출력한다.
	//2. 관리자가 대화상자를 이용하여 입력한 값을 얻는다.
	//3. 입력한 값을 이용하여 CMember객체를 생성한다.
	//4. 생성된 CMember 객체를 Doc에 추가한다.





	CMemberMgrDlg dlg; //여기서도 그냥 윈도우 없는 객체

	//dlg.DoModal() : 이걸 호출하면 자동적으로 대화상자를 만든다

	if (dlg.DoModal() == IDOK) { // ok 버튼을 눌렀다면 실행 , IDOK 를 하면 자동으로  UpdateData()가 호출이 됨 -> 굳이 안써도 된다.
			//2. 입력된 값을 이용하여 Member 객체를 생성한다
	CMemberPtr pMember = make_shared<CMember>();
	
	pMember->m_strId = m_strID;
	pMember->m_strName = m_strName;
	pMember->m_nPostCode = m_nPostCode;
	pMember->m_strAddress = m_strAddress;
	pMember->m_bSex = m_bMale ? TRUE : FALSE;
	pMember->m_strPhone1 = m_strPhone1;
	pMember->m_strPhone2 = m_strPhone2;
	pMember->m_strPhone3 = m_strPhone3;
	pMember->m_nAge = m_nAge;
	pMember->m_nHobby = m_nHobby;

	//3. 어디가 저장될 공간(1. vector, 2. map, 3.db) 에 저장한다
	m_array.push_back(pMember);

	}
}

//cpp 클래스 -> 멤버변수
//객체화 될 때 멤버 변수 확보가 됨
//HWND : 윈도우 핸들 CreateWindow()가 호출이 되면 만들어짐 (API)
//CWnd : HWND을 가지고 Window API를 호출 할 수 있다.

void CModalDemoView::OnBnClickedButtonRevise()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static CUserDlg dlg; //윈도우가 없는 빈 껍데기 상태의 객체

	if (dlg.GetSafeHwnd() == NULL)
	{
		//윈도우 생성
		//dlg.Create(CUserDlg::IDD) // IDD = 
		
			dlg.Create(IDD_DIALOG1);
		
/*
#ifdef AFX_DESIGN_TIME <== 이렇게 헤더파일에 선언되어 있음
			enum { IDD = IDD_DIALOG1 };
#endif
*/
	}
	dlg.ShowWindow(SW_SHOW);
}
