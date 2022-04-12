//#include "Library.h"
#include<iostream>
#include <vector>

using namespace std;

//������ : masungil2@daum.net
/*
���� : 1. ���� ���� : �����Ϸ��� ����� (�ð��� ���� �ɸ��� ����)
       2. �� ���� : ������ ������� ���ؼ� ��´�(�ð��� ���� �ɸ�)
              
       read,  read/write

*/

//Windows Programming API(Application Programmig Interface)
//  
// class A {
//   virtual void func();
// };
// 
// class B : public A {
// 
// }
// 
// 
//MFC 

//�ܼ����α׷� 
//������ : main() 
//�ܼ� ��� : cpp -> cout , c -> printf, ǥ�� �����ġ 
//Ű���� �Է� : cpp -> cin , c -> scanf, gets(), getchar(), ... :  ǥ�� �Է���ġ 
//���� ��ƾ�� ���������� ó���� 



//���������α׷�(Win32 API) -> C style �ۼ�
//������ : WinMain() 
//��� : �����쿡 ��� 
//�Է� : Mouse, keyboard
//���α׷� �帧�� ���� ��Ģ�� ��ӵǾ� ���� 
//���������� ���� ���� ���� 
//�޽����� ���� �������� ����� 

//solid ���� 
/*
1. ���� å���� ��Ģ 
2. ���� ������ ��Ģ 
3. �������� ġȯ ��Ģ 
4. �������̽� �и� ��Ģ
5. ������ ���� ��Ģ 
*/

/*
������ 
�����
������ 
*/
class Animal {
public:
    virtual void speak() const = 0;
};

class Cat : public Animal {
public:
    virtual void speak() const override {
        cout << " �߿� ~~~~" << endl;
    }
};

class Dog : public Animal {
public:
    virtual void speak() const override {
        cout << " �۸� ~~~~" << endl;
    }
};

//�߰��� 
class Cow : public Animal {
public:
    virtual void speak() const override {
        cout << " ���� ~~~~" << endl;
    }
};

//���� �ڵ� 
class Zoo {
private:
    //Cat cat;
    //Dog dog;
    ////�߰��� 
    //Cow cow;
    vector<Animal*> array;

public:
    void addAnimal(Animal* const pAnimal) {
        //pAnimal++; ������ ������ �̿��ؼ� �����͸� �����ϸ� ������ ���� �߻��ϰ� ���� (const)
        array.push_back(pAnimal);
    }

    void speak() {
        //cat.cat_speak();
        //dog.dog_speak();
        ////�߰���
        //cow.cow_speak();
        for (const auto& pAnimal : array) {
            pAnimal->speak();
        }
    }
};

//���� library ��� + ���� ��� �߰�(main()�� �ۼ��� ����) -> ���� ���α׷� �ۼ� 
//pointer -> indirect -> virtual function , ������ ����, ocp
//framework ����, �ڵ� ���

int sum(const int* const arr, const int size) {
    int sum = 0;
    //const int count = 10;
    //
    //count += 10;


    //arr[0] == *arr
    //*arr = 10;  //�迭�� read/write �����ϸ� OK
    //arr += 10;   //arr�� ���� write �� 

//    arr++;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        //size++;
        //arr[i]++;
    }

    return sum;
}

int add(const int a, const int b) {
    return a + b;
}

int sub(const int a, const int b) {
    return a - b;
}

//typedef type ������; //�������� ���ο� ������ �����Ѵ�
//unsigned int UINT;

//unsigned int aaa;
//UINT bbb;

//int (*)(const int, const int);

typedef int (*FP_CALC)(const int, const int);
FP_CALC calc;


class Calc {
public:
    virtual int calc(const int a, const int b) = 0;
};

class AddCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a + b;
    }
};

class SubCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a - b;
    }
};

class MulCalc : public Calc {
public:
    virtual int calc(const int a, const int b) override {
        return a * b;
    }
};

