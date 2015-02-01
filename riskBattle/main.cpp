#include "battle.h"
#include "country.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//country m("canada", "RED", 10);
	//country *z = new country("canada","red", 1);
	//string a = z->getName();
	//cout << "name is" << a << endl;
	
	
	country *world [4];
	world[0] = new country("canada", "red", 10);
	world[0] = new country("usa", "red", 5);
	world[0] = new country("mexico", "blue", 5);
	world[0] = new country("uk", "blue", 10);





	//cmd prompt doesn't close
	system("Pause");
	return 0;
}