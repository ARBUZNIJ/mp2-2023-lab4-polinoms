#include "polynomials.h"
#include <locale>

int main()  
{
	setlocale(LC_ALL, "Rus");
	int quan_input;
	cout << "������� ���������� ������� � ��������: ";
	cin >> quan_input;
	Polynomial a(quan_input);
	cout << "������� ���������� ������� � ��������: ";
	cin >> quan_input;
	Polynomial b(quan_input), c;
	b-=a;
	cout << b << endl/* << exam*/;
}