//ocp
int MyCalc(Calc& obj, const int a, const int b) {
    //����Ǵ� �� ���� , ���ο� ��� �ڿ������� ���� �� �� �ִ���?
    return obj.calc(a, b);
}


bool InitInstance(Zoo* pZoo)
{
    Cat cat;
    Dog dog;
    Cow cow;

    pZoo->addAnimal(&dog);
    pZoo->addAnimal(&cat);
    pZoo->addAnimal(&cow);

}

bool Run(Zoo* pZoo) {
    pZoo->speak();
    return true;
}

bool ExitInstance(Zoo* pZoo)
{
    return true;
}

int main(int argc, char** argv)
{
//    int a = 10; //atoi(argv[1]);
//    int b = 20; //atoi(argv[2]);
//    int c = 10;
//    int d = 20;
//    int e = 10;
//    int f = 20;
//    int sum;
//
//    
//
//    //������ Ÿ�� 
//    //��Ÿ�� 
////    sum = a + b; //������ �ڵ� -> sum = 10 + 20;
//    //debug -> �Լ��� ���� ������ : runtime�� ����� , ����� ������ ����� �ȿ� ���Ե� 
//    //release -> ����ȭ�� �����ڵ�� ������ sum = 30
//    //����(exe �����)  : �Ϲ����� ��� debug ��尡 exe ������ ���� ������
//    //���� : �Ϲ����� release ����� ������� ������ 
//    //ũ�� : debug ��尡 ũ��, release ��尡 ���� debug ��� ��� 1/4 ���� �۴� 
//    //�Ϲ�ȭ / Ư��ȭ 
//    //pointer -> data pointer, function pointer
//    int* p1 = &a;
//    int* p2 = &b;
//
//    sum = 10 + 20;
//
//    sum = a + b;
//    sum = c + d;
//    sum = e + f;
//    
//    p1 = &a;
//    p2 = &b;
//    sum = *p1 + *p2;
//
//    p1 = &c;
//    p2 = &d;
//    sum = *p1 + *p2;
//
//    p1 = &e;
//    p2 = &f;
//    sum = *p1 + *p2;
//
//    int result = 0;
//
//    calc = add;
//    result = calc(a, b);
//
//    calc = sub;
//    result = calc(a, b);
//
//    //�Լ������� 
//    Calc* pCalc = new AddCalc();
//    result = pCalc->calc(a, b); //a + b;
//    delete pCalc;
//
//    pCalc = new SubCalc();
//    result = pCalc->calc(a, b); //a - b;
//    delete pCalc;
//    
//    AddCalc addCalc;
//    Calc& objA = addCalc;
//    result = objA.calc(a, b); //a + b;
//
//    SubCalc subCalc;
//    Calc& objB = subCalc;
//    result = objB.calc(a, b); //a - b;
//
//    result = MyCalc(addCalc, a, b);
//    result = MyCalc(subCalc, a, b);
//
//    //���Ӱ� �߰��� �κ� 
//    MulCalc objC;
//    result = MyCalc(objC, a, b);
//
//    vector<Calc*> arr = {&addCalc, &objC, &subCalc};
//    //for (auto& pCalc : arr) {
//    for (int i = 0; i < arr.size();i++) {
//        MyCalc(*arr[i], a, b);
//    }
//    for (auto& pCalc : arr) {
//        MyCalc(*pCalc, a, b);
//    }
//
//    cout << a << " + " << b << " = " << sum << endl;
//
//    Zoo zoo;
//    Cat cat;
//    Dog dog;
//    Cow cow;
//
//    zoo.addAnimal(&dog);
//    zoo.addAnimal(&cat);
//    zoo.addAnimal(&cow);
//
//    zoo.speak();

    Zoo zoo;

    InitInstance(&zoo);

    Run(&zoo);

    ExitInstance(&zoo);


    return 0;
}