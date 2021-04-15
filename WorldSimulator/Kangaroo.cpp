#include "Kangaroo.h"
#include <iostream>
#include <vector>



using namespace std;
namespace GameWorld {
	namespace Animal {

		Kangaroo::Kangaroo(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 9;
			_initiative = 6;
			_tile = 'K';
			_age = 0;
			_pause = 0;
			_name = "Kangaroo";


		}

		Kangaroo::Kangaroo(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 9;
			_initiative = 6;
			_tile = 'K';
			_age = 0;
			_pause = 1;
			_name = "Kangaroo";


		}


		Kangaroo::~Kangaroo() {

		}
	}
}
