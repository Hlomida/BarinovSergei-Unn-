#include <iostream>
#include "Queue.h"

using namespace std;


int main()
{
	queue<int> que;
	queue<int> que2;
	que.push_back(1);
	que.push_back(2);
	que.push_back(3);
	que.push_back(4);
	que.push_back(5);
	cout << "queue size:" << que.GetSize() << endl;
	cout << "top: " << que.Top() << endl;
	cout << "back: " << que.Back() << endl;
	cout << "removing element" << endl; que.pop_front();
	cout << "top: " << que.Top() << endl;
	cout << "back: " << que.Back() << endl;
	cout << "queue size:" << que.GetSize() << endl;
	/*cout << "clearing entire queue" << endl;  que.clear();
	cout << "1 - empty, 0 - not empty:" << que.isEmpty() << endl;*/
	que2 = que;
	//que2.dupe(que);
	que2.Top();
	que2.GetSize();
	return 0;

}