#include <afxwin.h>

//������ ������ ���� ���
//CFrameWnd : ������ ������
//������ ���� : resource
//�޴� : resource
//������ : resource
//���ʿ� �����쿡 �ڽ� �����츦 �����ϰ� ���� �� �� �ִ� å���� �ִ�.
//���� bar�� ���� bar�� �����ؼ� ���� �� �� ����
//���� ��� 3����
/*
	1. CWind::Create() // �ٽ�
	2. LoadFrame()
	3. RuntimeClass ����ϴ� ��� -> ���θ���� MFC������ ����

*/

//Ŭ���� ����
class CMainFrame : public CFrameWnd {

};


class CMyApp : public CWinApp {
public:
	BOOL InitInstance() {

		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->Create(NULL, NULL); //������ ����
		//::CreateWindow(lpClassName, lpWindowName, dwStyle, x, y ...); �̷� ���빰���� MFC������ ����Ʈ������ �˾Ƽ� ����� �ֱ⶧���� 
		// pMainFrame->Create(NULL, NULL) �� �ϸ� �ȴ�.

		pMainFrame->ShowWindow(SW_SHOW); //ȭ�鿡 �����츦 ����Ѵ�.

		m_pMainWnd = pMainFrame; // ���� �����츦 �����Ѵ�.

		return TRUE;
	}
	int ExitInstance() {
		return 0;
	}
};

CMyApp theApp;