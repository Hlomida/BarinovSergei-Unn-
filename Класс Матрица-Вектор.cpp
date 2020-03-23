#include <iostream> 
#include <cassert>
using namespace std;

class Vector
{
public:
	int x;
	int y;
	int z;
	Vector(int x, int y, int z)
	{
		cout << "test 1" << endl;
		cout << x << " " << y << " " << z << endl;
	}
	Vector(const Vector& vec)
	{
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
		cout <<"Copy Iniciated" << endl;
	}
	void operator = (const Vector& vec)
	{

		cout << "= init" << endl;
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
		
	}
};


/*class Matrix
{
private:
	int a;
	int collumn, row;
public:
	Matrix(int _collumn, int _row) :
		collumn(_collumn),
		row(_row)
	{
		a = collumn * row;
		cout << a << endl;
	}
};*/

int main()
{
	Vector a(2, 5, 2);
	cout << a.x <<" "<<a.y<<" "<<a.z <<endl;
	Vector b(3, 7, 4);
	cout << b.x << " " << b.y << " " << b.z << endl;
	a = b;
	cout << a.x << " " << a.y << " " << a.z << endl;
};