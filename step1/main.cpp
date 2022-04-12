//#include<iostream>
#include<sdkddkver.h>
#include<afxwin.h> // iostream�� �����Ŷ� ���� ��
//using namespace std;

#define IN
#define OUT

int sum(IN const int a, IN const int b);
int sum(const int a, const int b);

int sum(IN const int a, OUT const int b);
int sum(const int a, const int b);

//�ܼ� �������α׷�
//int main(int argc, char** argv) { // MFC������ ������ ����
//
//	return 0;
//}
 
// ������ �������α׷� -> C style
// BOOL WinMain(...){
// 
// return 0;
// }

//������ ���ø����̼�
// 
//CWinApp : �������α׷��� ����ϴ� Ŭ����  ���� ����°� MFC�� Ȯ���̶� ����, �� ��輺���� ���� MFC�� �߰� �� ������ �Ǵ°� �ƴ� ���� Ȯ���� ��
//WinMain()�� CWinApp�ȿ� �����ִ�.

//sub �ý����� ������ : WinMain()
class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override {
		// ������  : ���� �Լ�
		TRACE("hello world\n"); // ������ �� ������

		//���� : F5 // ������ϰ� ����
		//���� : ctrl + F5 // ����� �����ʰ� ����

		TRACE("InitInstance() ȣ���\n");
/*
#ifdef _UNICODE
	#define TCHAR wchar_t
	#define _T(str) L(str)
#else
	#define TCHAR char
	#define _T(str) str
#endif

		char* p1 = "Hello World";
		wchar_t p2[] = L"Hello World";
*/
		//char* str
		//char str[] -> LPSTR // L long,  p : pointer,  Str : string , long�� ���� ���� �޸� ������ �� long near�� ������ �����
		//const char* -> LPCSTR

		//wchar_t* wstrl;
		//wchar_t wstr2[]; LPWSTR  L long, p : pointer, W : Wide, Str : string
		//	const wchar_t* wstr3;, LPCWSTR

			//LPCTSTR : cosnt char* , cosnt wchar_t*
		//LPTSTR : char* , wchar_t* 


		AfxMessageBox(_T("Hello World")); // MFC ����
		::MessageBox(NULL, _T("����"), _T("Ÿ��Ʋ"),MB_OK); // Win32API template
		//::MessageBoxW(); // Win32API -> unicode
		//::MessageBoxA(); // Win32API -> ansi code( �ƽ�Ű�ڵ�)

		return TRUE; //�������� ���̽��� TRUE
	}
	// MFC�� Win32 API�� Ȱ���ؼ� �ϹǷ� API�� ���������� �����ϸ鼭 MFC�� ���ر��� �̲��� ���ڴ�


	virtual int ExitInstance() override {
		TRACE("ExitInstance() ȣ���\n");
		return 0;
	}
};

CMyApp theApp;