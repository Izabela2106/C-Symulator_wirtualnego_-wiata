#include "Animal.h"
#include <iostream>
#include <vector>
#include "Wolf.h"
#include "Sheep.h"
#include "Turtle.h"
#include "Hedgehog.h"
#include "Kangaroo.h"
#include "Organism.h"



using namespace std;
namespace GameWorld {
	namespace Animal {

		Animal::Animal() {
		}

		void Animal::action(char** world, vector <Organism*>& organisms, int width, int heigth) {
			incAge();
			if (_pause > 0) {
				_pause--;
			}
			else {
				int direction = randomNumberGenerator(3);
				int targetX;
				int targetY;
				int range = 1;
				if (_tile == 'K') {
					range = 2;
				}

				switch (direction)
				{
				case 0:  //up
					targetX = _x - range;
					targetY = _y;
					if (targetX < 0) {
						break;
					}
					processAction(targetX, targetY, _tile, world, organisms, width, heigth);
					break;

				case 1: //down
					targetX = _x + range;
					targetY = _y;

					if (targetX >= width) {
						break;
					}
					processAction(targetX, targetY, _tile, world, organisms, width, heigth);
					break;

				case 2: //left
					targetX = _x;
					targetY = _y - range;
					if (targetY < 0) {
						break;
					}
					processAction(targetX, targetY, _tile, world, organisms, width, heigth);
					break;
				case 3:  //right
					targetX = _x;
					targetY = _y + range;
					if (targetY >= heigth) {
						break;
					}
					processAction(targetX, targetY, _tile, world, organisms, width, heigth);
					break;
				}
			}
		}


		void Animal::processAction(int targetX, int targetY, int _tile, char** world, vector <Organism*>& organisms, int width, int heigth) {
			if (world[targetX][targetY] == '.') {
				move(targetX, targetY, world);
			}
			else if (world[targetX][targetY] == _tile) {
				multiplication(targetX, targetY, width, heigth, world, organisms);
			}
			else {
				battle(targetX, targetY, world, organisms);
			}
		}






		void Animal::move(int targetX, int targetY, char** world) {
			int x = _x;
			int y = _y;

			_x = targetX;
			_y = targetY;
			world[_x][_y] = _tile;
			world[x][y] = '.';
		}

		void Animal::multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms) {
			bool settled = false;
			int placeToSettle = randomNumberGenerator(7);
			Animal* newAnimal;
			for (int i = 0; i < 8; i++) {
				if (settled == false) {
					switch (placeToSettle) {
					case 0: {
						if (_x - 1 < 0) {
							placeToSettle++;
							break;
						}
						if (world[_x - 1][_y] == '.') {
							newAnimal = createNewAnimal(_tile, _x - 1, _y);
							world[_x - 1][_y] = _tile;
							newAnimal->insertOrganism(organisms);
							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 1: {
						if (_y - 1 < 0) {
							placeToSettle++;
							break;
						}
						if (world[_x][_y - 1] == '.') {
							newAnimal = createNewAnimal(_tile, _x, _y - 1);
							world[_x][_y - 1] = _tile;
							newAnimal->insertOrganism(organisms);
							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 2: {
						if (_x + 1 >= width) {
							placeToSettle++;

							break;
						}

						if (world[_x + 1][_y] == '.') {
							newAnimal = createNewAnimal(_tile, _x + 1, _y);
							world[_x + 1][_y] = _tile;
							newAnimal->insertOrganism(organisms);
							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 3: {
						if (_y + 1 >= heigth) {
							placeToSettle++;

							break;
						}
						if (world[_x][_y + 1] == '.') {
							newAnimal = createNewAnimal(_tile, _x, _y + 1);
							world[_x][_y + 1] = _tile;

							newAnimal->insertOrganism(organisms);


							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 4: {
						if (targetX - 1 < 0) {
							placeToSettle++;

							break;
						}
						if (world[targetX - 1][targetY] == '.') {
							newAnimal = createNewAnimal(_tile, targetX - 1, targetY);
							world[targetX - 1][targetY] = _tile;

							newAnimal->insertOrganism(organisms);

							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 5: {
						if (targetY - 1 < 0) {
							placeToSettle++;

							break;
						}
						if (world[targetX][targetY - 1] == '.') {
							newAnimal = createNewAnimal(_tile, targetX, targetY - 1);
							world[targetX][targetY - 1] = _tile;

							newAnimal->insertOrganism(organisms);

							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 6: {
						if (targetX + 1 >= width) {
							placeToSettle++;

							break;
						}
						if (world[targetX + 1][targetY] == '.') {
							newAnimal = createNewAnimal(_tile, targetX + 1, targetY);
							world[targetX + 1][targetY] = _tile;

							newAnimal->insertOrganism(organisms);

							settled = true;
							break;
						}
						else {
							placeToSettle++;
							break;
						}
					}
					case 7: {
						if (targetY + 1 >= heigth) {
							placeToSettle = 0;

							break;
						}
						if (world[targetX][targetY + 1] == '.') {
							newAnimal = createNewAnimal(_tile, targetX, targetY + 1);
							world[targetX][targetY + 1] = _tile;
							newAnimal->insertOrganism(organisms);

							settled = true;
							break;
						}
						else {
							placeToSettle = 0;
							break;
						}
					}
					}
				}

			}


		}




		Animal* Animal::createNewAnimal(char tile, int indexX, int indexY) {
			switch (tile)
			{
			case 'W':
				return new Wolf(indexX, indexY, 1);
				break;
			case 'S':
				return new Sheep(indexX, indexY, 1);
				break;
			case 'T':
				return new Turtle(indexX, indexY, 1);
				break;
			case 'H':
				return new Hedgehog(indexX, indexY, 1);
				break;
			case 'K':
				return new Kangaroo(indexX, indexY, 1);
				break;
			default:
				break;
			}
		}





		Animal::~Animal() {

		}
	}
}