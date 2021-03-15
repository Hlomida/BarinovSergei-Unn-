#pragma once
#include <iostream>
#include<stdio.h>

using namespace std;
class List
{
public:
	void InsElemOne(int pow);
	void PrintList(); // выводит список
private:
	class Node {
	public:
		int pow;
		Node* pNext;
	public:
		Node(int pow, Node* pNext)
		{
			this->pow = pow;
			this->pNext = pNext;
		}
	};
	int size;
	int size2;
	Node* pHead;
	Node* pCurr;
	Node* pHead2;
	Node* pCurr2;
	Node* pNew;
	Node* pPrev;
	Node* pPrev2;
	Node* pDel;
	Node* pCurr3;
	Node* pCurr4;

};
List::List()
{
	pHead = new Node(0, NULL);
	pHead->pNext = pHead;
	size = 1;
	pHead2 = new Node(0, NULL);
	pHead2->pNext = pHead2;
	size2 = 1;
}
void List::PrintList()
{
	pCurr = pHead->pNext;
	pCurr2 = pHead2->pNext;
	if (size != 1)
	{
		while (pCurr != NULL)
		{
			cout << pCurr->pow << "->";
			pCurr = pCurr->pNext;
		}
		cout << "NULL" << endl;
	}
	else
		cout << "Список Заполнен" << endl;
	if (size2 != 1)
	{
		while (pCurr2 != NULL)
		{
			cout << pCurr2->pow << "->";
			pCurr2 = pCurr2->pNext;
		}
		cout << "NULL" << endl;
	}
	else
		cout << "Список Закончен" << endl;
}
void List::InsElemOne(int pow) // получает элементы списка
{
	pCurr = this->pHead;
	if (size == 1)
	{
		pNew = new Node(pow, NULL);
		pHead->pNext = pNew;
		size++;
	}
	else
	{
		pCurr = pHead->pNext;
		while (pCurr->pNext != NULL)
		{
			pCurr = pCurr->pNext;
		}
		pNew = new Node(pow, NULL);
		pCurr->pNext = pNew;
		size++;
	}
}


