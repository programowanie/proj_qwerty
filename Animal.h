#pragma once
#include "Warrior.h"
#include <string>

using namespace std;

class Animal
	:public Warrior
{
private:
	string name;
	int anger;

public:
	Animal();

	int getanger() { return anger; };
	void addanger();
	void addanger(int n);

	int random(int level);
	void clear();

	void statisticsshort();
	void dynamicstatistics();

	string showname() { return name; }
};
