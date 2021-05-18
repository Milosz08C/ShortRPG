#include "Scepter.h"

Scepter::Scepter() : Weapon(35, 45, 40, 10, 10) {}

Scepter::Scepter(int hp, int mana, int wisdom, int strength) : Weapon(hp, mana, wisdom, strength, 0) {}