#include<afxwin.h>
#include"resource.h"
//RTTI
//factory design pattern
class A :public CObject {
	//DECLARE_DYNAMIC(A); // CObject::IsKindOf() ==> static A* CreatObject();
	DECLARE_DYNCREATE(A); // CObject::IsKindOf()  객체 생성의 일반화 : 객체를 자동적으로 생성할 수 있는 함수를 내부적으로 제공해준다.
	//DECLARE_SIRIAL(A);
private:
	int a, b;
public:
	A() : a(100), b(100) { TRACE("A() 생성자 호출\n"); }

	~A() {
		TRACE("~A() 소멸자호출\n");
	}
	int add(int a, int b) {
		TRACE("A::add() 호출 = %d\n", (this->a + this->b + a + b));
		return this->a + this->b + a + b;
	}

	//static A* CreatObject() { //팩토리 메소드
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
	B():b(200) { TRACE("B() 생성자 호출\n"); }

	~B() {
		TRACE("~B() 소멸자호출\n");
	}
	int add(int a, int b) {
		return a + b;
	}
	
	int sub(int a, int b) {
		TRACE("B::SUB() 호출 : %d\n",(this->b + (a-b)));
		return a - b;
	}

};
//IMPLEMENT_DYNAMIC(A, CObject); //부모자식관계의 연결고리 만들기  : A* A::CreateObject(){ return new A; }
IMPLEMENT_DYNCREATE(A, CObject); //부모자식관계의 연결고리 만들기 , 객체 생성의 일반화에 대한 함수 제공
//IMPLEMENT_DYNAMIC(B, CObject);
IMPLEMENT_DYNCREATE(B, CObject);
//IMPLEMENT_SERIAL(A, CObject,1); // 부모자식관계의 연결고리 만들기, 객체 생성의 일반화
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
			객체 생성 방법
			1. A obj;
			2. A* obj = new A(); //특별화
			3. A* obj = new A;
			4. A* obj = new A{}; //요즘 이걸 많이씀



			int AAA(); // 함수선언
			A obj(); // 함수선언 함수명 (obj) return type -> A

			RTTI -> Runtime type information

			CObject == MFC에서 가장 최상위의 부모클래스

		*/
		CObject* pObj = nullptr; // nullptr == void형 포인터, NULL == int형 포인터
		//CObject* pObj = NULL;
		//pObj = new A;

		CRuntimeClass* pClass = RUNTIME_CLASS(A);
		pObj = pClass->CreateObject(); // MFC식 객체 생성


		//((A*)pObj)->add(10, 20);
		if (pObj->IsKindOf(RUNTIME_CLASS(A))) {
			((A*)pObj)->add(10, 20);
		}
		else if (pObj->IsKindOf(RUNTIME_CLASS(B))) {// 이 클래스의 종류로 변경이 가능한가?
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
		else if (pObj->IsKindOf(RUNTIME_CLASS(B))) {// 이 클래스의 종류로 변경이 가능한가?
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