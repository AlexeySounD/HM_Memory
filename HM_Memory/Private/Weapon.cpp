#include "..\Public\Weapon.h"

Weapon::Weapon()
{
	cout << "Create weapon";
}

Weapon::Weapon(string name, float damage) : Name(name), Damage(damage)
{
	cout << "Weapon created\n" << endl;
}

float Weapon::GetDamage() const
{
	return Damage;
}

string Weapon::GetName() const
{
	return Name;
}
