#include "battle.h"
#include "country.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main()
{
	//country m("canada", "RED", 10);
	//country *z = new country("canada","red", 1);
	//string a = z->getName();
	//cout << "name is" << a << endl;
	
	
	srand(static_cast<int>(time(0))); //get real random 

	country world[5] = 
	{ 
		country("canada", "red", 10),
		country("usa", "red", 5),
		country("brazil", "red", 1),
		country("mexico", "blue", 5),
		country("uk", "blue", 10)
	};

	

	battle risk;
	
	//user is red
	//show current world map 
	cout << "CURRENT WORLD MAP ( user is red) " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << world[i].getName() << " Owner is : " << world[i].getOwner() << " army : " << world[i].getArmy() << endl;
	}

	int choiceAttacker = -1;
	cout << "\n\nYour turn has started, please select your country from the list below" <<endl << "(choose number)" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (world[i].getOwner() == "red" && world[i].getArmy() >=2)
		{
			cout << i <<"--->Country : " << world[i].getName() << " army : " << world[i].getArmy() << endl;
		}
	}
	cin >> choiceAttacker;
	int choicedefender = -1;
	cout << "Choose which country to attack from the list below" << endl << "(choose number)" << endl;
	for (int i = 0; i < 5; i++)
	{
		if (world[i].getOwner() == "blue")
		{
			cout << i << "--->Country : " << world[i].getName() << " army : " << world[i].getArmy() << endl;
		}
	}
	cin >> choicedefender;
	risk.war(world[choiceAttacker], world[choicedefender]);

	cout << "\nWar is over! new world map : " <<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << world[i].getName() << " Owner is : " << world[i].getOwner() << "army->" << world[i].getArmy() << endl;
	}
	



	//cmd prompt doesn't close
	system("Pause");
	return 0;
}