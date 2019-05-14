//
// Created by hun46 on 2019. 04. 23..
//

#include "Carrier.h"

Carrier::Carrier(int health, int storage)
{
    _health = health;
    _storage = storage;
}

void Carrier::add(Aircraft plane)
{
    _aircrafts.push_back(plane);
}

void Carrier::fill()
{
    if(_storage == 0) throw ("Ammo storage is empty.");
    for (int i = 0; i < _aircrafts.size(); ++i) {
        if(_aircrafts.at(i).isPriority()) {
            _storage = _aircrafts.at(i).refill(_storage);
        }
    }
    for (int i = 0; i < _aircrafts.size(); ++i) {
        _storage = _aircrafts.at(i).refill(_storage);
    }



}

void Carrier::fight(Carrier ship)
{
    int otherHealth = ship.getHealth();
    int dealtDamage = 0;

    for (int i = 0; i < _aircrafts.size(); ++i) {
        dealtDamage += _aircrafts.at(i).fight();
    }

    if(dealtDamage > otherHealth) otherHealth = 0;
    else otherHealth -= dealtDamage;

    ship.setHealth(otherHealth);

}

int Carrier::getHealth() const
{
    return _health;
}

void Carrier::setHealth(int health)
{
    _health = health;
}

std::string Carrier::getStatus()
{
    if(_health = 0) return "It's dead Jim :(";

    std::stringstream ss;
    int totalDamage = 0;

    for (int i = 0; i < _aircrafts.size(); ++i) {
        totalDamage += (_aircrafts.at(i).getAmmo() * _aircrafts.at(i).getBaseDamage());
    }
    ss << "HP: " << _health << ", Aircraft count: " << _aircrafts.size() << ", Ammo storage: " << _storage << ", Total damage: " << totalDamage << "\nAircrafts:\n";

    for (int i = 0; i < _aircrafts.size(); ++i) {
        ss << _aircrafts.at(i).getStatus() << "\n";
    }
    return ss.str();
}
