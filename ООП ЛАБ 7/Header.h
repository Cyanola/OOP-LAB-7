#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#define M_PI 3.1415926
using namespace std;
class Coordinate
{
protected: double x; double y;
public:

	virtual void Method(char A) = 0;

	double GetX()
	{
		return x;
	}

	void SetX(double valueX)
	{
		x = valueX;
	}

	void SetY(double valueY)
	{
		y = valueY;
	}

	double GetY()
	{
		return y;
	}
	virtual  ~Coordinate()
	{

	}
};

class Dekart :public Coordinate
{
public:

	Dekart()
	{
		x = 0;
		y = 0;
	}
	Dekart(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	void Method(char A) override
	{
		cout << "Точка " << A << " имеет декартовы координаты " << "{" << setprecision(2) << fixed << x << ", " << y << "}" << endl;
	}
	~Dekart() override
	{

	}
};
class Polyar :public Coordinate
{
private: double fi; int k;
public:
	friend void func(Polyar& value, Dekart& val);


	Polyar()
	{
		x = 0;
		y = 0;
	}
	Polyar(double a, double b)
	{
		x = a;
		y = b;
	}
	~Polyar() override
	{

	}
	double CoorR()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}
	void vvod()
	{
		cout << "Выберите интервал: 1) (-pi;+pi) или 2) (0;+2pi): " << endl; cin >> k;
	}
	double CoorFi()
	{
		switch (k)
		{
		case 1:
		{
			if (x > 0)
			{
				fi = atan2(y, x);
			}
			else if (x < 0 && y >= 0)
			{
				fi = atan2(y, x) + M_PI;
			}
			else if (x < 0 && y < 0)
			{
				fi = atan2(y, x) - M_PI;
			}
			else if (x == 0 && y > 0)
			{
				fi = M_PI / 2;
			}
			else if (x == 0 && y < 0)
			{
				fi = -(M_PI / 2);
			}
			else if (x == 0 && y == 0)
			{
				cout << "Полярный угол - любое действительное число" << endl;
			}
			break;
		}
		case 2:
		{
			if (x > 0 && y >= 0)
			{
				fi = atan2(y, x);
			}
			else if (x > 0 && y < 0)
			{
				fi = atan2(y, x) + 2 * M_PI;
			}
			else if (x < 0)
			{
				fi = atan2(y, x) + M_PI;
			}
			else if (x == 0 && y > 0)
			{
				fi = M_PI / 2;
			}
			else if (x == 0 && y < 0)
			{
				fi = 3 * M_PI / 2;
			}
			else if (x == 0 && y == 0)
			{
				cout << "Полярный угол - любое действительное число" << endl;
			}
			break;
		}
		}
		return this->fi;
	}
	void Method(char A) override
	{
		cout << "Точка " << A << " имеет полярные координаты " << "{" << setprecision(6) << fixed << CoorR() << ", " << setprecision(6) << fixed << CoorFi() << "}" << endl;
	}


};
//class Do
//{
//private: char A;
//public:
//	void Method(Coordinate* coordinate)
//	{
//		coordinate->Method(A);
//	}
//};
void func(Polyar& value, Dekart& val)
{
	double a, b;
	char A = 'A';
	cout << "\t\t\tПеревод из полярных координат в декартовые" << endl;
	value.Method(A);
	a = value.CoorR() * cos(value.CoorFi());
	b = value.CoorR() * sin(value.CoorFi());
	val.SetX(a);
	val.SetY(b);
	val.Method(A);
}
