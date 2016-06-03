#pragma once

class Warrior
{
private:
	int strength,
		defence, 
		agility, 
		hp;

public:
	Warrior();

	int getstrength() { return strength; };
	int getdefence() { return defence; };
	int getagility() { return agility; };
	int gethp() { return hp; };

	int losehp(int n);
	void getup() { hp = 42; };

	void addstrength(int n) { strength += n; };
	void adddefence(int n) { defence += n; };
	void addagility(int n) { agility += n; };

	void clear();
};
