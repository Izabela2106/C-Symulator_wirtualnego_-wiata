#include "Organism.h"
#include "GameWorld.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <random>
#include <ctime>
#include "Wolf.h"
#include <vector>
#include "Animal.h";
#include "Plant.h"



using namespace std;





	int  Organism::randomNumberGenerator(int range)  {
		static default_random_engine randomEngine(time(NULL));
		uniform_int_distribution <int> attackRoll(0, range);

		return attackRoll(randomEngine);
	}

	void Organism::action(char** world, vector <Organism*>& organisms, int width, int heigth) {

	}

	void Organism::getPosition(int& x, int& y) {
		x = _x;
		y = _y;

	}

	char Organism::getTile() {
		return _tile;
	}

	int Organism::getAge() {
		return _age;
	}
	void Organism::incAge() {
		_age++;
	}
	int Organism::getStrength() {
		return _strength;
	}
	int Organism::getX() {
		return _x;
	}
	int Organism::getY() {
		return _y;
	}

	void Organism::setPause(int p) {
		_pause = p;
	}
	void Organism::setStrength(int s) {
		_strength += s;
	}

	string Organism::getName() {
		return _name;
	}


	void Organism::move(int targetX, int targetY, char** world) {

	}



	void Organism::multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms) {

	}

	int Organism::getInitiative() {
		return _initiative;
	}

	void Organism::insertOrganism(vector <Organism*>& organisms) {
		if (organisms.size() == 0) {
			organisms.push_back(this);
		}


		else if ((organisms.back())->_initiative >= _initiative) {
			organisms.push_back(this);
		}


		else {
			for (vector<Organism*>::iterator it = organisms.begin(); it != organisms.end(); it++) {

				if (_initiative > (*it)->getInitiative()) {
					organisms.insert(it, this);
					break;
				}

			}

		}

	}


	void Organism::battle(int targetX, int targetY, char** world, vector <Organism*>& organisms) {
		Organism* attackedOrganism = 0;
		vector<Organism*>::iterator position;
		vector<Organism*>::iterator position2;

		for (vector<Organism*>::iterator it = organisms.begin(); it != organisms.end(); it++) {
			if ((*it)->getX() == targetX && (*it)->getY() == targetY) {
				attackedOrganism = *it;
				position = it;
				break;
			}
		}
		if (attackedOrganism != 0) {

			int initiative1 = _initiative;
			int initiative2 = attackedOrganism->getInitiative();
			int strength1 = _strength;
			int strength2 = attackedOrganism->getStrength();
			char attackedTile = attackedOrganism->getTile();
			string name1 = _name;
			string name2 = attackedOrganism->getName();
			if (attackedTile == 'Z' && strength1 < 5) {

			}


			else if (strength1 >= strength2) {
				if (attackedTile == 'r') {
					setStrength(3);
					cout << name1 << " ate Guarana, it's strength is now " << _strength << endl;
				}
				//Atacked organism is dying 
				world[_x][_y] = '.';
				world[targetX][targetY] = _tile;
				_x = targetX;
				_y = targetY;
				organisms.erase(position);

				if (attackedTile == 'b') {
					cout << name1 + " ate deadly berries and died" << endl;
					for (vector<Organism*>::iterator it = organisms.begin(); it != organisms.end(); ++it) {
						if ((*it)->getX() == _x && (*it)->getY() == _y) {
							position = it;
							break;
						}
					}
					organisms.erase(position);
					world[_x][_y] = '.';


				}
				if (attackedTile == 'g') {
					cout << name1 << " ate " << name2 << endl;
				}
				else if (attackedTile == 'b' || attackedTile == 'r') {
					
				}
				else {
					cout << name2 + " was killed by " + name1 << endl;
				}


				if (attackedTile == 'H') {
					_pause = 2;
				}
			}
			else {
				//Atacking organism is dying
				for (vector<Organism*>::iterator it = organisms.begin(); it != organisms.end(); ++it) {
					if ((*it)->getX() == _x && (*it)->getY() == _y) {
						position = it;
						break;
					}
				}
				if (_tile == 'H') {
					attackedOrganism->setPause(2);
				}
				organisms.erase(position);
				world[_x][_y] = '.';

				cout << name1 + " was killed by " + name2 << endl;


			}
		}
	}







	Organism::~Organism() {

	}





