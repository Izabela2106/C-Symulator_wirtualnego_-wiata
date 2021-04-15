#pragma once
#include "Organism.h"



		class Plant : public Organism
		{
		public:
			void action(char** world, vector <Organism*>& organisms, int width, int heigth) override;

			void multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms);
			Plant* createNewPlant(char tile, int targetX, int targetY);
			void move();
			virtual ~Plant();
		protected:
			int _probability;
		};

