#pragma once
#include "Weapon.h"
class Shotgun :
    public Weapon
{
public:
    Shotgun();
    Shotgun(float damage);

    virtual float GetDamage() const override;
    virtual string GetName() const override;


};

