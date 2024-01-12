#pragma once
#include <iostream>
#include "Stack.h"
#include <string>
#include "Step.h"
using namespace std;

class Product
{
private:
	int id;
	string name;
	Stack<Step> instructions;

public:
    Product(int ID, string na, Stack<Step> in) : id(ID), name(na), instructions(in)
    { }
    Product(int ID=0) : id(ID)
    { }
    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    void setName(const string& newName)
    {
        name = newName;
    }

    Stack<Step>& getInstructions()
    {
        return instructions;
    }

    void setInstructions(const Stack<Step>& newInstructions)
    {
        instructions = newInstructions;
    }

    void execution()
    {
        cout << "ID : " << id << "   " << "Name : " << name;
        cout << "\n------------------------\n\n";
        for (size_t i=0; i<=instructions.getSize(); i++)
        {
            instructions.at(i).execution();
            cout << "Step " << i+1 << " is finished :)\n\n";
        }

        cout << "\n" <<name <<" completed :)\n";
        cout << "\n*************************************\n\n";
    }
};

