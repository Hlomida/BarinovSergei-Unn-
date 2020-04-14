#include <iostream> 
#include <cassert>
#include <string>
using namespace std;


class Vector
{
public:
	int x, y, z;
	Vector()
	{}
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
public:
	int collumn, row;
	Matrix()
	{}
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
		int cx;
		try
		{
			Vector c;
			cin >> c.x;
			if (!(isdigit(c.x)))
			{
				throw exception("Not a number imput");
			}

			cin >> c.y;
			if (!(isdigit(c.y)))
			{
				throw exception("Not a number imput");
			}
			cin >> c.z;
			if (!(isdigit(c.z)))
			{
				throw exception("Not a number imput");
			}
		cout << c.x << c.y << c.z << endl;
		}
		catch (const exception &ex)
		{
			cout << ex.what() << endl;
		}
		
		return 0;
	};