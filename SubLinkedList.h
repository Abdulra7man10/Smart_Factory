#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
struct SubNode
{
    T* arr;
    size_t size;
    SubNode<T>* next = nullptr;
    SubNode(size_t sz = 4) : size(sz)
    {
        arr = new T[size];
    }
};

template <typename T>
class SubLinkedList : public List<T>
{
private:
    SubNode<T>* head;
    SubNode<T>* tail;
    size_t rear;
    size_t front;

public:
    SubLinkedList() : head(nullptr), tail(nullptr), rear(0), front(0)
    { }

    void push_back(T value)
    {
        if (IsEmpty()) { head = new SubNode<T>; tail = head; }
        if (rear % tail->size == 0 && rear != 0)
        {
            tail->next = new SubNode<T>;
            tail = tail->next;
        }

        tail->arr[rear % tail->size] = value;
        rear++;
    }

    bool pop_front()
    {
        if (IsEmpty()) return false;
        front++;
        if (front % tail->size == 0 && front != 0)
        {
            SubNode<T>* temp = head->next;
            delete head;
            head = temp;
        }
        return true;
    }

    bool pop_back()
    {
        if (IsEmpty()) return false;
        if (rear % tail->size == 0)
        {
            SubNode<T>* temp = head;
            if (temp == tail) head = temp = nullptr;
            else
                while (temp->next->next) temp = temp->next;
            delete tail;
            tail = temp;
        }
        rear--;
        return true;
    }

    void display()
    {
        if (!head) return;

        SubNode<T>* cur = head;
        size_t counter = front;
        while (cur)
        {
            for (size_t i = counter%tail->size; counter < rear && i < tail->size; i++, counter++)
                cout << cur->arr[i % tail->size] << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    size_t getSize()
    {
        return rear - front;
    }

    bool IsEmpty()
    {
        return rear == front;
    }

    T& frontt()
    {
        return head->arr[front%tail->size];
    }
};
