#pragma once

#include <vector>
#include <string>





using namespace std;




	class Organism
	{
	public:
		int randomNumberGenerator(int range);


		virtual void move(int targetX, int targetY, char** world);
		virtual void multiplication(int targetX, int targetY, int width, int heigth, char** world, vector <Organism*>& organisms);
		virtual void action(char** world, vector <Organism*>& organisms, int width, int heigth);
		void getPosition(int& x, int& y);
		char getTile();
		void incAge();
		int getAge();
		void setStrength(int s);
		int getInitiative();
		int getStrength();
		int getX();
		int getY();
		string getName();
		void setPause(int p);
		void insertOrganism(vector <Organism*>& organisms);
		void battle(int targetX, int targetY, char** world, vector <Organism*>& organisms);


		virtual ~Organism();



	protected:

		int _strength;
		int _initiative;
		int _x;
		int _y;
		int _age;
		char _tile;
		int _pause;
		string _name;

	};




