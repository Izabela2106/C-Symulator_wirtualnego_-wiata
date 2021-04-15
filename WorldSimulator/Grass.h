#pragma once
#include "Plant.h"
#include <vector>


		class Grass :public Plant
		{
		public:
			Grass(int width, int heigth);
			Grass(int indexX, int indexY, int z);
			virtual ~Grass();

		};

