#pragma once
#include "Animal.h"
#include <vector>

namespace GameWorld {
	namespace Animal {

		class Sheep :public Animal
		{
		public:
			Sheep(int width, int heigth);
			Sheep(int indexX, int indexY, int z);
			virtual ~Sheep();



		};

	}
}

