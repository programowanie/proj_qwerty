#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior()
{
	strength = 0;
	defence = 0;
	agility = 0;
	hp = 42;
}

void Warrior::clear()
{
	strength = 0;
	defence = 0;
	agility = 0;
}

int Warrior::losehp(int n)
{
	hp -= n;
	return n;
}
