#include "Wolf.h"
#include <iostream>
#include <vector>



using namespace std;

namespace GameWorld {
	namespace Animal {

		Wolf::Wolf(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 9;
			_initiative = 5;
			_tile = 'W';
			_age = 0;
			_pause = 0;
			_name = "Wolf";

		}

		Wolf::Wolf(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 9;
			_initiative = 5;
			_tile = 'W';
			_age = 0;
			_pause = 1;
			_name = "Wolf";

		}


		Wolf::~Wolf() {

		}

	}
}