#include "Plant.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include "Grass.h"
#include "Organism.h"
#include "Guarana.h"
#include "Berries.h"



		void Plant::action(char** world, vector <Organism*>& organisms, int width, int heigth) {
			incAge();
			if (_pause > 0) {
				_pause--;
			}
			else {
				int probability = _probability;
				int direction = randomNumberGenerator(probability);
				int targetX;
				int targetY;
				int range = 1;
				bool isPlanted = false;
				for (int i = 0; i < 4; i++) {
					if (!isPlanted) {
						switch (direction)
						{
						case 0:
						{//up
							targetX = _x - range;
							targetY = _y;
							if (targetX < 0) {
								direction++;
								break;
							}
							if (world[targetX][targetY] == '.') {
								multiplication(targetX, targetY, width, heigth, world, organisms);
								isPlanted = true;
								break;
							}

							direction++;
							break;
						}


						case 1: {//down
							targetX = _x + range;
							targetY = _y;

							if (targetX >= width) {
								direction++;
								break;
							}
							if (world[targetX][targetY] == '.') {

								multiplication(targetX, targetY, width, heigth, world, organisms);
								isPlanted = true;
								break;
							}
							direction++;
							break;
						}
						case 2: {//left
							targetX = _x;
							targetY = _y - range;
							if (targetY < 0) {
								direction++;
								break;
							}
							if (world[targetX][targetY] == '.')
							{
								multiplication(targetX, targetY, width, heigth, world, organisms);
								isPlanted = true;
								direction++;
							}
							break;
						}
						case 3: { //right
							targetX = _x;
							targetY = _y + range;
							if (targetY >= heigth) {
								direction = 0;
								break;
							}
							if (world[targetX][targetY] == '.') {
								multiplication(targetX, targetY, width, heigth, world, organisms);
								isPlanted = true;
							}
							direction = 0;
							break;
						}
						}
					}
				}
			}

		}




		void Plant::multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms) {
			Plant* newPlant;
			newPlant = createNewPlant(_tile, targetX, targetY);
			newPlant->insertOrganism(organisms);
			world[targetX][targetY] = _tile;
		}


		Plant* Plant::createNewPlant(char tile, int targetX, int targetY) {
			switch (tile)
			{
			case 'g':
				return new Grass(targetX, targetY, 1);
				break;
			case 'r':
				return new Guarana(targetX, targetY, 1);
				break;
			case 'b':
				return new Berries(targetX, targetY, 1);
				break;
			default:
				break;
			}
		}

		void Plant::move() {

		}

		Plant::~Plant() {

		}

