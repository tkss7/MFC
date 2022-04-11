#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;// -> 0�� �߻�Ŭ����ȭ, const�� �� �Լ� �ȿ����� ���� �б⸸ �ϰڴٴ� �ǹ�
};
class Cat : public Animal {
public:
    virtual void speak() const override { cout << "�߿�" << endl; }
};
class Dog :public Animal {
public:
    virtual void speak() const override { cout << "��" << endl; }
};
class Zoo {
private:
    vector<Animal*> array;//->���� ������ ������ �ƴ� ���͸� �̿��Ͽ� �����Ѵ�
public:
    void addAnimal(Animal* const pAnimal) {
        //->������ ������ �̿��ؼ� �����͸� �����ϸ� �����Ͽ��� �߻��ϵ��� ����
        array.push_back(pAnimal);
    }
    void speak() {
        for (const auto& pAnimal : array) {
            // ->�б� �������� ���ڴ�
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