#include <iostream>
#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	double x, y;
	char A = 'A';
	void (*pFcn)(Polyar&, Dekart&) = nullptr;
	cout << "¬ведите декартовые координаты точки: "; cin >> x >> y;
	Dekart dekart(x,y);
	
	Polyar polyar(x,y);
	polyar.vvod();
	Dekart* dek = &dekart;
	Polyar* pol = &polyar;
	dek->Method(A);
	pol->Method(A);
/*	doo.Method(&dekart);
	doo.Method(&polyar);*/
	pFcn = func;
	pFcn(polyar, dekart);

	return 0;
}