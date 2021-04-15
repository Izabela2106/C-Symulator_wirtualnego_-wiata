#include "Hedgehog.h"
#include <iostream>
#include <vector>



using namespace std;
namespace GameWorld {
	namespace Animal {

		Hedgehog::Hedgehog(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 2;
			_initiative = 1;
			_tile = 'H';
			_age = 0;
			_name = "Hedgehog";




		}

		Hedgehog::Hedgehog(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 2;
			_initiative = 1;
			_tile = 'H';
			_age = 0;
			_pause = 1;
			_name = "Hedgehog";


		}


		Hedgehog::~Hedgehog() {

		}
	}
}