#include "..\Public\SniperRifle.h"

SniperRifle::SniperRifle()
{
	cout << "SniperRifle created\n" << endl;
}

SniperRifle::SniperRifle(float damage) : Weapon("SniperRifle", damage)
{
}

float SniperRifle::GetDamage() const
{
	return Weapon::GetDamage();
}

string SniperRifle::GetName() const
{
	return Weapon::GetName();
}
