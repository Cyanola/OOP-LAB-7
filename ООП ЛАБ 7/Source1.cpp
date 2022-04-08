#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


class Weapon//абстрактный класс
{
public: virtual void Shoot() = 0;
	  void Foo()
	  {
		  cout << "Foo()" << endl;
	  }
};


class Gun :public Weapon{

public: 
	void Shoot() override//чтобы можно было переопределить
	{
		cout << "BANG" << endl;
	}

};
class SubmachineGun :public Gun
{

public:

	 void Shoot() override//чтобы правильно переопределить метод
	{
		cout << "BANG BANG BANG" << endl;
	}

};


class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VZHUHHH" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon*weapon) {
		weapon->Shoot();
	}
};

class Bazooka :public Weapon
{

public:

	void Shoot() override//чтобы правильно переопределить метод
	{
		cout << "BANDBUB" << endl;
	}

};
int main0()
{
//	Gun gun;
//	SubmachineGun machineGun;
//	Bazooka bazooka;
////	Gun* weapon = &gun;
////	Gun* weapon = &machinegun;
//
//	//weapon->Shoot();
//	//gun.Shoot();
//	Player player;
//	player.Shoot(&bazooka);
	Bazooka bazooka;
	Knife knife;
	Player player;
	player.Shoot(&knife);
	knife.Foo();
	return 0;
}