#pragma once
#include "Animal.h"

namespace GameWorld {
	namespace Animal {
		class Kangaroo :public Animal
		{
		public:
			Kangaroo(int width, int heigth);
			Kangaroo(int indexX, int indexY, int z);
			virtual ~Kangaroo();


		};

	}
}