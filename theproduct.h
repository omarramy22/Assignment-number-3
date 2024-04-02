#include <iostream>
#include<string>
#ifndef theproduct_h
#define theproduct_h

using namespace std;
class product {
private:
	string name;
	float price_per_unit;
	int quantity;
	float initial_price = price_per_unit; 
	int initialquantity = quantity; 
public: 

	product(string n, float p, int q) : name(n), price_per_unit(p), quantity(q) {}
	product() {}; 

	void setname(string n)
	{
		name = n;
	}
	void setprice_per_unit(float p)
	{
		price_per_unit = p;
	}

	void setquantity(int q)
	{
		quantity = q;
	}

	float getinitialprice()
	{
		return initial_price; 
	}
	string getname()
	{
		return name;
	}
	float getprice_per_unit()
	{
		return price_per_unit;
	}
	int getquantity()
	{
		return quantity;
	}
	int getinitialquantity()
	{
		return initialquantity; 
	}
	virtual bool iselectronics()
	{
		return false; 
	}
	virtual int getwarranty() {
		return 0; 

	}

	friend std::ostream& operator<<(std::ostream& os, const product& p)
	{
		os << " Name: " << p.name << " ,Price per unit: " << p.price_per_unit << " ,Quantity: " << p.quantity;
		return os;
	}

};
#endif 

