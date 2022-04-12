#include<afxwin.h>
#include"resource.h"
/*
	resource //재사용 가능한 자원 == 별도의 파일로 빼서 관리하는 것
	1. 윈도우 제목
	2. 메뉴
	3. 아이컨
	위 3가지를 사용하여 윈도우 생성하는 방법
	LoadFrame() 사용해서 FrameWnd 생성


*/


class CMainFrame :public CFrameWnd {

};

class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {
		CMainFrame* pMainFrame = new CMainFrame();
		//pMainFrame->Create(NULL, NULL);
		pMainFrame->LoadFrame(IDR_MAIN_FRAME);
		pMainFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pMainFrame;
		return TRUE;
	}
	int ExitInstance() {
		return 0;
	}
};

CMyApp theApp;