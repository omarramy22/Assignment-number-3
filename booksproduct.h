#include <iostream>
#include<string>
#ifndef booksproduct_h
#define booksproduct_h
#include "theproduct.h"
using namespace std;


class booksproduct : public product
{
private:
	string author; 

public:
	enum genre { history, science, novel } enumtype;
	booksproduct (string n, float p, int q, string a, genre t) : product(n, p, q), author(a), enumtype(t) {}

	void setauthor(string a)
	{
		author = a;
	}
	string getauthor()
	{
		return author;
	}
	string gettype()
	{
		string x;
		if (enumtype == 0)
			x = "history ";
		else if (enumtype == 1)
			x = "science ";
		else if (enumtype == 2)
			x = "novel ";
		else
			x = "this product is not defined ";
		return x;
	}
	bool iselectronics()
	{
		return true;
	}

	friend std::ostream& operator<<(std::ostream& os, booksproduct p)
	{
		os << " Name: " << p.getname() << " ,Price per unit: " << p.getprice_per_unit() << " ,Quantity: " << p.getquantity() << " ,Author: " << p.author << " ,Genre " << p.gettype() << endl; 
		return os;
	}
};
#endif 

