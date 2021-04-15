#pragma once
#include "Animal.h"

namespace GameWorld {
	namespace Animal {
		class Hedgehog :public Animal
		{
		public:
			Hedgehog(int width, int heigth);
			Hedgehog(int indexX, int indexY, int z);
			virtual ~Hedgehog();


		};

	}
}

