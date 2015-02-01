#pragma once
class battle
{
public:
	battle();
	~battle();
	void fight(country attacker, country defender);
	

private:
	int rollDice();
	void battle::rollSort(int firstRoll, int secondRoll, int thirdRoll);
};

