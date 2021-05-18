#include "Sword.h"

Sword::Sword() : Weapon(30, 15, 45, 30, 15) {}

Sword::Sword(int mana, int wisdom, int hp, int strength,int luck) : Weapon(mana, wisdom, hp, strength, luck) {}
