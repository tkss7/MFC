#include<iostream>
#include<vector>
using namespace std;

typedef double (*FP_CALC)(const int, const int);
FP_CALC calc;

class Calc
{
public:
	virtual double calc(const int a, const int b) = 0;
};

class DivCalc :public Calc {
public:
	virtual double calc(const int a, const int b) override
	{
		if (b == 0)
			return -99999;
		else
			return (double)a / b;
	}
};

auto MyCalc(Calc& obj, const int a, const int b) {
	//변경되는 것 없음 , 새로운 기능 자연스럽게 실행 할 수 있는지?
	return obj.calc(a, b);
}

void Input(int& a, int& b)
{
	do {
		cout << "두 수를 입력하세요" << endl;
		cin >> a;
		cin.clear();

		cin >> b;
		cin.clear();
		cin.ignore();
	} while (!cin);
}

void Output(const double result)
{
	if (result == -99999)
		cout << " 올바르지 않은 수식입니다." << endl;
	else
		cout << result << endl;
}


int main()
{

	DivCalc objB;
	int a, b;

	Input(a, b);

	auto result = MyCalc(objB, a, b);

	Output(result);

	
	return 0;
}