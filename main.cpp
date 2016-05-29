#include "Warrior.h"
#include "Gladiator.h"
#include "Animal.h"
#include "Functions.h"

int main(int argc, char const *argv[])
{
	srand(argc == 2 
		? atoi(argv[1]) 
		: time(NULL));

	Gladiator *player = new Gladiator;
	Gladiator *enemy = new Gladiator;

	Animal *mytiger = new Animal;
	Animal *enemytiger = new Animal;
	
	enemy -> random();

	cout << "\n\n";
	player -> start();

	fight(player, enemy, mytiger, enemytiger);

	delete player;
	delete enemy;

	delete mytiger;
	delete enemytiger;

	return 0;
}
