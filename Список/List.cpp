#include <iostream>
#include <stdio.h>
#include "List.h"

using namespace std;

void main() //�������� � ������� ������
{
	setlocale(LC_ALL, "ru");
	int x, enter, col;

	List list;	
			cout << "������� ���������� ��������� ������:";
			cin >> col;
			for (int i = 0; i < col; i++)
			{
				cout << "������� " << i << " ������� ������:";
				cin >> x;
				list.InsElemOne(x);
			}
			list.PrintList();
			system("pause");
		}
	
