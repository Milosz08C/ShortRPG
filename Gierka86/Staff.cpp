#include "Staff.h"

Staff::Staff() : Weapon(20, 30, 30, 5, 5) {}

Staff::Staff(int hp, int mana, int wisdom, int luck) : Weapon(hp, mana, wisdom, 0, luck) {}