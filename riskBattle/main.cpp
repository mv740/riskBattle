#include "battle.h"
#include "country.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	country m("canada", "RED", 10);
	country *z = new country("canada","red", 1);
	string a = z->getName();
	cout << "name is" << a << endl;
	

	//cmd prompt doesn't close
	system("Pause");
	return 0;
}