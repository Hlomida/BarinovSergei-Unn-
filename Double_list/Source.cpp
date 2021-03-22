#include "List.h"

int main()
{
	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_front(4);
	lst.push_front(5);
	lst.push_front(6);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl;

	lst.insert(83, 0);

	//lst.push_front(7);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << endl;

	lst.pop_front();
	lst.removeAt(3);
	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}