#include <iostream>
#include <stdio.h>
#include "List.h"

using namespace std;

void main() //получает и выводит список
{
	setlocale(LC_ALL, "ru");
	int x, enter, col;

	List list;	
			cout << "Введите количество элементов списка:";
			cin >> col;
			for (int i = 0; i < col; i++)
			{
				cout << "Введите " << i << " элемент списка:";
				cin >> x;
				list.InsElemOne(x);
			}
			list.PrintList();
			system("pause");
		}
	
