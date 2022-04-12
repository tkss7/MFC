#include<afxwin.h>
#include"resource.h"
//RTTI
//factory design pattern
class A :public CObject {
	//DECLARE_DYNAMIC(A); // CObject::IsKindOf() ==> static A* CreatObject();
	DECLARE_DYNCREATE(A); // CObject::IsKindOf()  ��ü ������ �Ϲ�ȭ : ��ü�� �ڵ������� ������ �� �ִ� �Լ��� ���������� �������ش�.
	//DECLARE_SIRIAL(A);
private:
	int a, b;
public:
	A() : a(100), b(100) { TRACE("A() ������ ȣ��\n"); }

	~A() {
		TRACE("~A() �Ҹ���ȣ��\n");
	}
	int add(int a, int b) {
		TRACE("A::add() ȣ�� = %d\n", (this->a + this->b + a + b));
		return this->a + this->b + a + b;
	}

	//static A* CreatObject() { //���丮 �޼ҵ�
	//	return new A;
	//}
};

class B :public CObject {
	//DECLARE_DYNAMIC(B); 
	DECLARE_DYNCREATE(B);
	//DECLARE_SIRIAL(B);
private:
	int a;
	int b;
public:
	B():b(200) { TRACE("B() ������ ȣ��\n"); }

	~B() {
		TRACE("~B() �Ҹ���ȣ��\n");
	}
	int add(int a, int b) {
		return a + b;
	}
	
	int sub(int a, int b) {
		TRACE("B::SUB() ȣ�� : %d\n",(this->b + (a-b)));
		return a - b;
	}

};
//IMPLEMENT_DYNAMIC(A, CObject); //�θ��ڽİ����� ����� �����  : A* A::CreateObject(){ return new A; }
IMPLEMENT_DYNCREATE(A, CObject); //�θ��ڽİ����� ����� ����� , ��ü ������ �Ϲ�ȭ�� ���� �Լ� ����
//IMPLEMENT_DYNAMIC(B, CObject);
IMPLEMENT_DYNCREATE(B, CObject);
//IMPLEMENT_SERIAL(A, CObject,1); // �θ��ڽİ����� ����� �����, ��ü ������ �Ϲ�ȭ
//IMPLEMENT_SERIAL(B, CObject,1);


class CMainFrame :public CFrameWnd {

};

class CMyApp :public CWinApp
{
public :

	virtual BOOL InitInstance() override {
		CMainFrame* pMainFrame = new CMainFrame();

		pMainFrame->LoadFrame(IDR_MAIN_FRAME);
		pMainFrame->ShowWindow(SW_SHOW);
		m_pMainWnd = pMainFrame;
	

		/*
			��ü ���� ���
			1. A obj;
			2. A* obj = new A(); //Ư��ȭ
			3. A* obj = new A;
			4. A* obj = new A{}; //���� �̰� ���̾�



			int AAA(); // �Լ�����
			A obj(); // �Լ����� �Լ��� (obj) return type -> A

			RTTI -> Runtime type information

			CObject == MFC���� ���� �ֻ����� �θ�Ŭ����

		*/
		CObject* pObj = nullptr; // nullptr == void�� ������, NULL == int�� ������
		//CObject* pObj = NULL;
		//pObj = new A;

		CRuntimeClass* pClass = RUNTIME_CLASS(A);
		pObj = pClass->CreateObject(); // MFC�� ��ü ����


		//((A*)pObj)->add(10, 20);
		if (pObj->IsKindOf(RUNTIME_CLASS(A))) {
			((A*)pObj)->add(10, 20);
		}
		else if (pObj->IsKindOf(RUNTIME_CLASS(B))) {// �� Ŭ������ ������ ������ �����Ѱ�?
			((B*)pObj)->sub(10, 20);
		}
		else
			TRACE("@@@@@@@@@\n");

		delete pObj;

		pObj = new B;
		//((B*)pObj)->sub(10, 20);
		if (pObj->IsKindOf(RUNTIME_CLASS(A))) {
			((A*)pObj)->add(10, 20);
		}
		else if (pObj->IsKindOf(RUNTIME_CLASS(B))) {// �� Ŭ������ ������ ������ �����Ѱ�?
			((B*)pObj)->sub(10, 20);
		}
		else
			TRACE("@@@@@@@@@\n");
		delete pObj;


		return TRUE;
	}

	virtual int ExitInstance() override
	{
		return 0;
	}
};

CMyApp theApp;