
#include <iostream>
#include "Stack.h"
#include "Calc.h"
using namespace std;
string str;

bool Check(string str)
{
	TStack <char> st(10);

	for (int i = 0; i < str.length(); i++)
		if (str[i] == '(')
			st.Push(str[i]);
		else if (str[i] == ')')
		{
			if (st.IsEmpty())
				return false;
			else
				st.Pop();
		}
	if (st.IsEmpty())
		return true;
	else
		return false;
}

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "¬ведите уравнение: ";
	cin >> str;
	Calc tcal;
	tcal.SetInfix(str);
	cout << tcal.GetPostfix() << endl;;
	cout << tcal.CalcS() << endl;
	system("pause");
}
