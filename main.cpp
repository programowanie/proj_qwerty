#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"

using namespace std;

int skillchoice ();
void fight(Gladiator * player, Gladiator * enemy);
void skill(int pchoice, int echoice, Gladiator * player, Gladiator * enemy);
float attack(int strength, int morale, int defence, bool skill);

int main(int argc, char const *argv[])
{
	srand(argc == 2 
		? atoi(argv[1]) 
		: time(NULL));

	Gladiator *player = new Gladiator;
	Gladiator *enemy = new Gladiator;
	enemy->random();
	player->start();

	fight(player,enemy);

	delete player;
	delete enemy;
	return 0;
}

int skillchoice()
{
	int choice;
	cout << "Jakiej umiejętności chcesz użyć?" << endl;
	cout << "1.Atak 2.Blok 3.Krzyk" << endl;
	cin >> choice;
	return choice;
}

void fight(Gladiator * player, Gladiator * enemy)
{
	while(42)
	{
		int anotherchance = 0;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "===============\nPOZIOM WALKI: " << enemy->getlevel() << endl;
		cout << "===========================================================================================================" << endl;
		cout << "Statystyki " << player->showname() << ":" ; player->statisticsshort(); 
		cout << "   <|>   Statystyki " << enemy->showname() << ":" ; enemy->statisticsshort(); cout << endl; 
		while(1)
		{ 
			cout << endl << "===========================================================================================================" << endl;
			player->dynamicstatistics(); cout << "  P: "<< player->getpopularity() << "   <|>   "; 
			enemy->dynamicstatistics(); cout << endl;
			cout << "===========================================================================================================" << endl;
			int pchoice = skillchoice(), echoice = random() % 3 + 1;
			skill(pchoice, echoice, player, enemy);
			if (player->gethp()<1)
			{

				anotherchance = random() % 100 +1;
				if (anotherchance < player->getpopularity())
				{
					cout << "Przegrałeś walkę.\nJednak cesarz postanawia Cię ocalić!" << endl;
					player->droppopularity();
				}
				else 
				{
					cout << "===============\nZginąłeś..." << endl;
					exit(0);
				}
				break;
			}
			if (enemy->gethp()<1)
			{
				cout << "===============\nWygrałeś walkę!" << endl;
				break;
			}
		}
		cout << "[enter by kontynuować]" << endl;
		getchar();
		getchar();
		if (anotherchance == 0)
		{
			if (enemy->getlevel() == 5)
			{
				exit(0);
			}
			enemy->levelup();
			cout << "Otrzymujesz 10 punktów do rozdania." << endl;
			player->setstatistics();

		}
		enemy->random();
		enemy->getup();
		player->getup();
	}
}

void skill(int pchoice, int echoice, Gladiator * player, Gladiator * enemy)
{
	int mode = pchoice + echoice;

	switch(mode)
	{
		case 2:
		{
			cout << "Obaj gladiatorzy używają ataku!" << endl;
			if (player->getagility()>=enemy->getagility())
			{
				enemy->losehp(attack(player->getstrength(), player->getmorale(), enemy->getdefence(), 0));
				if (enemy->gethp()<1) break;
				player->losehp(attack(enemy->getstrength(), enemy->getmorale(), player->getdefence(), 0));
			}
			else
			{
				player->losehp(attack(enemy->getstrength(), enemy->getmorale(), player->getdefence(), 0));
				if (player->gethp()<1) break;			
				enemy->losehp(attack(player->getstrength(), player->getmorale(), enemy->getdefence(), 0));
			}
			break;
		}
		case 3:
		{
			if (pchoice == 1)
			{
				cout << "Używasz ataku, a Twój przeciwnik bloku!" << endl;
				enemy->losehp(attack(player->getstrength(), player->getmorale(), enemy->getdefence(), 1));
			}
			else 
			{
				cout << "Używasz bloku, a Twój przeciwnik ataku!" << endl;
				player->losehp(attack(enemy->getstrength(), enemy->getmorale(), player->getdefence(), 1));
			}
			break;
		}
		case 4:
		{
			if (pchoice == echoice)
			{
				cout << "Obaj gladiatorzy użwają bloku!" << endl;
				break;
			}
			else
			{
				if (pchoice == 1) 
				{	
					cout << "Używasz ataku, a Twój przeciwnik krzyku!" << endl;
					enemy->losehp(attack(player->getstrength(), player->getmorale(), enemy->getdefence(), 0));
					enemy->addmorale();
					player->lessmorale();
				}
				else
				{
					cout << "Używasz krzyku, a Twój przeciwnik ataku!" << endl;
					player->losehp(attack(enemy->getstrength(), enemy->getmorale(), player->getdefence(), 0));
					player->addmorale();
					enemy->lessmorale();
				}
			}
			break;
		}
		case 5:
		{
			if (pchoice == 3)
			{
				cout << "Używasz krzyku, a Twój przeciwnik bloku!" << endl;
				player->addmorale();
				enemy->lessmorale();
			}
			else
			{
				cout << "Używasz bloku, a Twój przeciwnik krzyku!" << endl;
				enemy->addmorale();
				player->lessmorale();
			}
			break;
		}
		case 6:
		{
			cout << "Obaj gladiatorzy używają krzyku!" << endl;
			player->addmorale();
			enemy->addmorale();
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
			attack = (1.2*strength)/defence;
		}
		else
		{
			attack = (2*strength)/defence;
		}
	}	
	else
	{
		if (skill)
		{
			attack = (1.2*strength);
		}
		else
		{
			attack = (2*strength);
		}
	}
	attack = attack * morale/7;
	if (attack < 1) attack = 1; 
	return attack;
}