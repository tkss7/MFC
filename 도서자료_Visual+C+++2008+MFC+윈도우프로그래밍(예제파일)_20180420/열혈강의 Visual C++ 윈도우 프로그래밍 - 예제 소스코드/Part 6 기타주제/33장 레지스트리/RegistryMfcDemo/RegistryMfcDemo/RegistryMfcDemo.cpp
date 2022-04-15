
// RegistryMfcDemo.cpp : 응용 프로그램에 대한 클래스 동작을 정의합니다.
//

#include "stdafx.h"
#include "RegistryMfcDemo.h"
#include "RegistryMfcDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRegistryMfcDemoApp

BEGIN_MESSAGE_MAP(CRegistryMfcDemoApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CRegistryMfcDemoApp 생성

CRegistryMfcDemoApp::CRegistryMfcDemoApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CRegistryMfcDemoApp 개체입니다.

CRegistryMfcDemoApp theApp;


// CRegistryMfcDemoApp 초기화

BOOL CRegistryMfcDemoApp::InitInstance()
{
	// 응용 프로그램 매니페스트가 ComCtl32.dll 버전 6 이상을 사용하여 비주얼 스타일을
	// 사용하도록 지정하는 경우, Windows XP 상에서 반드시 InitCommonControlsEx()가 필요합니다.
	// InitCommonControlsEx()를 사용하지 않으면 창을 만들 수 없습니다.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 응용 프로그램에서 사용할 모든 공용 컨트롤 클래스를 포함하도록
	// 이 항목을 설정하십시오.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();
	AfxEnableControlContainer();

	SetRegistryKey(_T("프리렉"));

	CRegistryMfcDemoDlg dlg;
	m_pMainWnd = &dlg;

	UINT uRead = 0;
	BYTE* pData = NULL;
	dlg.m_strLastDate = GetProfileString(_T(""), _T("LastDate"), _T("정보 없음"));
	dlg.m_strName = GetProfileString(_T("User"), _T("Name"), _T("Unknown"));
	dlg.m_dwNumber = GetProfileInt(_T("User"), _T("Number"), 0);
	
	if(GetProfileBinary(_T(""), _T("TestData"), &pData, &uRead))
	{
		TEST_DATA* pTestData = (TEST_DATA*)pData;
		delete[] pData;
	}

	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 여기에 [확인]을 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 여기에 [취소]를 클릭하여 대화 상자가 없어질 때 처리할
		//  코드를 배치합니다.
	}

	CTime t = CTime::GetCurrentTime();
	CString strDate = t.Format(_T("%A, %B %d, %Y"));

	WriteProfileString(_T(""), _T("LastDate"), strDate);
	WriteProfileString(_T("User"), _T("Name"), dlg.m_strName);
	WriteProfileInt(_T("User"), _T("Number"), dlg.m_dwNumber);

	TEST_DATA TestData;
	::ZeroMemory(&TestData, sizeof(TestData));
	TestData.nType	= 10;
	TestData.dwData	= 15;
	wsprintf(TestData.szData, _T("%s"), _T("TEST DATA STRING"));
	WriteProfileBinary(_T(""), _T("TestData"), (BYTE*)&TestData, sizeof(TestData));

	return FALSE;
}
