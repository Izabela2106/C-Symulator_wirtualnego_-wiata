#include "Turtle.h"
#include"Animal.h"

#include <iostream>
#include <vector>



using namespace std;

namespace GameWorld {
	namespace Animal {

		Turtle::Turtle(int width, int height) {

			_x = randomNumberGenerator(width - 1);
			_y = randomNumberGenerator(height - 1);
			_strength = 2;
			_initiative = 1;
			_tile = 'T';
			_age = 0;
			_pause = 0;
			_name = "Turtle";

		}

		Turtle::Turtle(int indexX, int indexY, int z) {

			_x = indexX;
			_y = indexY;
			_strength = 2;
			_initiative = 1;
			_tile = 'T';
			_age = 0;
			_pause = 1;
			_name = "Turtle";


		}


		void Turtle::move(int targetX, int targetY, char** world) {
			int ifmov = randomNumberGenerator(3);

			if (ifmov > 2) {


				int x = _x;
				int y = _y;

				_x = targetX;
				_y = targetY;
				world[_x][_y] = _tile;
				world[x][y] = '.';
			}
		}


		Turtle::~Turtle() {

		}
	}
}