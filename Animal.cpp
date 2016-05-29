#include "Animal.h"
#include "Colors.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Animal::Animal()
:Warrior()
{
	anger = 3;
	addagility(42);
	name = "TYGRYS";
}

int Animal::random(int level)
{
	int repeat,
		points = 7*level;

	repeat = rand() % points + 1;
	addstrength(repeat);
	
	points -= repeat;
	if (points==0) 
		return 0;

	adddefence(points);

	return 0;
}

void Animal::statisticsshort()
{
	cout << green << showname() << ":";
	cout << red << " Atak:" << def << setw(2)  << getstrength()
		 << blue << "  Unik:" << def << setw(2)  << getdefence()
		 << yellow << "  Szybkość:" << def << setw(2) << getagility();
}

void Animal::dynamicstatistics()
{
	cout << green << showname() << red << "  HP:"<< def << setw(2) << gethp()
		 << yellow << "  Wściekłość:" << def << setw(2) << getanger();
}

void Animal::clear()
{
	Warrior::clear();
	Warrior::getup();
	anger = 3;
}

void Animal::addanger()
{
	anger += 2;
	if (anger > 10)
		anger = 10;
}

void Animal::addanger(int n)
{
	anger += n;
	if (anger > 10)
		anger = 10;
}

