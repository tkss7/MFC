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
	Controller (����)
Document : Data ������ ���� (������, ����, ����)
View : ȭ�� ���
*/

class CMyDoc : public CDocument {
public:
	DECLARE_DYNCREATE(CMyDoc);
	//������ ��� ���� �Լ� 
	virtual BOOL OnNewDocument() override {
		return TRUE;
	}
	//���Ͽ� �б�/���⸦ ����ϴ� �Լ� 
	virtual void Serialize(CArchive& ar) override {

	}
};

class CMyView : public CView {
public:
	DECLARE_DYNCREATE(CMyView);
	//ȭ�� ��¿� ���� �Լ�
	virtual void OnDraw(CDC* pDC) override {

	}
};

//��ü ������ ���õ� �Լ� ���� 
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
		//Doc/View ����
		//Document/View ����
		//���� ���� 
		//���� ����
		CSingleDocTemplate* pDocTemplate;
		pDocTemplate = new CSingleDocTemplate(IDR_MAIN_FRAME2,
			RUNTIME_CLASS(CMyDoc), //CRuntimeClass
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CMyView)
		);
		if (pDocTemplate == nullptr) {
			return FALSE;
		}
		//Doc/View���� ��ü�� ��� �Ѵ�
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