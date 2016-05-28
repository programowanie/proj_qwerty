#pragma once
#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"

int   skillchoice();
void  fight(Gladiator * player, Gladiator * enemy);
void  fight(Gladiator * player, Animal * mytiger);
void  fightbehind(Gladiator * enemy, Animal * enemytiger);
void  skill(int pchoice, int echoice, Gladiator * player, Gladiator * enemy);
void  skill(int pchoice, int tchoice, Gladiator * player, Animal * mytiger);
float attack(int strength, int morale, int defence, bool skill);
