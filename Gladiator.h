#pragma once
#include "Warrior.h"
#include <string>
#include <iostream>

using namespace std;

class Gladiator 
	:public Warrior
{
private:
	string name;
	int charisma,
		morale,
		popularity,
		level;

public:
	Gladiator();

	void start();
	void getup();

	int getcharisma() { return charisma; };
	int getmorale()	{ return morale; };
	int getpopularity()	{ return popularity; };
	int getlevel() { return level; };

	void addcharisma(int n) { charisma += n; };
	void addmorale();
	void lessmorale (int difference);

	void setname() { cin >> name; };
	string showname() { return name; };

	int random();
	void clear();
	void setstatistics();
	void statisticsshort();
	void dynamicstatistics();

	void addpopularity();
	void droppopularity();
	void levelup() { level++; };
};
