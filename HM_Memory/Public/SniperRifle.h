#pragma once
#include "Weapon.h"
class SniperRifle :
    public Weapon
{
public:
    SniperRifle();
    SniperRifle(float damage);

    virtual float GetDamage() const override;
    virtual string GetName() const override;

};

