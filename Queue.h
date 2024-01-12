#pragma once
#include "SubLinkedList.h"

template <typename T>
class Queue : public SubLinkedList<T>
{
public:
	void enqueue(T value)
	{
		SubLinkedList<T>::push_back(value);
	}

	bool dequeue()
	{
		return SubLinkedList<T>::pop_front();
	}
};
