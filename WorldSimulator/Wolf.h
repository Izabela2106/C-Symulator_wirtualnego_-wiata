#pragma once
#include "Animal.h"
#include <vector>

namespace GameWorld {
	namespace Animal {
		class Wolf :public Animal
		{
		public:
			Wolf(int width, int heigth);
			Wolf(int indexX, int indexY, int z);
			virtual ~Wolf();



		};

	}
}