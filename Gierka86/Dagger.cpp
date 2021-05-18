#include "Dagger.h"

Dagger::Dagger() : Weapon(20, 25, 40, 20, 10) {} 

Dagger::Dagger(int mana, int wisdom, int hp, int strength, int luck) : Weapon(mana, wisdom,hp, strength, luck) {}
