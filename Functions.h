#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <ncurses.h>
#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"
#include "Colors.h"

using namespace std;

int   skillchoice ();
void  fight	(Gladiator * player, Gladiator * enemy);
void  skill (int pchoice, int echoice, Gladiator * player, Gladiator * enemy);
float attack(int strength, int morale, int defence, bool skill);

int skillchoice()
{
	int choice;
	cout << cyan << " Jakiej umiejętności chcesz użyć?" << endl;
	cout << " 1.Atak 2.Blok 3.Krzyk" << black << endl;
	cin >> choice;
	cout << def;
	return choice;
}

void fight(Gladiator * player, Gladiator * enemy)
{
	while(42)
	{
		int anotherchance = 0;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "===============\n" << green << "POZIOM WALKI: " << def << enemy -> getlevel() << def << endl;

		cout << "==========================================================================================================================" << endl;
		player -> statisticsshort(); 
		cout << "   <| VS |>  ";
		enemy -> statisticsshort(); cout << endl; 
		cout << "==========================================================================================================================" << endl;

		cout << "[by rozpocząć walkę wcniśnij enter]";
		getchar();
		getchar();

		while(1)
		{ 
			cout << endl << "===========================================================================================================" << endl;
			player -> dynamicstatistics(); cout << blue << "  Popularność:"<< def << setw(2) << player -> getpopularity() << "   <|>   "; 
			enemy -> dynamicstatistics(); cout << endl;
			cout << "===========================================================================================================" << endl;

			int pchoice = skillchoice(), echoice = random() % 3 + 1;
			skill(pchoice, echoice, player, enemy);

			if (player -> gethp()<1)
			{

				anotherchance = random() % 100 +1;
				if (anotherchance < player -> getpopularity())
				{
					cout << red << endl << " Przegrałeś walkę." << endl 
						 << green << " Jednak cesarz postanawia Cię ocalić!" << def << endl << endl;
					player -> droppopularity();
				}
				else 
				{
					cout << "===========================================================================================================" << endl;
					cout << red << "Zginąłeś..." << def << endl;
					exit(0);
				}
				break;
			}
			if (enemy -> gethp()<1)
			{
				cout << "===========================================================================================================" << endl;
				cout << green << " Wygrałeś walkę!" << def << endl;
				break;
			}
		}

		cout << "[enter by kontynuować]" << endl;
		getchar();
		getchar();

		if (anotherchance == 0)
		{
			if (enemy -> getlevel() == 5)
			{
				cout << green << " Udało Ci się wywalczyć wolność :)" << def << endl << endl;
				exit(0);
			}
			enemy -> levelup();
			player -> levelup();
			cout << red << " Otrzymujesz 10 punktów do rozdania." << def << endl;
			player -> setstatistics();

		}
		enemy -> random();
		enemy -> getup();
		player -> getup();
	}
}

void skill(int pchoice, int echoice, Gladiator * player, Gladiator * enemy)
{
	int mode = pchoice + echoice;

	switch(mode)
	{
		case 2:
		{
			cout << " Obaj gladiatorzy używają ataku!" << endl;
			if (player -> getagility() >= enemy -> getagility())
			{
				enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0));
				if (enemy -> gethp()<1) break;
				player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0));
			}
			else
			{
				player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0));
				if (player -> gethp()<1) break;			
				enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0));
			}
			break;
		}
		case 3:
		{
			if (pchoice == 1)
			{
				cout << " Używasz ataku, a Twój przeciwnik bloku!" << endl;
				enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 1));
			}
			else 
			{
				cout << " Używasz bloku, a Twój przeciwnik ataku!" << endl;
				player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 1));
			}
			break;
		}
		case 4:
		{
			if (pchoice == echoice)
			{
				cout << " Obaj gladiatorzy użwają bloku!" << endl;
				break;
			}
			else
			{
				if (pchoice == 1) 
				{	
					cout << " Używasz ataku, a Twój przeciwnik krzyku!" << endl;
					enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0));
					enemy -> addmorale();
					player -> lessmorale(enemy -> getcharisma() - player -> getcharisma());
				}
				else
				{
					cout << " Używasz krzyku, a Twój przeciwnik ataku!" << endl;
					player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0));
					player -> addmorale();
					enemy -> lessmorale(player -> getcharisma() - enemy -> getcharisma());
				}
			}
			break;
		}
		case 5:
		{
			if (pchoice == 3)
			{
				cout << " Używasz krzyku, a Twój przeciwnik bloku!" << endl;
				player -> addmorale();
				enemy -> lessmorale(player -> getcharisma() - enemy -> getcharisma());
			}
			else
			{
				cout << " Używasz bloku, a Twój przeciwnik krzyku!" << endl;
				enemy -> addmorale();
				player -> lessmorale(enemy -> getcharisma() - player -> getcharisma());
			}
			break;
		}
		case 6:
		{
			cout << " Obaj gladiatorzy używają krzyku!" << endl;
			player -> addmorale();
			enemy -> addmorale();
			break;
		}
	}
}

float attack(int strength, int morale, int defence, bool skill)
{
	float attack = 1;

	if (defence)
	{
		if (skill)
		{
			attack = 0.8 * strength / defence;
		}
		else
		{
			attack = 2.2 * strength / defence;
		}
	}	
	else
	{
		if (skill)
		{
			attack = 0.8 * strength;
		}
		else
		{
			attack = 2.2 * strength;
		}
	}

	attack = attack * morale/7;
	if (attack < 1) attack = 1; 
	return attack;
}
