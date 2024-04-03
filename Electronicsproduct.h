#include <iostream>
#include<string>
#include "theproduct.h"
#ifndef electronicsproduct_h 
#define electronicsproduct_h

using namespace std;
class electronicsproduct : public product
{
private: 
	float warranty; 
	string factory; 

public :
	enum electronicstype { laptop, mobile, watch } enumtype;
	electronicsproduct (string n, float p, int q, float w, string f, electronicstype t ) : product(n, p, q), warranty(w), factory(f), enumtype(t) {}
	electronicsproduct() {}; 

	void setwarranty(float w)
	{
		warranty = w; 
	}
	void setfactory(string f)
	{
		factory = f; 
	}
	float getwarranty() 
	{
		return warranty; 
	}
	string getfactory()
	{
		return factory; 
	}
	string gettype()
	{
		string x;
		if (enumtype == 0)
			x = "laptop ";
		else if (enumtype == 1)
			x = "mobile ";
		else if (enumtype == 2)
			x = "watch ";
		else
			x = "this product is not defined ";
		return x;
	}

	friend std::ostream& operator<<(std::ostream& os, electronicsproduct p)
	{
		os << " Name: " << p.getname() << " ,Price per unit: " << p.getprice_per_unit() << " ,Quantity: " << p.getquantity() << " ,Factory: " << p.factory << " ,Warranty " << p.warranty << " ,type " << p.gettype() << endl;
		return os;
	}
	bool iselectronics()
	{
		return true;
	}

}; 
#endif  

