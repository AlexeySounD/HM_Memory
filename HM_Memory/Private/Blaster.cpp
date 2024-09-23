#include "..\Public\Blaster.h"

Blaster::Blaster()
{
	cout << "Blaster created\n" << endl;
}

Blaster::Blaster(float damage) : Weapon("Blaster", damage)
{	
}

float Blaster::GetDamage() const
{
	return Weapon::GetDamage();
}

string Blaster::GetName() const
{
	return Weapon::GetName();
}
