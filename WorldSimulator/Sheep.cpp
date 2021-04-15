#include "Sheep.h"
#include <iostream>
#include <vector>



using namespace std;

namespace GameWorld {
	namespace Animal {

		Sheep::Sheep(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 4;
			_initiative = 4;
			_tile = 'S';
			_age = 0;
			_pause = 0;
			_name = "Sheep";


		}

		Sheep::Sheep(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 4;
			_initiative = 4;
			_tile = 'S';
			_age = 0;
			_pause = 1;
			_name = "Sheep";


		}


		Sheep::~Sheep() {

		}
	}
}