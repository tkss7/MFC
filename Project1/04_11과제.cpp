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
	//����Ǵ� �� ���� , ���ο� ��� �ڿ������� ���� �� �� �ִ���?
	return obj.calc(a, b);
}

void Input(int& a, int& b)
{
	do {
		cout << "�� ���� �Է��ϼ���" << endl;
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
		cout << " �ùٸ��� ���� �����Դϴ�." << endl;
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