#include <iostream> 
#include <cassert>

int main()
{};

class Vector
{
private:
	int* a;
	int x, y, z;
public:
	Vector(int _x, int _y, int _z) :
		x(_x), y(_y), z(_z)
	{

	}
	Vector(const Vector&vector):
		x(vector _x),
		y(vector _y),
		z(vector _z)
	{}
};
class Matrix
{
private:
	int* a;
	int collumn, row;
public:
	Matrix(int _collumn, int _row):
		collumn(_collumn),
		row(_row)
	{
		a = new int[collumn * row];
	}
	Matrix(const Matrix&marix):
		collumn(matrix _collumn),
		row(matrix _row)
	{

	}
};