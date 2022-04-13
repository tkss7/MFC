
// OleDBDemoView.cpp : COleDBDemoView 클래스의 구현
//

#include "stdafx.h"
#include "OleDBDemo.h"

#include "OleDBDemoSet.h"
#include "OleDBDemoDoc.h"
#include "OleDBDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COleDBDemoView

IMPLEMENT_DYNCREATE(COleDBDemoView, COleDBRecordView)

BEGIN_MESSAGE_MAP(COleDBDemoView, COleDBRecordView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &COleDBRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COleDBDemoView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_Button_AddNew, &COleDBDemoView::OnBnClickedButtonAddnew)
	ON_BN_CLICKED(IDC_Button_ModifyRecord, &COleDBDemoView::OnBnClickedButtonModifyrecord)
	ON_BN_CLICKED(IDC_Button_DeleteRecord, &COleDBDemoView::OnBnClickedButtonDeleterecord)
END_MESSAGE_MAP()

// COleDBDemoView 생성/소멸

COleDBDemoView::COleDBDemoView()
	: COleDBRecordView(COleDBDemoView::IDD)
{
	m_pSet = NULL;
	// TODO: 여기에 생성 코드를 추가합니다.

}

COleDBDemoView::~COleDBDemoView()
{
}

void COleDBDemoView::DoDataExchange(CDataExchange* pDX)
{
	COleDBRecordView::DoDataExchange(pDX);
	// SetDlgItem*/GetDlgItem* API 호출뿐 아니라 DDX_* 함수를 삽입하여 데이터베이스를 뷰에 연결할 수 있습니다.
	// ex. ::SetDlgItemText(m_hWnd, IDC_MYCONTROL, m_pSet->m_MyColumn);
	// 자세한 내용은 MSDN 및 OLEDB 샘플을 참조하십시오.
	DDX_Control(pDX, IDC_List, m_List);
}

BOOL COleDBDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return COleDBRecordView::PreCreateWindow(cs);
}

void COleDBDemoView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_OleDBDemoSet;
	{
		CWaitCursor wait;
		HRESULT hr = m_pSet->OpenAll();
		if (FAILED(hr))
		{
			// 레코드 집합을 열지 못했습니다. 레코드 집합이 저장
			// 프로시저인 경우 OpenAll()을 호출하기 전에 
			// 입력 매개 변수를 제대로 초기화했는지
			// 확인하십시오.

			AfxMessageBox(_T("레코드 집합을 열지 못했습니다."), MB_OK);
			// 열린 RowSet 없이 현재 레코드의 변경을 시도하면
			// 충돌할 수 있기 때문에 다음 및 이전 레코드 명령을
			// 비활성화합니다.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
		if( hr == DB_S_ENDOFROWSET )
		{
			// 행 집합이 비어 있습니다(행이 포함되어 있지 않음).
			AfxMessageBox(_T("레코드 집합이 열렸지만 반환할 행이 없었습니다."), MB_OK);
			// 다음 및 이전 레코드 명령을 비활성화합니다.
			m_bOnFirstRecord = TRUE;
			m_bOnLastRecord = TRUE;
		}
	}
	COleDBRecordView::OnInitialUpdate();

	m_pSet->RunSQL(_T("SELECT * FROM UserData WHERE Age >= 40"));

	if(m_List.GetHeaderCtrl()->GetItemCount() <= 0)
	{
		m_List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 100);
		m_List.InsertColumn(1, _T("Phone number"), LVCFMT_LEFT, 150);
		m_List.InsertColumn(2, _T("Address"), LVCFMT_LEFT, 200);
		m_List.InsertColumn(3, _T("Age"), LVCFMT_LEFT, 50);
	}

	ListupAllRecords();
}


// COleDBDemoView 인쇄


void COleDBDemoView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL COleDBDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void COleDBDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void COleDBDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void COleDBDemoView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COleDBDemoView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// COleDBDemoView 진단

#ifdef _DEBUG
void COleDBDemoView::AssertValid() const
{
	COleDBRecordView::AssertValid();
}

void COleDBDemoView::Dump(CDumpContext& dc) const
{
	COleDBRecordView::Dump(dc);
}

