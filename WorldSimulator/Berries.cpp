#include "Berries.h"
#include "Organism.h"
#include <iostream>
#include <vector>



using namespace std;



		Berries::Berries(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 0;
			_initiative = 0;
			_tile = 'b';
			_age = 0;
			_pause = 1;
			_probability = 15;
			_name = "Deadly Berries";


		}

		Berries::Berries(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 0;
			_initiative = 0;
			_tile = 'b';
			_age = 0;
			_pause = 0;
			_probability = 15;
			_pause = 1;
			_name = "Deadly Berries";

		}


		Berries::~Berries() {

		}


