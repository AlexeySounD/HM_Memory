#include "..\Public\Character.h"

void Character::SetCurrentWeapon(unique_ptr<Weapon> weapon)
{
	if (CurrentWeapon != nullptr)
	{
		AddWeapon(move(CurrentWeapon));
	}	
	CurrentWeapon = move(weapon);
}

unique_ptr<Weapon> Character::GetWeaponByID(int id)
{
	if (Weapons.size() == 0)
	{
		cout << "No weapons in Inventory ";
	}
	else 
	{
		if (Weapons.size() >= id)
		{
			// Список  [ индекс ] оператор индексации	
			return move(Weapons[id]);
		}
		else
		{
			cout << "Incorrect ID";
		}		
	}
}

void Character::ShowEquipment()
{
	int counter = 0;	
	if (Weapons.size() == 0)
	{
		cout << "no Weapons" << endl;
	}	
	for (unique_ptr<Weapon>& tempWeapon : Weapons )
	{	
		if (tempWeapon != nullptr)
		{
			cout << "Character has: " << endl;
			cout << "ID: " << counter << endl << "Weapon: " << tempWeapon->GetName() << endl << "Damage: " << tempWeapon->GetDamage() << "\n" << endl;
			counter++;
		}
		else
		{	
			cout << "Empty slot \n" << endl;
		}
	}	
}

void Character::AddWeapon(unique_ptr<Weapon> weapon)
{
	Weapons.push_back(move(weapon));
}

void Character::RemoveWeaponsSlot(int id)
{	
	if (!Weapons.empty() && Weapons.size() >= id)
	{
		Weapons.erase(Weapons.begin() + id);
	}
}

void Character::MakeHandsFree()
{
	if (CurrentWeapon != nullptr)
	{
		AddWeapon(move(CurrentWeapon));
	}	
}

void Character::ShowCurrentWeapon()
{
	if (CurrentWeapon == nullptr)
	{
		cout << "Character hands EMPTY" << endl;
	}
	else
	{
		cout << "Character equiped: " << CurrentWeapon->GetName() << endl;
	}
}
