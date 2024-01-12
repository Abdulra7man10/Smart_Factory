#pragma once
#include "LinkedList.h"

template <typename T>
class LinkedList;

template <typename T>
class Stack : public LinkedList<T>
{
public:
	void push(T value)
	{
		LinkedList<T>::push_front(value);
	}

	bool pop()
	{
		return LinkedList<T>::pop_front();
	}
};
