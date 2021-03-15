#pragma once

#include <string>
#include <sstream>

#include "Bitfield.h"

class Set
{
	BitField bf;
	int MaxPower;

public:
	Set(int mp = 100) : MaxPower(mp), bf(mp) {};
	~Set() {};

	Set(const Set& m) : bf(m.bf)
	{
		MaxPower = m.MaxPower;
	}

	Set(const BitField& tmp) : bf(tmp), MaxPower(tmp.getBitSize()) {};

	operator BitField()
	{
		BitField tmp(this->bf);
		return tmp;
	}

	void Add(int el)
	{
		bf.setBit(el);
	}

	void Del(int el)
	{
		bf.clrBit(el);
	}

	int Check(int el)
	{
		return bf.checkBit(el);
	}


	Set operator + (const Set& s)
	{
		return bf | s.bf;
	}

	Set operator * (const Set& s)
	{
		return bf & s.bf;
	}

	Set operator ~()
	{
		return ~bf;
	}

	int GetMaxPower(void) const
	{
		return MaxPower;
	}

	friend ostream& operator<<(ostream& ostr, const Set& s)
	{
		int i, n; char ch = ' ';
		ostr << "{";
		n = s.GetMaxPower();

		for (i = 0; i < n; i++)
		{
			ostr << ch << ' ' << i;
			ch = ', ';
		}

		ostr << " }";
		return ostr;

	}

	friend istream& operator>>(istream& istr, Set& s)
	{
		int temp; char ch;

		do { istr >> ch; } while (ch != '{');
		do {
			istr >> temp; s.Add(temp);
			do { istr >> ch; } while ((ch != ',') && (ch != '}'));
		} while (ch != '}');
		return istr;
	}

	Set Resehto(Set& s)
	{
		int m, k, n;

		n = s.GetMaxPower();

		for (m = 2; m * m <= n; m++)
		{
			s.Del(0);
			s.Del(1);

			if (s.Check(m))
				for (k = 2 * m; k <= n; k += m)
					if (s.Check(k))
						s.Del(k);
		}

		return s;
	}

	string ToStri()
	{
		string str;
		ostringstream outStream;
		outStream << "{";
		for (int i = 0; i < MaxPower; i++)
			if (Check(i))
				if (i < (MaxPower - 1))
				{
					outStream << i << ",";
					str = outStream.str();
				}
				else
				{
					outStream << i;
					str = outStream.str();
				}
		outStream << "}";
		str = outStream.str();
		return str;
	}


};