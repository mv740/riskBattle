#pragma once
class country
{
public:
	country();
	~country();
	country(string name1, string owner, int nbOfArmy);
	string getName();
	string getOwner();
	int getArmy();

private:
	string name;
	string owner;
	int nbOfArmy;

};
