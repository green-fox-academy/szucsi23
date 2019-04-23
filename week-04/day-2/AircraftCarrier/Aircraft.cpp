//
// Created by hun46 on 2019. 04. 23..
//

#include "Aircraft.h"

Aircraft::Aircraft(Type type)
{
    _type = type;
    _ammo = 0;
    if (type == F16) {
        _maxAmmo = 8;
        _baseDamage = 30;
    } else if (type == F35) {
        _maxAmmo = 12;
        _baseDamage = 50;
    }
}

std::string Aircraft::getType()
{
    switch (_type) {
        case F16:
            return "F16";
        case F35:
            return "F35";
    }
}

std::string Aircraft::getStatus()
{
    std::stringstream ss;
    ss << "Type " << getType() << ", Ammo: " << _ammo << ", Base Damage: " << _baseDamage << ", All Damage: "
       << (_ammo * _baseDamage);
    return ss.str();
}

bool Aircraft::isPriority()
{
    if (_type == F35) return true;
    else return false;
}

int Aircraft::fight()
{
    int damage = _ammo * _baseDamage;
    _ammo = 0;
    return damage;
}

int Aircraft::refill(int storage)
{
    int remaining = storage;
    while(remaining > 0 && _ammo < _maxAmmo) {
        _ammo++;
        remaining--;
    }
    return remaining;
}

