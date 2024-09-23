#include <iostream>
#include <string>
#include <cctype> 

#include "Public\Character.h"
#include "Public\Blaster.h"
#include "Public\SniperRifle.h"
#include "Public\Shotgun.h"

using namespace std;

//�������� ������� ���� ��������� Character �� ��������
// 
//void SetWeapon(unique_ptr<Weapon> weapon); ���� ����� ���������
// 
//Weapon* GetWeapon() const; �� ����� ��������, �� �� ����� � ���������
//�������� ������� ���� Weapon �� ����� ������������ ��������
//float GetDamage() = 0; ������� �������� ����� ����
//string GetName() = 0; ������� ����� ����
//�������� ���� � 3 ����� - ������� ����� ���� ����
// 
//�������� �� ������� :
//���������� ���� ��������� ����� �����, �� �������� ���� ���� � ���� ������� ���������� ����, ��� ����� ����(��� �����) ���� ���� ������

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