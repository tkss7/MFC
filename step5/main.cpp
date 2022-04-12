#include<afxwin.h>
#include"resource.h"
//RTTI
//factory design pattern

/*
	Document/View
	MVC
		Model (Document)
		View
		Controller (����) : �� �ΰ��� ����

	Document : Data ������ ���� (������ , ����, ����)
	View : ȭ�� ���
*/
class CMyDoc : public CDocument {
public:

	DECLARE_DYNCREATE(CMyDoc);

	virtual BOOL OnNewDocument() override { // ������ ��� ���� �Լ�

	}

	virtual void Serialize(CArchive& ar) override { //������ �б� ���⸦ ���

	}
};

class CMyView : public CView {
public:
	DECLARE_DYNCREATE(CMyView);

	virtual void OnDraw(CDC* pDC) override { //ȭ�� ��¿� ���� �Լ�

	}
};

class CMainFrame :public CFrameWnd {
public:
	DECLARE_DYNCREATE(CMainFrame);
};

class CMyApp :public CWinApp
{
public:

	virtual BOOL InitInstance() override {
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
			RUNTIME_CLASS(CMyView));

		if (pDocTemplate == nullptr) {
			return FALSE;
		}
		//Doc/View ���� ��ü ��� �Ѵ�
		AddDocTemplate(pDocTemplate);




		return TRUE;
	}

	virtual int ExitInstance() override
	{
		return 0;
	}
};

CMyApp theApp;