#include "..\Public\Shotgun.h"

Shotgun::Shotgun()
{
	cout << "Shotgun created\n" << endl;
}

Shotgun::Shotgun(float damage) : Weapon("Shotgun", damage)
{
}

float Shotgun::GetDamage() const
{
	return Weapon::GetDamage();
}

string Shotgun::GetName() const
{
	return Weapon::GetName();
}


