#include<afxwin.h>
#include"resource.h"
//RTTI
//factory design pattern

/*
	Document/View
	MVC
		Model (Document)
		View
		Controller (제어) : 위 두개를 제어

	Document : Data 관리가 목적 (새문서 , 열기, 저장)
	View : 화면 출력
*/
class CMyDoc : public CDocument {
public:

	DECLARE_DYNCREATE(CMyDoc);

	virtual BOOL OnNewDocument() override { // 새문서 기능 구현 함수

	}

	virtual void Serialize(CArchive& ar) override { //파일의 읽기 쓰기를 담당

	}
};

class CMyView : public CView {
public:
	DECLARE_DYNCREATE(CMyView);

	virtual void OnDraw(CDC* pDC) override { //화면 출력에 대한 함수

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

		//Doc/View 구조
		//Document/View 구조
		//단일 문서
		//다중 문서
		CSingleDocTemplate* pDocTemplate;
		pDocTemplate = new CSingleDocTemplate(IDR_MAIN_FRAME2,
			RUNTIME_CLASS(CMyDoc), //CRuntimeClass
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CMyView));

		if (pDocTemplate == nullptr) {
			return FALSE;
		}
		//Doc/View 구조 객체 등록 한다
		AddDocTemplate(pDocTemplate);




		return TRUE;
	}

	virtual int ExitInstance() override
	{
		return 0;
	}
};

CMyApp theApp;