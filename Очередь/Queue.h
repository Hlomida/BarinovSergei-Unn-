/*#pragma once
template <class T>
class TQueue
{
private:
	int Size, MaxSize, first, last;
	T* ord;
public:
	TQueue(int _MaxSize = 10);
	TQueue(const TQueue <T>& queue);
	~TQueue();
	TQueue operator =(const TQueue& queue);
	bool operator==(const TQueue <T>& queue) const;
	bool operator!=(const TQueue& queue) const;
	bool IsFull() const;
	bool IsEmpty() const;
	void Push(const T elem);
	int GetSize() { return Size; }
	int GetMaxSize() { return MaxSize; }
	int First() { return first; }
	T Pop();
	T WhoIsFirst() const;
	T WhoIsLast()const;
	void Clear();

};

template <class T>
TQueue <T>::TQueue(int _MaxSize)
{
	if (_MaxSize <= 0)
		throw _MaxSize;
	MaxSize = _MaxSize;
	ord = new T[MaxSize];
	first = 0;
	last = -1;
	Size = 0;
}
template <class T>
TQueue <T> ::TQueue(const TQueue <T>& queue)
{
	MaxSize = queue.MaxSize;
	first = queue.first;
	last = queue.last;
	Size = queue.Size;
	ord = new T[MaxSize];
	for (int i = 0; i < MaxSize; i++)
		ord[i] = queue.ord[i];
}
template <class T>
TQueue<T> ::~TQueue()
{
	delete[] ord;
}

template <class T>
TQueue <T> TQueue <T>::operator=(const TQueue <T>& queue)
{
	if (MaxSize != queue.MaxSize)
	{
		delete[] ord;
		ord = new T[queue.MaxSize];
	}
	MaxSize = queue.MaxSize;
	first = queue.first;
	last = queue.last;
	Size = queue.Size;
	for (int i = 0; i < MaxSize; i++)
		ord[i] = queue.ord[i];
	return *this;
}
template <class T>
bool TQueue <T>::operator==(const TQueue& queue) const
{
	if (!(MaxSize == queue.MaxSize && Size == queue.Size && first == queue.first && last && queue.last))
		return false;
	for (int i = 0; i < MaxSize; i++)
		if (ord[i] != queue.ord[i])
			return false;
	return true;
}
template <class T>
bool TQueue <T>::operator!=(const TQueue& queue) const
{
	return !(*this == queue);
}
template <class T>
bool  TQueue <T>::IsEmpty() const
{
	if (Size == 0)
		return true;
	else
		return false;
}
template <class T>
bool TQueue <T> ::IsFull() const
{
	if (Size == MaxSize)
		return true;
	else
		return false;
}
template <class T>
void TQueue <T>::Push(const T elem)
{
	if (this->IsFull())
		throw "Queue is full";
	if (last == MaxSize - 1)
		last = 0;
	else
		last++;
	ord[last] = elem;
	Size++;
}
template <class T>
T TQueue <T> ::Pop()
{
	if (this->IsEmpty())
		throw "Queue is empty";
	int tmp = first;
	first++;
	first = first % MaxSize;
	Size--;
	return ord[tmp];
}
template <class T>
T TQueue <T>::WhoIsFirst() const
{
	if (IsEmpty())
		throw "queue is empty";
	return ord[first];
}
template <class T>
T TQueue <T>::WhoIsLast() const
{
	return ord[last];
}
template <class T>
void TQueue<T>::Clear()
{
	delete[] ord;
	ord = new T[queue.MaxSize];
	first = 0;
	last = -1;
	Size = 0;

}*/
#include <iostream>
using namespace std;

template<typename T>
class queue
{
public:
	queue();
	~queue();
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
	return head->data;
}

template<typename T>
T queue<T>::Back()
{
	return tail->data;
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