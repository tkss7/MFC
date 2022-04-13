#include"pch.h"
#include"myApp.h"
#include"mainFrame.h"
#include"myDoc.h"
#include"myView.h"
#include"resource.h"

BOOL CMyApp::InitInstance() {

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(IDR_MAIN_FRAME2,
		RUNTIME_CLASS(CMyDoc), //CRuntimeClass == C++ 의 new
		RUNTIME_CLASS(CMainFrame),
		RUNTIME_CLASS(CMyView)
	);
	if (pDocTemplate == nullptr) {
		return FALSE;
	}
	//Doc/View구조 객체를 등록 한다
	AddDocTemplate(pDocTemplate);

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	if (!ProcessShellCommand(cmdInfo)) {
		return FALSE;
	}

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}
int CMyApp:: ExitInstance() {
	return 0;
}

CMyApp theApp;
