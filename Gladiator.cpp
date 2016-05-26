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
	while (points--)
	{
		cout << "Pozostało do rozdania: " << points + 1 << endl;
		cout << "Co chcesz dodać?:\n1.Atak\n2.Obrona\n3.Zręczność\n4.Charyzma\n";
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
	} 
}

int Gladiator::random()
{
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
	popularity -= rand() % 50 + 1;
	if (popularity < 0)
	{
		popularity = 0;
	}
}

void Gladiator::lessmorale()
{
	if (morale > 1) morale--;
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