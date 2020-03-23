#include <iostream> 
#include <cassert>
using namespace std;

class Vector
{
private:
	int* x, y, z;
public:
	int size;
	Vector(int _x, int _y, int _z)
	{
		cout << "test 1" << endl;
	}
	Vector(const Vector& vec)
	{
		this->size = vec.size;
		this->x = new int[vec.size];
		for (int i = 0; i < vec.size; i++)
		{
			this->x[i] = vec.x[i];
		}
		cout <<"Copy Iniciated" << size << endl;
	}
};


class Matrix
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
};

int main()
{
	Vector a(2,5,1);
	Vector b(a, 1, 5);
};