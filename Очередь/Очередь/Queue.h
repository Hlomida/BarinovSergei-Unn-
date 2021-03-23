#include <iostream>
using namespace std;

template<typename T>
class queue
{
public:
	queue();
	~queue();
	queue(const queue &orig)
	{
		data = orig.data;
		cout << "copy";
	}
	void push_back(T data); // добавляет элемент в начало очереди
	int GetSize() // возвращает размер очереди
	{
		return size;
	}
	T Top(); // выводит значение конца очереди
	T Back(); // выводит значение начала очереди
	void pop_front(); // убирает элемент из конца очереди
	void clear(); // отчищает очередь последовательно
	bool isEmpty(); // проверяет очередь на пустоту
	//void dupe(const queue &orig);
	T& operator=(const queue &orig);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node<T>* head; //первый добавленый элемент, первый убранный
	Node<T>* tail; // последний добавленный элемент
};

template<typename T>
queue<T>::queue() //  при создании очереди изначально она пуста и указатели на начало и конец пусты
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
queue<T>::~queue()
{
	clear();
}
/*template<typename T>
queue<T>::queue(const queue &orig)
{
	cout << "test" << endl;
}*/
template<typename T>
void queue<T>::push_back(T data) // проверяет начало и конец на пустоту и заполняет их, либо добавляет значение в начало очереди 
{
	if (head == nullptr) 
	{
		head = new Node<T>(data);
	}
	else if (tail == nullptr) 
	{
		tail = new Node<T>(data);
		head->pNext = tail;
	}
	else
	{
		Node<T>* current = tail;
		tail = new Node<T>(data);
		current->pNext = tail;
	}
	size++;
}

template<typename T>
T queue<T>::Top()
{
	if (head == nullptr) { cout << "nullptr"; }
	else {
		return head->data;
	}
}

template<typename T>
T queue<T>::Back()
{
	if (tail == nullptr)
	{
		cout << "nullptr";
	}
	else {
		return tail->data;
	}
}

template<typename T>
void queue<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	size--;
}

template<typename T>
void queue<T>::clear() // вызывает функцию удаления первого элемента последовательно для каждого элемента в очереди 
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
bool queue<T>::isEmpty()
{
	if (size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}
template<typename T>
T& queue<T>::operator=(const queue &orig)
{
	clear();
	while (orig.size)
	{
		//head = orig.head;
		//head = orig.head->pNext;
		push_back(orig.head->data);

		return head->data;
		//orig.pop_front();
	}
	
}
/*template<typename T>
void queue<T>::dupe(const queue &orig)
{
	Node<T>* temp = orig.head;
	//data = temp->data;
	push_back(temp->data);
	cout << "Copy" << endl;
}*/
