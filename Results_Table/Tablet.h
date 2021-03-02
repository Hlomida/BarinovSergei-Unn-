#include <iostream>

using namespace std;

class Tablet
{
public:
	char *Name;
	int *Number;
	void Create()
	{
		Name = new char;
		Number = new int;
	};
};