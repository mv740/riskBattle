#include "battle.h";
#include "country.h";
#include <iostream>;
using namespace std;

int main()
{
	country m("canada", "RED", 10);
	
	cout << "name is" + m.getName  << endl;
	

	//cmd prompt doesn't close
	system("Pause");
	return 0;
}