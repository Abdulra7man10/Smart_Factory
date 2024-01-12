#pragma once
#include "Product.h"
#include "Queue.h"
#include <vector>
#include "Stack.h"
#include "Step.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "other.h"
using namespace std;


class Factory
{
private:
	vector<Step> steps;
	vector<Product> products;
	Queue<Product> orders;

public:
	Factory()
	{
		this->loadStep();
		this->loadProduct();
	}

	void loadStep()
	{
		int id;
		string desc;
		int duration;
		ifstream inp;

		inp.open("step.txt");
		if (inp.is_open())
			while (inp >> id)
			{
				inp.ignore();
				getline(inp, desc);
				inp >> duration;
				steps.push_back(Step(id, desc, duration));
			}
		else cout << "NOT OPENED";
		inp.close();
	}

	void loadProduct()
	{
		int id;
		string name;
		int step_id;
		ifstream inp;

		inp.open("product.txt");
		if (inp.is_open())
			while (inp >> id)
			{
				inp.ignore();
				getline(inp, name);
				Stack<Step> s;
				while (inp >> step_id)
				{
					if (step_id == 0) break;
					s.push(steps[step_id-1]);
				}
				products.push_back(Product(id, name, s));
			}
		else cout << "NOT OPENED";
		inp.close();
	}

	Product* make_product(int ID, string na, Stack<Step> s)
	{
		Product *p = new Product(ID);
		p->setName(na);
		p->setInstructions(s);
		return p;
	}

	void display_products()
	{
		for (size_t i = 0; i < products.size(); i++)
			cout << products[i].getId() << "   " << products[i].getName() << endl;
	}

	void make_order()
	{
		display_products();
		cout << endl;

		char ch = 'y';
		while (ch == 'y')
		{
			int id_product, quantity;
			id_product = IsValid(1,products.size(),"Choose ID product : ");
			quantity = IsNumber("Enter quantity of the product : ");
			for (int i = 0; i < quantity; i++)
				orders.enqueue(products[id_product - 1]);
			ch = IsChar("Do you want to order another product (y/n)? ");
		}

		cout << "\n\n";
		execution();
	}

	void execution()
	{
		while (!orders.IsEmpty())
		{
			orders.frontt().execution();
			orders.dequeue();
		}
	}
};

