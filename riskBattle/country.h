#pragma once
#include <iostream>
using namespace std;
class country
{
public:
	country();
	~country();
	country(string name1, string owner, int nbOfArmy);
	string getName();
	string getOwner();
	int getArmy();

	void setOwner(string newOwner);
	void setArmy(int newArmy);

private:
	string name;
	string owner;
	int nbOfArmy;

};
