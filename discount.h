#include <iostream>
#include<string>
#include <stdlib.h>
#ifndef discount_h
#define discount_h
#include"theproduct.h"
#include "Productmanager.h"
using namespace std;
class discount {
private: 
	int percentage;
	int fixed;
	string d_fixed = "$" + to_string(fixed); 
	bool Bogo; 
	string coupon; 
public: 
	discount(int p = 0, int f = 0, bool b = false, string c = "Nilecart00") : percentage(p), fixed(f), Bogo(b), coupon(c) {}

	void setcoupon(string n)
	{
		coupon = n;
	}

	void setpercentage(int p)
	{
		percentage = p;
	}

	void setfixed(int f)
	{
		fixed = f; 
	}
	string getcoupon()
	{
		return coupon; 
	}
	float getpercentage()
	{
		return percentage; 
	}
	int getfixed()
	{
		return fixed;
	}
	product price_after_coupon(product &x)
	{
		string hamo = coupon.substr(8, 2); 
		float c = stof(hamo); 
		x.setprice_per_unit(x.getprice_per_unit() - x.getinitialprice() * c / 100); 
		return x; 
	}
	product price_after_percentage(product& x)
	{
		x.setprice_per_unit(x.getprice_per_unit() - x.getinitialprice() * percentage / 100);
		return x;
	}

	product price_after_fixed(product& x)
	{
		if (fixed < x.getprice_per_unit())
			x.setprice_per_unit(x.getprice_per_unit() - fixed);
		else
			x.setprice_per_unit(0); 
		
		return x;
	}
	product price_after_discount(product& x)
	{
		price_after_coupon(x);
		price_after_percentage(x);
		price_after_fixed(x);
		return x; 
	}
	product operator- (product& z)
	{ 
		price_after_coupon(z);
		price_after_percentage(z); 
		price_after_fixed(z); 
		return z; 
	}
};
#endif
