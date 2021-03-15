#pragma once

#include <iostream>
#include <vector>

using namespace std;

class BitField {
private:
	int* mas;
	int size;
	int bitSize;

	int getNumOfBlock(int num);
	int getBitMask(int num);

public:
	BitField();
	BitField(int _bitSize);
	BitField(const BitField& bf);
	~BitField();

	// ������ � �����
	int getBitSize() const;
	void setBit(int pos);
	void clrBit(int pos);
	/* ���������� ��� */
	int getBit(int pos)
	{
		return (/*mas[getNumOfBlock(pos)] & */getBitMask(pos));
	}
	int checkBit(int pos);

	// ������� ��������
	BitField& operator=(const BitField& bf);
	int  operator==(const BitField& bf);

	BitField& operator|=(const BitField& bf);
	BitField& operator&=(const BitField& bf);

	BitField operator|(const BitField& bf);
	BitField operator&(const BitField& bf);
	BitField operator~();


	friend ostream& operator<< (ostream& out, BitField& bf)
	{
		int len = bf.getBitSize();

		for (int i = 0; i < len; i++)
			if (bf.getBit(i)) out << '1'; else out << '0';

		return out;
	}

	friend istream& operator>> (istream& in, BitField& bf)
	{
		int i = 0;
		char ch;

		while (1)
		{
			in >> ch;
			if (ch == '0') bf.clrBit(i++);
			else if (ch == '1') bf.setBit(i++); else break;
		}

		return in;
	}

};

/* ����������� �� ��������� */
BitField::BitField(){}

BitField::BitField(int _bitSize)
{
	bitSize = _bitSize;
	size = bitSize / (sizeof(int) * 8) + 1;
	vector<int> mas;
	for (int i = 0; i < size; i++) mas[i] = 0;
}

/* ����������� �����������*/
BitField::BitField(const BitField& bf)
{
	bitSize = bf.bitSize;
	size = bf.size;
	vector<int> mas;
	for (int i = 0; i < size; i++) mas[i] = bf.mas[i];
}

/* ���������� */
BitField::~BitField()
{
	delete[] mas;
}

/* �������� ����� ����� */
int BitField::getNumOfBlock(int num)
{
	return num / (sizeof(int) * 8);
}

/* ������� ������� ����� */
int BitField::getBitMask(int num)
{
	int st = num % (sizeof(int) * 8), res = 1;
	return res << st;
}

/* �������� ����� �������� ���� */
int BitField::getBitSize() const
{
	return bitSize;
}

/* �������� ��� */
void BitField::setBit(int pos)
{
	mas[getNumOfBlock(pos)] |= getBitMask(pos);
}

/* ������� ��� */
void BitField::clrBit(int pos)
{
	mas[getNumOfBlock(pos)] &= ~getBitMask(pos);
}

/* ��������� ��� */
int BitField::checkBit(int pos)
{
	return (/*mas[getNumOfBlock(pos)] & */getBitMask(pos));
}


/* ������������*/
BitField& BitField::operator=(const BitField& bf)
{
	bitSize = bf.bitSize;
	size = bf.size;

	for (int i = 0; i < size; i++) mas[i] = bf.mas[i];

	return (*this);
}

/* ��������� */
int BitField::operator==(const BitField& bf)
{
	int res = 1;

	if (bitSize != bf.bitSize) res = 0;
	else
		for (int i = 0; i < size; i++)
			if (mas[i] != bf.mas[i]) { res = 0; break; };

	return res;
}

/* ������������ � ��� */
BitField& BitField::operator|=(const BitField& bf)
{
	for (int i = 0; i < size; i++) mas[i] |= bf.mas[i];

	return (*this);
}

/* ������������ � � */
BitField& BitField::operator&=(const BitField& bf)
{
	//for (int i = 0; i < size; i++) mas[i] &= bf.mas[i];

	return (*this);
}

/* �������� ��� */
BitField BitField::operator|(const BitField& bf)
{
	BitField temp(bitSize);

	for (int i = 0; i < size; i++) temp.mas[i] = mas[i] | bf.mas[i];

	return (temp);
}

/* �������� � */
BitField BitField::operator&(const BitField& bf)
{
	BitField temp(bitSize);

	for (int i = 0; i < size; i++) temp.mas[i] = mas[i] & bf.mas[i];

	return (temp);
}

/* �������� �� */
BitField BitField::operator~()
{
	BitField temp(bitSize);

	for (int i = 0; i < size; i++) temp.mas[i] = ~mas[i];

	return (temp);
}