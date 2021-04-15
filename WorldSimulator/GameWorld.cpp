#include "GameWorld.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "Wolf.h"
#include "Organism.h"
#include <vector>
#include "Sheep.h"
#include "Turtle.h"
#include "Hedgehog.h"
#include "Kangaroo.h"
#include "Plant.h"
#include "Grass.h"
#include "Guarana.h"
#include "Berries.h"
#include "Animal.h"




using namespace std;



namespace GameWorld {


	GameWorld::GameWorld() {
		_width = 20;
		_heigth = 20;

		_world = new char* [_width];
		for (int i = 0; i < _width; i++) {
			_world[i] = new char[_heigth];
		}
		init(_width, _heigth);
		_organisms.reserve(_width * _heigth);
		roundCount = 0;

	}


	GameWorld::GameWorld(int width, int height) {
		_width = width;
		_heigth = height;
		_world = new char* [_width];
		for (int i = 0; i < _width; i++) {
			_world[i] = new char[_heigth];
		}
		init(_width, _heigth);
		_organisms.reserve(_width * _heigth);
		roundCount = 0;

	}


	void GameWorld::init(int width, int heigth) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < heigth; j++) {
				_world[i][j] = '.';
			}
		}


	}




	void GameWorld::getSize(int width, int heigth) {
		width = _width;
		heigth = _heigth;
	}



	void GameWorld::printWorld() {
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _heigth; j++) {
				cout << _world[i][j];
			}
			cout << endl;
		}
	}

	int GameWorld::randomNumberGenerator(int range) {
		static default_random_engine randomEngine(time(NULL));
		uniform_int_distribution <int> attackRoll(0, range);

		return attackRoll(randomEngine);
	}


	void GameWorld::action() {
		for (size_t i = 0; i < _organisms.size(); i++) {

			_organisms[i]->action(_world, _organisms, _width, _heigth);
		}

	}


	void GameWorld::createOrganism(char tile) {

		switch (tile)
		{
			Organism* newOrganism;
		case 'W': {

			newOrganism = new Animal::Wolf(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'S': {

			newOrganism = new Animal::Sheep(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'T': {
			newOrganism = new Animal::Turtle(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'H': {
			newOrganism = new Animal::Hedgehog(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'K': {
			newOrganism = new Animal::Kangaroo(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'g': {
			newOrganism = new Grass(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'r': {
			newOrganism = new Guarana(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		case 'b': {
			newOrganism = new Berries(_width, _heigth);
			newOrganism->insertOrganism(_organisms);
			break;
		}
		default:
			break;
		}
	}

	char** GameWorld::getWorld() {
		return _world;
	}

	void GameWorld::displayOrganisms() {

		int organismX = 0;
		int organismY = 0;
		for (size_t i = 0; i < _organisms.size(); i++) {
			_organisms[i]->getPosition(organismX, organismY);
			_world[organismX][organismY] = _organisms[i]->getTile();
		}
	}

	


	void GameWorld::newRound() {
		system("cls");
		cout << "Izabela Nowak 159970" << endl;
		cout << "Round: " << roundCount << endl;
		action();
		printWorld();
		cout << endl;
		roundCount++;
		system("PAUSE");
	}

	GameWorld::~GameWorld() {
		for (int i = 0; i < _organisms.size(); i++) {
			delete _organisms[i];
		}
	}

}