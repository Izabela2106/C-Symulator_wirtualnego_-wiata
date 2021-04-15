#pragma once
#include "Plant.h"



		class Berries : public Plant
		{
		public:
			Berries(int width, int heigth);
			Berries(int indexX, int indexY, int z);
			virtual ~Berries();
		};

