#pragma once
#include <iostream>
#include <string>
using namespace std;
/* двусв€зный список*/
template<typename T>
class List
{
public:
	List();
	~List();
	void push_back(T data); // добавл€ет элемент в начало
	int GetSize() // выводит размер списка
	{
		return Size;
	}
	T& operator[](const int index);
	void pop_front(); // удал€ет последний элемент в списке
	void clear(); // удал€ет каждый элемент последовательно
	void push_front(T data); // добавл€ет элемент в конец списка 
	void insert(T data, int index);// добавл€ет элемент в определенное места списка
	void removeAt(int index);// убирает элемент определенного номера
	void pop_back(); // удал€ет первый элемент в списке

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)  // nullptr - нулевой указатель
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};




template<typename T>
List<T>::List()  // ѕри начальном вызове списка его размер 0 и указатель последнего элемента нулевой
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head; // переносит текущий указатель в конец списка

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}

		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}
