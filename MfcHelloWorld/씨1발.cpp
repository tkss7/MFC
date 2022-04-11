#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;// -> 0은 추상클래스화, const는 이 함수 안에서의 값은 읽기만 하겠다는 의미
};
class Cat : public Animal {
public:
    virtual void speak() const override { cout << "야용" << endl; }
};
class Dog :public Animal {
public:
    virtual void speak() const override { cout << "머" << endl; }
};
class Zoo {
private:
    vector<Animal*> array;//->직접 변수명 선언이 아닌 벡터를 이용하여 관리한다
public:
    void addAnimal(Animal* const pAnimal) {
        //->포인터 변수를 이용해서 포인터를 변경하면 컴파일오류 발생하도록 설정
        array.push_back(pAnimal);
    }
    void speak() {
        for (const auto& pAnimal : array) {
            // ->읽기 전용으로 쓰겠다
            pAnimal->speak();
        }

    }
};
int main() {
    Zoo zoo;
    Cat cat;
    Dog dog;

    zoo.addAnimal(&dog);
    zoo.addAnimal(&cat);
    zoo.speak();
}