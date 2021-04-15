#include <iostream>
#include "GameWorld.h"
#include "Organism.h"
#include "Animal.h"
#include "Wolf.h"
#include "Plant.h"

using namespace std;

int main() {

	GameWorld::GameWorld gameWorld(20,30);
	for (int i = 0; i < 5; i++) {
		gameWorld.createOrganism('W');
		gameWorld.createOrganism('S');
		gameWorld.createOrganism('H');
		gameWorld.createOrganism('K');
		gameWorld.createOrganism('r');
		gameWorld.createOrganism('T');
		gameWorld.createOrganism('b');
		gameWorld.createOrganism('g');
	}
	gameWorld.displayOrganisms();
	gameWorld.printWorld();

	while(1){
		gameWorld.newRound();
     }
	
	





	

	
	return 0;
}