#include "battle.h"
#include <stdlib.h>
#include <time.h>
#include "country.h"
#include <stack>
#include <string>

battle::battle()
{
}


battle::~battle()
{
}

int battle::rollDice()
{
	//srand(static_cast<int>(time(0))); in mAIN TO BE RANDOM
	int roll;
	roll = (1 + rand() % 6);
	return roll;
}


void battle::sortRolls(int& firstRoll, int& secondRoll)
{
	if (secondRoll > firstRoll)
		swap(secondRoll, firstRoll);
	//firstroll is higher roll 
}
void battle::sortRolls(int& firstRoll, int& secondRoll, int& thirdRoll)
{
	if (thirdRoll > secondRoll)
		swap(thirdRoll, secondRoll);
	if (thirdRoll > firstRoll)
		swap(thirdRoll, firstRoll);
	if (secondRoll> firstRoll)
		swap(secondRoll, firstRoll);
	//firstroll is higher roll 
}

int battle::fight(country& attacker, country& defender)
{

		//dice rolls
		int attackRoll1, attackRoll2, attackRoll3;
		int defenceRoll1, defenceRoll2;

		//numbers of dices
		int attackerDices, defenderDices;

		//attack roll
		if (attacker.getArmy() >= 3)
		{
			attackRoll1 = rollDice();
			attackRoll2 = rollDice();
			attackRoll3 = rollDice();
			attackerDices = 3;
		}
		else if (attacker.getArmy() == 2)
		{
			attackRoll1 = rollDice();
			attackRoll2 = rollDice();
			attackRoll3 = 0;// will be ignored
			attackerDices = 2;
		}
		else if (attacker.getArmy() == 1)
		{
			attackRoll1 = rollDice();
			attackRoll2 = 0;
			attackRoll3 = 0;
			attackerDices = 1;
		}
		if (defender.getArmy() >= 2)
		{
			defenceRoll1 = rollDice();
			defenceRoll2 = rollDice();
			defenderDices = 2;
		}
		else if (defender.getArmy() == 1)
		{
			defenceRoll1 = rollDice();
			defenceRoll2 = 0;
			defenderDices = 1;
		}

		//sort all the rolls, high to low
		sortRolls(attackRoll1, attackRoll2, attackRoll3);
		sortRolls(defenceRoll1, defenceRoll2);

		//Display rolls

		cout << endl << "Attacker has rolled: " << attackRoll1 << "  ";
		if (attackRoll2 != 0)
			cout << attackRoll2 << "  ";
		if(attackRoll3!=0)
			cout << attackRoll3 << "  ";
		cout << endl << "Defender has rolled: " << defenceRoll1 << "  ";
		if(defenceRoll2 !=0)
			cout << defenceRoll2 << endl;

		//BATTLE --------------------------------------
		//Compare attack vs defense
		if (attackRoll1 == defenceRoll1)
		{
			int newArmy = attacker.getArmy() - 1;
			attacker.setArmy(newArmy);
		}
		else
		{
			if (attackRoll1 > defenceRoll1)
			{
				defender.setArmy(defender.getArmy() - 1);
			}
			else if (attackRoll1 < defenceRoll1)
			{
				attacker.setArmy(attacker.getArmy() - 1);
			}
		}
		// both still have army remaining  
		if (attacker.getArmy() > 1 && defender.getArmy() > 0)
		{
			//defence has 2 dice so fight continue 
			if (defenderDices == 2)
			{
				if (attackRoll2 == defenceRoll2)
				{
					attacker.setArmy(attacker.getArmy() - 1);
				}
				else
				{
					if (attackRoll2 > defenceRoll2)
					{
						defender.setArmy(defender.getArmy() - 1);
					}
					else if (attackRoll2 < defenceRoll2)
					{
						attacker.setArmy(attacker.getArmy() - 1);
					}
				}
			}
		}
		return attackerDices; // when win , need to know how many dice
}


void battle::loser()
{
	cout << "you have only one army left, you can't attack anymore!!! the invasion is over";
}

void battle::winner(int DiceUsedbyAttack, country& attacker, country& defender){

	defender.setOwner(attacker.getOwner());
	cout << "Attacker has won, he is the new owner of " << defender.getName() << endl;

	int moveArmy;
	//how you many soldier in new country
	cout << "you have " << attacker.getArmy() << " remaining in your winner country " << endl;
	cout << "how many army do you wish to move to your new country ? ";
	cin >> moveArmy;

	/// ASK QUESTION ABOUT THIS
	while (moveArmy < DiceUsedbyAttack || moveArmy > attacker.getArmy() || moveArmy == attacker.getArmy())
		{
			if (attacker.getArmy() == 2)
			{
				//moveArmy is =1 , dice used is 2 
				//user can only send 1 unit because he need to keep at least one in the attacker country 
				break;
			}
			if (moveArmy == attacker.getArmy())
			{
				cout << "You need to at least leave one army in the attacker country" << endl;
				cout << "how many army do you wish to move to your new country ?" << endl;
			}
			else
			{
				cout << " place a number of armies in the conquered country which is greater or equal than the number of dice that was used";

			}
			cin >> moveArmy;

		}

	attacker.setArmy(attacker.getArmy() - moveArmy);
	defender.setArmy(moveArmy); 

}
void battle::status(country& attacker, country& defender)
{
	cout << "Attacker has " << attacker.getArmy() << " armies left" << endl;
	cout << "Defender has " << defender.getArmy() << " armies left" << endl;
}

// all in attack mode 
void battle::blitz(country& attacker, country& defender)
{
	//fight 
	while (attacker.getArmy() > 1 && defender.getArmy() > 0)
	{
		int DiceUsedbyAttack = fight(attacker, defender);
		status(attacker, defender);

		if (attacker.getArmy() == 1)
		{
			loser();
			break;
		}
		if (defender.getArmy() ==0)
		{
			//attacker won
			winner(DiceUsedbyAttack ,attacker, defender);
			break;
		}

	}
}
void battle::skirmish(country& attacker, country& defender)
{
	while (true)
	{
		//executing the fight
		int DiceUsedbyAttack = fight(attacker, defender);
		//cout << "test" << attacker.getArmy() << endl;
		//RESULT
		if (defender.getArmy() == 0)
		{
			//attacker won
			winner(DiceUsedbyAttack, attacker, defender);
			break; //stop skrmish 
		}
		else
		{
			status(attacker, defender);
			if (attacker.getArmy() == 1)
			{
				loser();
				break;
			}
			int choice=3;
			while (choice != 1 && choice != 2)
			{
			cout << "Do you which to continue the fight or stop ---  (continue = 1, stop = 2)";
			cin >> choice;
			}
			
			if (choice == 1)
			{
				//continue while true
				//
			}
			else if (choice == 2)
			{
				//stop fight
				break;
			}
		}
	}
}

void battle::war(country& attacker, country& defender)
{
	int choice = -1;
	cout << "choose a war option: " << endl;
	cout << "0 --> skirmish" << endl;
	cout << "1 --> blitz (all in attack mode) " << endl;
	cout << "press enter to exit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: skirmish(attacker, defender);
		break;
	case 1: blitz(attacker, defender);
		break;
	default: //exit 
		break;
	}
}