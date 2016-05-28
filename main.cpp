#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"
#include "Functions.h"


// ogarnięcie zwierząt
// zmiana interfejsu użytkownika

int main(int argc, char const *argv[])
{
	srand(argc == 2 
		? atoi(argv[1]) 
		: time(NULL));

	Gladiator *player = new Gladiator;
	Gladiator *enemy = new Gladiator;
	
	enemy -> random();

	cout << "\n\n";
	player -> start();

	fight(player,enemy);

	delete player;
	delete enemy;
	return 0;
}

