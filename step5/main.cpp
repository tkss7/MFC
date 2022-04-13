#include <afxwin.h>
#include "resource.h"

class CMainFrame : public CFrameWnd {
public:
	DECLARE_DYNCREATE(CMainFrame);
};

/*
Document/View
MVC
	Model (Document)
	View
	Controller (제어)
Document : Data 관리가 목적 (새문서, 열기, 저장)
View : 화면 출력
*/

class CMyDoc : public CDocument {
public:
	DECLARE_DYNCREATE(CMyDoc);
	//새문서 기능 구현 함수 
	virtual BOOL OnNewDocument() override {
		return TRUE;
	}
	//파일에 읽기/쓰기를 담당하는 함수 
	virtual void Serialize(CArchive& ar) override {

	}
};

class CMyView : public CView {
public:
	DECLARE_DYNCREATE(CMyView);
	//화면 출력에 대한 함수
	virtual void OnDraw(CDC* pDC) override {

	}
};

//객체 생성에 관련된 함수 구현 
IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd);
IMPLEMENT_DYNCREATE(CMyDoc, CDocument);
IMPLEMENT_DYNCREATE(CMyView, CView);

class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {
		//CMainFrame* pMainFrame = new CMainFrame();
		//pMainFrame->LoadFrame(IDR_MAIN_FRAME);
		//pMainFrame->ShowWindow(SW_SHOW);
		//m_pMainWnd = pMainFrame;
		//Doc/View 구조
		//Document/View 구조
		//단일 문서 
		//다중 문서
		CSingleDocTemplate* pDocTemplate;
		pDocTemplate = new CSingleDocTemplate(IDR_MAIN_FRAME2,
			RUNTIME_CLASS(CMyDoc), //CRuntimeClass
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
	int ExitInstance() {
		return 0;
	}
};

CMyApp theApp;