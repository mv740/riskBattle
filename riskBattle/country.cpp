#include "country.h"
#include <iostream>
using namespace std;

using namespace std;

country::country()
{
	
};

country::~country()
{
};

country::country(string Name, string Owner, int NbOfArmy)
{
	name = Name;
	owner = Owner;
	nbOfArmy = NbOfArmy;
};
string country::getName()
{
	return name;
};
void country::setOwner(string newOwner)
{
	owner = newOwner;
};

string country::getOwner()
{
	return owner;
};
void country::setArmy(int newArmy)
{
	nbOfArmy = newArmy;
}
int country::getArmy()
{
	return nbOfArmy;
};

