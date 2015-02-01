#include "battle.h"
#include <stdlib.h>
#include <time.h>
#include "country.h"
#include <stack>

battle::battle()
{
}


battle::~battle()
{
}

int battle::rollDice()
{
	int roll;
	srand(time(NULL));
	roll = (1 + rand() % 6);
	return roll;
}

void battle::rollSort(int firstRoll, int secondRoll, int thirdRoll)
{
	if (thirdRoll > secondRoll)
		swap(thirdRoll, secondRoll);
	if (thirdRoll > firstRoll)
		swap(thirdRoll, firstRoll);
	if (secondRoll, firstRoll)
		swap(secondRoll, firstRoll);

	//firstroll is higher roll 
}

void battle::fight(country attacker, country defender)
{
	int attackPower = attacker.getArmy;
	int defencePower = defender.getArmy;
	
	//dice rolls
	int attack1, attack2, attack3;
	int defence1, defence2;

	//attack roll
	if (attackPower >= 3)
	{
		attack1 = rollDice();
		attack2 = rollDice();
		attack3 = rollDice();
	}
	else if (attackPower == 2)
	{
		attack1 = rollDice();
		attack2 = rollDice();
		attack3 = 0;// will be ignored
	}
	else if (attackPower == 1)
	{
		attack1 = rollDice();
		attack2 = 0;
		attack3 = 0;
	}
	if (defencePower >= 2)
	{
		defence1 = rollDice();
		defence2 = rollDice();
	}
	else if (defencePower == 1)
	{
		defence1 = rollDice();
		defence2 = 0;
	}
	//stack test
	stack<int> attackerRolls;
	stack<int> defenderRolls;
	int aRoll1, aRoll2, aRoll3;
	int dRoll1, dRoll2;


	int nbRollAttack;
	int nbRollDefence;
	if (attackPower >= 3)
		nbRollAttack = 3;
	else if (attackPower == 2)
		nbRollAttack = 2;
	else
		nbRollAttack = 1;
	for (int i = 0; i < nbRollAttack; i++)
	{
		int roll = rollDice();

		//keep the value for output 
		switch (i)
		{
		case 0: aRoll1 = roll;
			break;
		case 1: aRoll2 = roll;
			break;
		case 3: aRoll3 = roll;
			break;
		}

		//sort value in a stack
		if (!attackerRolls.empty)
		{
			int temp = attackerRolls.top;

			if (temp > roll)
			{
				attackerRolls.pop();
				attackerRolls.push(roll);
				attackerRolls.push(temp);
				//top is the highest
			}
			else
			{
				attackerRolls.push(roll);
			}
		}
		else
		{
			attackerRolls.push(rollDice());
		}
	}
	for (int i = 0; i < nbRollDefence; i++)
	{

	}


	//battle
	


	
}