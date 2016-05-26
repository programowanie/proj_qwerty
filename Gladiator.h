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
	int charisma, morale, popularity, level;

public:
	Gladiator();
	void start();

	int getcharisma() { return charisma; };
	int getmorale() { return morale; };
	int getpopularity() {return popularity; };

	void addcharisma(int n) { charisma += n; };
	void addmorale();
	void lessmorale();

	void setmorale() { morale = 5; };

	void setname() { cin >> name; };
	string showname() { return name; }

	int random();
	void setstatistics();
	void statisticsshort();
	void dynamicstatistics();

	void addpopularity() {popularity += 3; };
	void droppopularity();
	void levelup() { level++; };
};