#include "Grass.h"
#include "Organism.h"
#include <iostream>
#include <vector>



using namespace std;


		Grass::Grass(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 0;
			_initiative = 0;
			_tile = 'g';
			_age = 0;
			_pause = 1;
			_probability = 10;
			_name = "Grass";


		}

		Grass::Grass(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 0;
			_initiative = 0;
			_tile = 'g';
			_age = 0;
			_pause = 0;
			_probability = 10;
			_pause = 1;
			_name = "Grass";

		}


		Grass::~Grass() {

		}
