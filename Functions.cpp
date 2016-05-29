#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"
#include "Colors.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int skillchoice()
{
	int choice;
	cout << cyan << " Jakiej umiejętności chcesz użyć?" << endl;
	cout << " 1.Atak 2.Blok 3.Krzyk" << black << endl;
	cin >> choice;
	cout << def;
	return choice;
}

void fight(Gladiator * player, Gladiator * enemy, Animal * mytiger, Animal * enemytiger)
{
	while(42)
	{
		int anotherchance = 0,
			animalfightchance = 0,
			oneperbattle;
		oneperbattle = 1;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "===============\n" << green << " POZIOM WALKI: " << def << enemy -> getlevel() << def << endl;

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
			animalfightchance = rand() % 100 + 1;
			if (animalfightchance > 92 && oneperbattle)
			{
				oneperbattle = 0;

				cout << red << "==========================================================================================================================" << endl
					 << " UWAGA!!! NA ARENE WPUSZCZONO ZWIERZĘTA! BROŃ SIĘ!" << def << endl;

				mytiger -> random(player -> getlevel());
				enemytiger -> random(enemy -> getlevel());

				fight(player, mytiger);
				fightbehind(enemy, enemytiger);
			}

			if (enemy -> gethp()<1)
			{
				cout << "==========================================================================================================================" << endl;
				cout << green << " Wygrałeś walkę!" << def << endl;
				break;
			}

			cout << endl << "==========================================================================================================================" << endl;
			player -> dynamicstatistics(); cout << blue << "  Popularność:"<< def << setw(2) << player -> getpopularity() << "   <|>   "; 
			enemy -> dynamicstatistics(); cout << endl;
			cout << "==========================================================================================================================" << endl;

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
					cout << "==========================================================================================================================" << endl;
					cout << red << "Zginąłeś..." << def << endl;
					exit(0);
				}
				break;
			}
			if (enemy -> gethp()<1)
			{
				cout << " " << green << enemy -> showname() << def << " zginął." << endl;
				cout << "==========================================================================================================================" << endl;
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


void fight(Gladiator * player, Animal * mytiger)
{
	cout << "==========================================================================================================================" << endl;
	player -> statisticsshort(); 
	cout << "   <| VS |>  ";
	mytiger -> statisticsshort(); cout << endl; 
	cout << "==========================================================================================================================" << endl;

	while(1)
	{ 
		cout << endl << "===========================================================================================================" << endl;
		player -> dynamicstatistics(); 
		cout << "   <|>   "; 
		mytiger -> dynamicstatistics(); cout << endl;
		cout << "===========================================================================================================" << endl;

		int pchoice = skillchoice(), tchoice = random() % 3 + 1;
		skill(pchoice, tchoice, player, mytiger);

		if (player -> gethp()<1)
		{
				cout << "===========================================================================================================" << endl;
				cout << red << "Zginąłeś..." << def << endl;
				exit(0);
		}

		if (mytiger -> gethp()<1)
		{
			cout << " " << green << mytiger -> showname() << def << " zginął." << endl;
			cout << "===========================================================================================================" << endl;
			break;
		}
	}
	mytiger -> clear();
}

void fightbehind(Gladiator * enemy, Animal * enemytiger)
{
	while(1)
	{ 
		int echoice = random() % 3 + 1, tchoice = random() % 3 + 1;

		switch(echoice + tchoice)
		{
			case 2:
			{	
				enemy -> losehp(attack(enemytiger -> getstrength(), enemytiger -> getanger(), enemy -> getdefence(), 0));
				if (enemy -> gethp()<1) 
					break;			
				enemytiger -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), enemytiger -> getdefence(), 0));
				break;
			}
			case 3:
			{
				if (echoice == 1)
					enemytiger -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), enemytiger -> getdefence(), 1));
				else 
					enemy -> losehp(attack(enemytiger -> getstrength(), enemytiger -> getanger(), enemy -> getdefence(), 1));
				break;
			}
			case 4:
			{
				if (echoice == tchoice)
					break;
				else
				{
					if (echoice == 1) 
					{	
						enemytiger -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), enemytiger -> getdefence(), 0)); 
						enemy -> lessmorale(2);
					}
					else
					{
						enemy -> losehp(attack(enemytiger -> getstrength(), enemytiger -> getanger(), enemy -> getdefence(), 0));
						enemy -> addmorale();
						enemytiger -> addanger();
					}
				}
				break;
			}
			case 5:
			{
				if (echoice == 3)
				{
					enemy -> addmorale();
					enemytiger -> addanger();
				}
				else
					enemy -> lessmorale(2);
				break;
			}
			case 6:
			{
				enemy -> addmorale();
				enemytiger -> addanger();
				break;
			}
		}	

		if (enemy -> gethp()<1)
		{
				cout << green << " Przeciwnik zginął w walce z tygrysem." << def << endl;
				break;
		}
			
		if (enemytiger -> gethp()<1)
		{
			cout << red << " Przecinwik pokonał zwierze! Wracacie do walki ze sobą!" << def << endl;
			break;
		}
	}
	enemytiger -> clear();
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
				cout << " " << green << enemy -> showname() << def << " traci " 
					 << enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0)) 
					 << " hp." << endl;
				if (enemy -> gethp()<1) 
					break;
				cout << " " << green << player -> showname() << def << " traci "
					 << player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0))
					 << " hp." << endl;
			}
			else
			{
				cout << " " << green << player -> showname() << def << " traci "
					 << player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0))
					 << " hp." << endl;
				if (player -> gethp()<1) 
					break;			
				cout << " " << green << enemy -> showname() << def << " traci " 
					 << enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0)) 
				 	 << " hp." << endl;
			}
			break;
		}
		case 3:
		{
			if (pchoice == 1)
			{
				cout << " Używasz ataku, a Twój przeciwnik bloku!" << endl;
				cout << " " << green << enemy -> showname() << def << " traci "
					 << enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 1))
					 << " hp." << endl;
			}
			else 
			{
				cout << " Używasz bloku, a Twój przeciwnik ataku!" << endl;
				cout << " " << green << player -> showname() << def << " traci "
					 << player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 1))
					 << " hp." << endl;
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
					cout << " " << green << enemy -> showname() << def << " traci " 
						 << enemy -> losehp(attack(player -> getstrength(), player -> getmorale(), enemy -> getdefence(), 0)) 
						 << " hp." << endl;
					enemy -> addmorale();
					player -> lessmorale(enemy -> getcharisma() - player -> getcharisma());
				}
				else
				{
					cout << " Używasz krzyku, a Twój przeciwnik ataku!" << endl;
					cout << " " << green << player -> showname() << def << " traci "
					 	 << player -> losehp(attack(enemy -> getstrength(), enemy -> getmorale(), player -> getdefence(), 0))
					 	 << " hp." << endl;
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

void skill(int pchoice, int tchoice, Gladiator * player, Animal * mytiger)
{
	int mode = pchoice + tchoice;

	switch(mode)
	{
		case 2:
		{
			cout << " Zwierze naciera na gladiatora, a on odpowiada tym samym!" << endl;
			cout << " " << green << player -> showname() << def << " traci "
				 << player -> losehp(attack(mytiger -> getstrength(), mytiger -> getanger(), player -> getdefence(), 0))
				 << " hp." << endl;
			if (player -> gethp()<1) break;			
				cout << " " << green << mytiger -> showname() << def << " traci " 
					 << mytiger -> losehp(attack(player -> getstrength(), player -> getmorale(), mytiger -> getdefence(), 0)) 
					 << " hp." << endl;
			break;
		}
		case 3:
		{
			if (pchoice == 1)
			{
				cout << " Gladiator używa ataku, a zwierze robi unik!" << endl;
				cout << " " << green << mytiger -> showname() << def << " traci " 
					 << mytiger -> losehp(attack(player -> getstrength(), player -> getmorale(), mytiger -> getdefence(), 1)) 
					 << " hp." << endl;
			}
			else 
			{
				cout << " Zwierze naciera, a gladiator próbuje się bronić!" << endl;
				cout << " " << green << player -> showname() << def << " traci "
					 << player -> losehp(attack(mytiger -> getstrength(), mytiger -> getanger(), player -> getdefence(), 1))
					 << " hp." << endl;
			}
			break;
		}
		case 4:
		{
			if (pchoice == tchoice)
			{
				cout << " Zwierzę i gladiator utrzymują dystans między sobą." << endl;
				break;
			}
			else
			{
				if (pchoice == 1) 
				{	
					cout << " Używasz ataku, a tygrys ryku!" << endl;
					cout << " " << green << mytiger -> showname() << def << " traci " 
						 << mytiger -> losehp(attack(player -> getstrength(), player -> getmorale(), mytiger -> getdefence(), 0)) 
						 << " hp." << endl;
					player -> lessmorale(2);
				}
				else
				{
					cout << " Używasz krzyku, a zwierze naciera!" << endl;
					cout << " " << green << player -> showname() << def << " traci "
					 	 << player -> losehp(attack(mytiger -> getstrength(), mytiger -> getanger(), player -> getdefence(), 0))
					 	 << " hp." << endl;
					player -> addmorale();
					mytiger -> addanger();
				}
			}
			break;
		}
		case 5:
		{
			if (pchoice == 3)
			{
				cout << " Używasz krzyku, zwierze zachowuje się pasywnie." << endl;
				player -> addmorale();
				mytiger -> addanger();
			}
			else
			{
				cout << " Używasz bloku, a zwierze ryku!" << endl;
				player -> lessmorale(2);
			}
			break;
		}
		case 6:
		{
			cout << " Używasz krzyku, zwierze odpowiada rykiem!" << endl;
			player -> addmorale();
			mytiger -> addanger();
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
			attack = 0.8 * strength / defence;
		else
			attack = 2.2 * strength / defence;
	}	
	else
	{
		if (skill)
			attack = 0.8 * strength;
		else
			attack = 2.2 * strength;
	}

	attack = attack * morale/7;
	if (attack < 1) attack = 1; 
	return attack;
}
