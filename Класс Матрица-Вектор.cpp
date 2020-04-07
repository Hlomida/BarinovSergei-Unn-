#include <iostream> 
#include <cassert>
using namespace std;

class Vector
{
public:
	int x, y, z;
	/*Vector(int x, int y, int z)
	{
		cout << "test 1" << endl;
		cout << x << " " << y << " " << z << endl;
	}*/
	/*Vector(const Vector& vec)
	{
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
		cout <<"Copy Iniciated" << endl;
	}*/
	Vector & operator = (const Vector& vec)
	{

		cout << "= init" << endl;
			this->x = vec.x;
			this->y = vec.y;
			this->z = vec.z;
			return *this;
	}
};


class Matrix
{
private:
	int* a;
	int collumn, row;
public:
	Matrix(int _collumn, int _row) :
		collumn(_collumn),
		row(_row)
	{
		a = new int [collumn*row];
		cout << a << endl;
	}
	Matrix(const Matrix& mat)
	{
		this->collumn = mat.collumn;
	this->row = mat.row;
	
		a = new int[collumn * row];
		memcpy(a,mat.a,sizeof(collumn * row));
		cout << "Copy Iniciated" << endl;
	}
	Matrix& operator = (const Matrix& mat)
	{

		cout << "= init" << endl;
		this->collumn = mat.collumn;
		this->row = mat.row;
		return *this;
	}
};

int main()
{
	Vector a;
	a.x = 1;
	a.y = 5;
	a.z = 3;
	cout << a.x <<" "<<a.y<<" "<<a.z <<endl;
	Vector b;
	b.x = 3;
	b.y = 7;
	b.z = 4;
	cout << b.x << " " << b.y << " " << b.z << endl;
	a = b;
	cout << a.x << " " << a.y << " " << a.z << endl;
	return 0;
};