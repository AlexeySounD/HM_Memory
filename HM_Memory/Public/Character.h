#pragma once
#include <memory>
#include <iostream>
#include "Weapon.h"
#include <vector>

using namespace std;

class Character
{
public:
	void SetCurrentWeapon(unique_ptr<Weapon> weapon);
	Weapon* GetCurrentWeapon() const { return CurrentWeapon.get(); }
	unique_ptr<Weapon> GetWeaponByID(int id);
	void ShowEquipment();
	void ShowCurrentWeapon();
	void AddWeapon(unique_ptr<Weapon> weapon);
	void RemoveWeaponsSlot(int id);	
	void MakeHandsFree();

private:
	unique_ptr<Weapon> CurrentWeapon;
	vector<unique_ptr<Weapon>> Weapons;

};