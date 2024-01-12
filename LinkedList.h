#pragma once
#include "List.h"
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node(T value) : data(value)
    {
        next = nullptr;
    }
};

template <typename T>
class LinkedList : public List<T>
{
private:
    Node<T>* head;
    size_t size;

public:
    LinkedList() : head(nullptr), size(0)
    { }

    void push_front(T value)
    {

        Node<T>*t = new Node<T>(value);
        if (!head)
        {
            head = t; return;
        }

        t->next = head;
        head = t;
        size++;
    }

    bool pop_front()
    {
        if (!head) return false;

        Node<T>* p = head->next;
        delete head;
        head = p;
        size--;
        return true;
    }

    T& top()
    {
        return head->data;
    }

    T& at(size_t i)
    {
        size_t counter = 0;
        Node<T>* cur = head;
        for (; counter != i; counter++)
            cur = cur->next;
        return cur->data;
    }

    void display()
    {
        Node<T>* cur = head;
        while (cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    size_t getSize()
    {
        return size;
    }

    bool IsEmpty()
    {
        return !head;
    }
};