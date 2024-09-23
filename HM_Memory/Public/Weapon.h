#pragma once
#include <string>
#include <iostream>

using namespace std;

class Weapon
{
public:	
	Weapon();
	Weapon(string name, float damage);	
	virtual float GetDamage() const = 0;
	virtual string GetName() const = 0;


private:
	float Damage = 0;
	string Name = "Default";
};

