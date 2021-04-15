#pragma once
#include "Animal.h"

namespace GameWorld {
	namespace Animal {

		class Turtle : public Animal {

		public:
			Turtle(int width, int heigth);
			Turtle(int indexX, int indexY, int z);
			virtual ~Turtle();

			void move(int targetX, int targetY, char** world);

		};

	}
}