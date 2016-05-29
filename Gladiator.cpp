#include "Gladiator.h"
#include "Colors.h"
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

	cout << "==========================================================================================================================" << endl;
	cout << red << " Atak:" << def << setw(2)  << getstrength()
		 << blue << "  Obrona:" << def << setw(2)  << getdefence()
		 << yellow << "  Zręczność:" << def << setw(2) << getagility()
		 << magenta << "  Charyzma:" << def << setw(2)  << getcharisma() << endl;
	cout << "==========================================================================================================================" << endl;

	while (points--)
	{
		cout << " Co chcesz dodać?: (pozostało:" << setw(2) << red << points + 1 << def << ") " << endl << endl;
		cout << red << " 1.Atak" << endl 
			 << blue << " 2.Obrona" << endl
			 << yellow << " 3.Zręczność" << endl
			 << magenta << " 4.Charyzma" << def << endl << endl;
		cout << black;
		cin >> stat;
		cout << def;
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
		cout << "==========================================================================================================================" << endl;
		cout << red << " Atak:" << def << setw(2)  << getstrength() 
		 	 << blue << "  Obrona:" << def << setw(2)  << getdefence()
		 	 << yellow << "  Zręczność:" << def << setw(2) << getagility() 
		 	 << magenta << "  Charyzma:" << def << setw(2)  << getcharisma() << endl;
		cout << "==========================================================================================================================" << endl;
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
	if (points==0) 
		return 0;

	repeat = rand() % points + 1;
	adddefence(repeat);

	points -= repeat;
	if (points==0) 
		return 0;

	repeat = rand() % points + 1;
	addagility(repeat);

	points -= repeat;
	addcharisma(points);

	return 0;
}

void Gladiator::statisticsshort()
{
	cout << green << showname() << ":";
	cout << red << " Atak:" << def << setw(2)  << getstrength() 
		 << blue << "  Obrona:" << def << setw(2)  << getdefence()
		 << yellow << "  Zręczność:" << def << setw(2) << getagility() 
		 << magenta << "  Charyzma:" << def << setw(2)  << getcharisma();
}

void Gladiator::dynamicstatistics()
{
	cout << green << showname() << red << "  HP:"<< def << setw(2) << gethp()
		 << yellow << "  Morale:" << def << setw(2) << getmorale();
}

void Gladiator::droppopularity()
{
	popularity -= rand() % 40 + 30;
	if (popularity < 0)
		popularity = 0;
}

void Gladiator::lessmorale(int difference)
{
	if (morale > 0 && difference > 2) morale = morale - 1 - difference/3;
	else 
		if (morale > 0) morale--;

	if (morale < 0) 
		morale = 0;
}

void Gladiator::addmorale()
{
	if (morale < 12) 
		morale = morale + 1 + charisma/3;

	if (morale > 12) 
		morale = 12;
	addpopularity();
}

void Gladiator::start()
{
	cout << green << " Podaj imię: " << def;
	setname();
	cout << endl << green << " Rozdaj statystyki" << def << endl;
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

void Gladiator::addpopularity()
{
	if (charisma > 1)
		popularity += 2 * charisma;
	else 
		popularity += 3;

	if (popularity > 100)
		popularity = 100;
}
