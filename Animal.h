#pragma once
#include "Warrior.h"

class Animal
	:public Warrior
{
private:
	int anger;

public:
	Animal();
	void addanger(int n) { anger += n; };
	int  getanger() 	 { return anger; };
	int  randomselection(int level);
	void displaystatistics();
};
