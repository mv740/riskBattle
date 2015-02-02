#pragma once
#include "country.h"

class battle
{
public:
	battle();
	~battle();
	void battle::war(country& attacker, country& defender);
	

private:
	int rollDice();
	void sortRolls(int& firstRoll, int& secondRoll);
	void sortRolls(int& firstRoll, int& secondRoll, int& thirdRoll);
	void winner(int DiceUsedbyAttack,country& attacker, country& defender);
	void loser();
	void status(country& attacker, country& defender);
	int fight(country& attacker, country& defender);
	void blitz(country& attacker, country& defender);
	void skirmish(country& attacker, country& defender);
};

