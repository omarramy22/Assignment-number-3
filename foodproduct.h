#include <iostream>
#include<string>
#ifndef foodproduct_h
#define foodproduct_h
#include"theproduct.h"
using namespace std;
class foodproduct : public product
{
private:
	int expirydate; 

public:
	enum foodtype { fruit, vegetables, other } enumtype;
	foodproduct (string n, float p, int q, int e, foodtype t) : product(n, p, q), expirydate(e), enumtype(t) {}

	void setexpirydate(int e)
	{
		expirydate = e;
	}
	int getexpirydate()
	{
		return expirydate;
	}
	string gettype()
	{
		string x;
		if (enumtype == 0)
			x = "fruit ";
		else if (enumtype == 1)
			x = "vegetables ";
		else if (enumtype == 2)
			x = "other ";
		else
			x = "this product is not defined "; 
		return x; 
	}

	friend std::ostream& operator<<(std::ostream& os, foodproduct p)
	{
		os << " Name: " << p.getname() << " ,Price per unit: " << p.getprice_per_unit() << " ,Quantity: " << p.getquantity() << " ,Exp.Date " << p.expirydate << " ,FoodType " << p.gettype() << endl; 
		return os;
	}
	bool iselectronics()
	{
		return false;
	}

};
#endif
