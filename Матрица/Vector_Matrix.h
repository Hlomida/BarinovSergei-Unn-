
#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;


template <class ValType>
class TVector
{
protected:
	ValType* pVector;
	int Size;
	int StartIndex;
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);
	~TVector();
	int GetSize() { return Size + StartIndex; }
	int GetStartIndex() { return StartIndex; }
	ValType& operator[](int pos);
	bool operator==(const TVector& v) const;
	bool operator!=(const TVector& v) const;
	TVector& operator=(const TVector& v);


	TVector  operator+(const ValType& val);
	TVector  operator-(const ValType& val);
	TVector  operator*(const ValType& val);


	TVector  operator+(const TVector& v);
	TVector  operator-(const TVector& v);
	ValType  operator*(const TVector& v);


	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << "\t";
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if ((s <= 0) || (s > MAX_VECTOR_SIZE))
		throw "big size";
	if ((si < 0) || (si >= s))
		throw "index";
	Size = s - si;
	StartIndex = si;
	pVector = new ValType[Size];
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
}

template <class ValType>
TVector<ValType>::~TVector()
{
	delete[]pVector;
}

template <class ValType>
ValType& TVector<ValType>::operator[](int pos)
{
	if ((pos - StartIndex < Size) && (pos - StartIndex > -1))
		return pVector[pos - StartIndex];
	else
		throw(pos);
}

template <class ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
	if (this != &v)
	{
		if (Size != v.Size)
			return false;
		else if (StartIndex != v.StartIndex)
			return false;
		else
			for (int i = 0; i < Size; i++)
				if (pVector[i] != v.pVector[i])
				{
					return false;
				}
	}
	return true;
}

template <class ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !(*this == v);
}

template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (this != &v)
	{
		delete[]pVector;
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new ValType[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];
	}
	return *this;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector <ValType> x(Size, StartIndex);
	for (int i = StartIndex; i < Size; i++)
		x.pVector[i] = pVector[i] + val;
	return x;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector <ValType> x(Size, StartIndex);
	for (int i = StartIndex; i < Size; i++)
		x.pVector[i] = pVector[i] - val;
	return x;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector <ValType> x(Size, StartIndex);
	for (int i = StartIndex; i < Size; i++)
		x.pVector[i] = pVector[i] * val;
	return x;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector <ValType>& v)
{
	TVector<ValType> res(*this);
	if (Size != v.Size)
		throw v.Size;
	for (int i = 0; i < Size; i++)
		res.pVector[i] = this->pVector[i] + v.pVector[i];
	return res;
}

template <class ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	TVector<ValType> c(*this);
	if (Size != v.Size)
		throw v.Size;
	for (int i = 0; i < Size; i++)
		c.pVector[i] = pVector[i] - v.pVector[i];
	return c;
}

template <class ValType>
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if ((Size != v.Size) || (StartIndex != v.StartIndex))
		throw "size";
	ValType scal = 0;
	for (int i = 0; i < Size; i++)
		scal += pVector[i] * v.pVector[i];
	return scal;
}


template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);
	TMatrix(const TVector<TVector<ValType> >& mt);
	bool operator==(const TMatrix& mt) const;
	bool operator!=(const TMatrix& mt) const;
	TMatrix& operator= (const TMatrix& mt);
	TMatrix  operator+ (const TMatrix& mt);
	TMatrix  operator- (const TMatrix& mt);


	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
		{
			for (int j = 0; j < i; j++)
				out << "\t";
			out << mt.pVector[i] << endl;
		}
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if ((s < 1) || (s > MAX_MATRIX_SIZE))
		throw s;
	Size = s;
	for (int i = 0; i < s; i++)
		pVector[i] = TVector<ValType>(s, i);
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt)
{
	Size = mt.Size;
	StartIndex = mt.StartIndex;
	pVector = new TVector<ValType>[Size];
	for (int i = 0; i < Size; i++)
		pVector[i] = mt.pVector[i];
}

template <class ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	if (this != &mt)
	{
		if (Size != mt.Size)
			return false;
		for (int i = 0; i < Size; i++) {
			if (pVector[i] != mt.pVector[i])
			{
				return false;
			}
		}
	}
	return true;
}

template <class ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return !(*this == mt);
}

template <class ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this != &mt)
	{
		delete[]pVector;
		Size = mt.Size;
		StartIndex = mt.StartIndex;
		pVector = new TVector<ValType>[Size];
		for (int i = 0; i < Size; i++)
			pVector[i] = mt.pVector[i];
	}
	return *this;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size || StartIndex != mt.StartIndex)
		throw mt.Size;
	TMatrix<ValType> res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] + mt.pVector[i];
	return res;
}

template <class ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	if (Size != mt.Size || StartIndex != mt.StartIndex)
		throw mt.Size;
	TMatrix<ValType> res(Size);
	for (int i = 0; i < Size; i++)
		res.pVector[i] = pVector[i] - mt.pVector[i];
	return res;
}

#endif 