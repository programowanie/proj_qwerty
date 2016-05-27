#include "Gladiator.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <fstream>
#include <iomanip>

using namespace std;

Gladiator::Gladiator()
:Warrior()
	{
		charisma = 0;
		morale = 5;
		popularity = 0;
		level = 1;
	}

void Gladiator::setstatistics()
{
	int stat,
		points = 10;

	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "Atak: " << getstrength() << " Obrona: " << getdefence()
	 << " Zrecznosc: " << getagility() << " Charyzma:" << getcharisma() << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;		

	while (points--)
	{
		cout << "Co chcesz dodać?: (pozostało: " << points + 1 << ") \n1.Atak\n2.Obrona\n3.Zręczność\n4.Charyzma"<< endl;
		cin >> stat;
		switch (stat)
		{
			case 1: 
				addstrength(1); break;
			
			case 2: 
				adddefence(1); break;

			case 3: 
				addagility(1); break;

			case 4: 
				addcharisma(1); break;
		}
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "Atak: " << getstrength() << " Obrona: " << getdefence()
		 << " Zrecznosc: " << getagility() << " Charyzma:" << getcharisma() << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
	} 
}

int Gladiator::random()
{
	clear();
	vector <string> names;
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
	int size = (names.size());
	name = names[rand() % size];

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
	addcharisma(repeat);
}

void Gladiator::statisticsshort()
{
	cout << " A:" << setw(2)  << getstrength() << "  O:" << setw(2)  << getdefence()
		 << "  Z:" << setw(2) << getagility() << "  C:" << setw(2)  << getcharisma();
}

void Gladiator::dynamicstatistics()
{
	cout << showname() << "  HP: " << gethp() << "  M: " << getmorale();
}

void Gladiator::droppopularity()
{
	popularity -= rand() % 30 + 20;
	if (popularity < 0)
	{
		popularity = 0;
	}
}

void Gladiator::lessmorale()
{
	if (morale > 0) morale--;
}

void Gladiator::addmorale()
{
	if (morale < 12) morale = morale + 1 + charisma/3;
	addpopularity();
}

void Gladiator::start()
{
	cout << "Podaj imię gracza: ";
	setname();
	cout << "Rozdaj statystyki" << endl;
	setstatistics();
}

void Gladiator::getup()
{
	morale = 5;
	Warrior::getup();
}

void Gladiator::clear()
{
	Warrior::clear();
	charisma = 0;
}