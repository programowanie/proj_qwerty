#include "Animal.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Animal::Animal()
:Warrior()
{
	anger = 0;
}

int Animal::randomselection(int level)
{
	int repeat,
		points = 12*level;

	repeat = rand() % points + 1;
	addstrength(repeat);
	
	points -= repeat;
	if (points==0) return 0;

	repeat = rand() % points + 1;
	adddefence(repeat);

	points -= repeat;
	if (points==0) return 0;

	repeat = rand() % points + 1;
	addagility(repeat);

	points -= repeat;
	if (points==0) return 0;

	repeat = rand() % points + 1;
	addanger(repeat);
}

void Animal::displaystatistics()
{
	cout << "Atak: " << getstrength() << " Obrona: " << getdefence()
	 << " Zrecznosc: " << getagility() << " Wściekłość:" << getanger() << endl;
}