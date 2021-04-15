#pragma once
#include "Organism.h"

#include <vector>

namespace GameWorld {
	namespace Animal {

		class Animal :public Organism
		{
		public:
			Animal();
			virtual ~Animal();
			void action(char** world, vector <Organism*>& organisms, int width, int heigth) override;
			void move(int targetX, int targetY, char** world);
			void multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms);
			Animal* createNewAnimal(char tile, int idnexX, int IndexY);
			void processAction(int targetX, int targetY, int _tile, char** world, vector <Organism*>& organisms, int width, int heigth);

		};
		
	}
}
