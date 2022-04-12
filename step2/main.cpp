#include <afxwin.h>

//프레임 윈도우 생성 방법
//CFrameWnd : 프레임 윈도우
//윈도우 제목 : resource
//메뉴 : resource
//아이콘 : resource
//안쪽에 윈도우에 자식 윈도우를 생성하고 관리 할 수 있는 책임이 있다.
//도구 bar와 상태 bar를 생성해서 관리 할 수 있음
//생성 방법 3가지
/*
	1. CWind::Create() // 핵심
	2. LoadFrame()
	3. RuntimeClass 사용하는 방법 -> 새로만들기 MFC만들기로 가능

*/

//클래스 선언
class CMainFrame : public CFrameWnd {

};


class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {

		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->Create(NULL, NULL); //윈도우 생성
		//::CreateWindow(lpClassName, lpWindowName, dwStyle, x, y ...); 이런 내용물들을 MFC에서는 디폴트값으로 알아서 만들어 주기때문에 
		// pMainFrame->Create(NULL, NULL) 로 하면 된다.

		pMainFrame->ShowWindow(SW_SHOW); //화면에 윈도우를 출력한다.

		m_pMainWnd = pMainFrame; // 메인 윈도우를 설정한다.

		return TRUE;
	}
	int ExitInstance() {
		return 0;
	}
};

CMyApp theApp;