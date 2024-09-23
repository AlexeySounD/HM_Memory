#include <iostream>
#include <string>
#include <cctype> 

#include "Public\Character.h"
#include "Public\Blaster.h"
#include "Public\SniperRifle.h"
#include "Public\Shotgun.h"

using namespace std;

//Створити базовий клас Персонажа Character із методами
// 
//void SetWeapon(unique_ptr<Weapon> weapon); видає зброю персонажу
// 
//Weapon* GetWeapon() const; дає змогу дізнатися, що за вепон у персонажа
//Створити базовий клас Weapon із двома абстрактними методами
//float GetDamage() = 0; повертає значення шкоди зброї
//string GetName() = 0; повертає назву зброї
//Створити хоча б 3 класи - нащадки різних видів зброї
// 
//Завдання із зірочкою :
//Переробити клас персонажа таким чином, що персонаж може мати у себе декілька екземплярів зброї, але тільки одна(або жодна) може бути обрана

int main()
{
	//Blaster* myBlasterPtr = new Blaster("Blaster", 100.f);
	Character* myCharacter = new Character();

	unique_ptr<Blaster> myBlasterPtr = make_unique<Blaster>(250.f);
	unique_ptr<SniperRifle> mySniperRiflePtr = make_unique<SniperRifle>(500.f);
	unique_ptr<Shotgun> myShotgunPtr = make_unique<Shotgun>(360.f);

	int id;	
	char command;
	bool GameStart = true;

	myCharacter->AddWeapon(move(myBlasterPtr));
	myCharacter->AddWeapon(move(mySniperRiflePtr));
	myCharacter->AddWeapon(move(myShotgunPtr));

	while (GameStart)
	{
		system("cls");
		myCharacter->ShowCurrentWeapon();
		myCharacter->ShowEquipment();
		cout << "Please write ID of Weapon which y wanna equip or Press 'G' to make hands empty: " << endl;
		cin >> command;
		if (isdigit(command))
		{
			id = command - '0';
			myCharacter->SetCurrentWeapon(myCharacter->GetWeaponByID(id));
			myCharacter->RemoveWeaponsSlot(id);
		}
		else if (command == 'G' || command == 'g')
		{
			myCharacter->MakeHandsFree();
		}
		else
		{
			system("cls");
			cout << "Wrong command" << endl;	
			system("pause");
		}		
	}
	return 0;
}