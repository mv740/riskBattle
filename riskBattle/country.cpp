#include "country.h"
#include <string>;

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
string country::getOwner()
{
	return owner;
};
int country::getArmy()
{
	return nbOfArmy;
};

