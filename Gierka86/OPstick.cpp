#include "OPstick.h"

OPstick::OPstick() : Weapon(60, 65, 60, 45, 20) {}

OPstick::OPstick (int mana, int wisdom, int hp, int luck) : Weapon(hp, mana, wisdom, 0, luck) {}