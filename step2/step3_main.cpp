#include<afxwin.h>

/*
	resource //���� ������ �ڿ� == ������ ���Ϸ� ���� �����ϴ� ��
	1. ������ ����
	2. �޴�
	3. ������
	�� 3������ ����Ͽ� ������ �����ϴ� ���
	LoadFrame() ����ؼ� FrameWnd ����


*/


class CMainFrame :public CFrameWnd {

};

class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {
		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->Create(NULL, NULL);
		pMainFrame->ShowWindow(SW_SHOW);

		m_pMainWnd = pMainFrame;
		return TRUE;
	}
	int ExitInstance() {
		return 0;
	}
};