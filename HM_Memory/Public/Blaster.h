#pragma once
#include "..\Public\Weapon.h"

class Blaster :
    public Weapon
{
public:
    Blaster();
    Blaster(float damage);

    virtual float GetDamage() const override;
    virtual string GetName() const override;
};
