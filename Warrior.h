#pragma once

class Warrior
{
private:
	int strength, defence, agility, hp;

public:
	Warrior();
	int getstrength() { return strength; };
	int getdefence() { return defence; };
	int getagility() { return agility; };
	int gethp() { return hp; };

	void losehp(int n) { hp -=n; };
	void sethp() { hp = 100; };

	void addstrength(int n) { strength += n; };
	void adddefence(int n) { defence += n; };
	void addagility(int n) { agility += n; };
};