COleDBDemoDoc* COleDBDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COleDBDemoDoc)));
	return (COleDBDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// COleDBDemoView 데이터베이스 지원
CRowset<>* COleDBDemoView::OnGetRowset()
{
	return m_pSet->GetRowsetBase();
}



// COleDBDemoView 메시지 처리기

void COleDBDemoView::ListupAllRecords(void)
{
	CString strTmp = _T("");
	m_pSet->MoveFirst();
	do
	{
		m_List.InsertItem(0, m_pSet->m_Name, 0);
		m_List.SetItemText(0, 1, m_pSet->m_PhoneNumber);
		m_List.SetItemText(0, 2, m_pSet->m_Address);

		strTmp.Format(_T("%ld"), m_pSet->m_Age);
		m_List.SetItemText(0, 3, strTmp);
	}
	while(m_pSet->MoveNext() != DB_S_ENDOFROWSET);

	m_pSet->MoveFirst();
}

void COleDBDemoView::OnBnClickedButtonAddnew()
{
	CCommand<CDynamicAccessor> Cmd;
 
	CDBPropSet   propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, 
							DBPROPVAL_UP_CHANGE | 
							DBPROPVAL_UP_INSERT | 
							DBPROPVAL_UP_DELETE);
 
	HRESULT hr = Cmd.Open(m_pSet->m_session, _T("SELECT * FROM UserData"), &propset);
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to execute SQL!"));
	}

	TCHAR* pszValue = NULL;
	Cmd.SetStatus(1, DBSTATUS_S_IGNORE); 

	pszValue = (TCHAR*)Cmd.GetValue(2);
	wsprintf(pszValue, _T("%s"), _T("김철수"));
	Cmd.SetLength(2, lstrlen(pszValue) * 2);
	Cmd.SetStatus(2, DBSTATUS_S_OK);

	pszValue = (TCHAR*)Cmd.GetValue(3);
	wsprintf(pszValue, _T("%s"), _T("02-5555-5555"));
	Cmd.SetLength(3, lstrlen(pszValue) * 2);
	Cmd.SetStatus(3, DBSTATUS_S_OK);

	pszValue = (TCHAR*)Cmd.GetValue(4);
	wsprintf(pszValue, _T("%s"), _T("부천시 원미구 상동"));
	Cmd.SetLength(4, lstrlen(pszValue) * 2);
	Cmd.SetStatus(4, DBSTATUS_S_OK);

	ULONG* plAge = (ULONG*)Cmd.GetValue(5);
	*plAge = 100;
	Cmd.SetLength(5, sizeof(ULONG));
	Cmd.SetStatus(5, DBSTATUS_S_OK);

	hr = Cmd.Insert();
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to Insert new record!"));
	}

	Cmd.Close();
	Cmd.ReleaseCommand();

	if(m_List.GetItemCount() > 0)		m_List.DeleteAllItems();
	m_pSet->RunSQL(_T("SELECT * FROM UserData"));
	ListupAllRecords();
}
void COleDBDemoView::OnBnClickedButtonModifyrecord()
{
	CCommand<CDynamicAccessor> Cmd;
 
	CDBPropSet   propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, 
							DBPROPVAL_UP_CHANGE | 
							DBPROPVAL_UP_INSERT | 
							DBPROPVAL_UP_DELETE);
 
	HRESULT hr = Cmd.Open(m_pSet->m_session,
						_T("SELECT * FROM UserData WHERE Name = '김철수'"),
						&propset);
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to execute SQL!"));
	}

	Cmd.MoveFirst();
	TCHAR* pszValue = NULL;
	Cmd.SetStatus(1, DBSTATUS_S_IGNORE); 

	ULONG* plAge = (ULONG*)Cmd.GetValue(5);
	*plAge = 30;
	Cmd.SetLength(5, sizeof(ULONG));
	Cmd.SetStatus(5, DBSTATUS_S_OK);

	hr = Cmd.SetData();
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to modify record!"));
	}

	Cmd.Update();
	Cmd.Close();
	Cmd.ReleaseCommand();

	if(m_List.GetItemCount() > 0)		m_List.DeleteAllItems();
	m_pSet->RunSQL(_T("SELECT * FROM UserData"));
	ListupAllRecords();
}
void COleDBDemoView::OnBnClickedButtonDeleterecord()
{
	CCommand<CDynamicAccessor> Cmd;
 
	CDBPropSet   propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_IRowsetChange, true);
	propset.AddProperty(DBPROP_UPDATABILITY, 
							DBPROPVAL_UP_CHANGE | 
							DBPROPVAL_UP_INSERT | 
							DBPROPVAL_UP_DELETE);
 
	HRESULT hr = Cmd.Open(m_pSet->m_session,
						_T("SELECT * FROM UserData WHERE Name = '김철수'"),
						&propset);
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to execute SQL!"));
	}

	Cmd.MoveFirst();
	hr = Cmd.Delete();
	if(FAILED(hr))
	{
		AfxMessageBox(_T("ERROR: Failed to delete record!"));
	}

	Cmd.Update();
	Cmd.Close();
	Cmd.ReleaseCommand();

	if(m_List.GetItemCount() > 0)		m_List.DeleteAllItems();
	m_pSet->RunSQL(_T("SELECT * FROM UserData"));
	ListupAllRecords();
}
