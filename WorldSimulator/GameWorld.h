#pragma once
#include <vector>
#include <iostream>
#include "Organism.h"





using namespace std;

namespace GameWorld {

	class GameWorld
	{
	public:
		GameWorld(int widht, int height);     
		GameWorld();
		~GameWorld();
		void printWorld();
		void action();
		void init(int i, int j);
		void getSize(int width, int heigth);
		char** getWorld();
		void createOrganism(char tile);
		void displayOrganisms();
		void newRound();

		static int randomNumberGenerator(int range);




	private:
		vector <Organism*> _organisms;
		int _width = 20;
		int _heigth = 20;
		char** _world;
		int roundCount;


	};

}

