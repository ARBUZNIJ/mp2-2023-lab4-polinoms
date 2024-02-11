#pragma once
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class Polynomial
{
private:
	class Monome
	{
	public:
		double alpha;
		int m;
		Monome* next;
		Monome(double alp, int pow, Monome* next);
		Monome(const Monome& mn);//����������� ����������� �������. ��������� ����� - null
		~Monome();
	};
	Monome* head;
	int quanity;
public:
	Polynomial(int quan); //����������� ����������������� �����
	Polynomial(int quan, double* arr); //����������� �������� �� ������� �������������� ������ ������ (��� ������)
	Polynomial(const Polynomial& p);  //�-� ����������� (�� ������ ��������� �� ���� � ��� �� ������, next = nullptr)
	Polynomial();
	~Polynomial();
	void pop(double alpha, int pow);
	bool operator==(const Polynomial& p);
	bool operator!=(const Polynomial& p);
	Polynomial& operator=(const Polynomial& p);
	Polynomial operator *(double factor);
	Polynomial& operator *=(double factor);
	Polynomial operator +(const Polynomial& p);
	Polynomial& operator +=(const Polynomial& p);
	Polynomial operator -(const Polynomial& p);
	Polynomial& operator -=(const Polynomial& p);
	Polynomial operator *(const Polynomial& p);
	Polynomial& operator *=(const Polynomial& p);
	int poly_out(double* tmp);//���������� ���-�� �������, � tmp ���������� ������ (�-�, ������� x, ������� y, ������� z)
	friend ostream& operator<<(ostream& ostr, const Polynomial& p)
	{
		Monome* prev = p.head->next;
		if (p.quanity != 0)
		{
			ostr << prev->alpha << " x^" << (prev->m) / 100 << " y^" << ((prev->m) % 100) / 10 << " z^" << (prev->m) % 10;
			prev = prev->next;
		}
		else ostr << '0';
		for (int i = 1; i < p.quanity; i++)
		{
			ostr << " + " << prev->alpha << " x^" << (prev->m) / 100 << " y^" << ((prev->m) % 100) / 10 << " z^" << (prev->m) % 10;
			prev = prev->next;
		}
		return ostr;
	}
};