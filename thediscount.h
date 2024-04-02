#include <iostream>
#include<string>
#include <stdlib.h>
#ifndef thediscount_h
#define thediscount_h
#include"theproduct.h"
#include "Productmanager.h"
#include "shoppingcart.h"

using namespace std;
class thediscount {
private: 
	int PERCENT;
	int FIXED;
	bool BOGO;
	string COUPON;
	string name; 


public:
	enum type { coupon, percentage, bogo, fixed } enumtype;
	thediscount(type t) : enumtype(t) {}

	 void setdiscount(string x)
	{ 
		
		if (enumtype == 0)
		{
			COUPON = x; 
			name = COUPON;
		

		}
		else if (enumtype == 1)
		{
			PERCENT = stoi(x); 
			name = to_string(PERCENT);
			
		}
		else if (enumtype == 2)
		{
				name = "bogo"; 
				
		}
		else if (enumtype == 3)
		{
			FIXED = stoi(x); 
			name = to_string(FIXED); 

		}
	}
	 string getname()
	 {
		 return name; 
	 }
	product applydiscount(product y)
	{
		product& s = y;   
		if (name == COUPON)
		{
			string hamo = COUPON.substr(8, 2);
			float c = stof(hamo);
			s.setprice_per_unit(s.getprice_per_unit() - s.getinitialprice() * c / 100);
			return s;

		}
		else if (name == to_string(PERCENT))
		{
			s.setprice_per_unit(s.getprice_per_unit() - s.getinitialprice() * PERCENT / 100);
			return s;
		}
		else if (name == "bogo")
		{
			if (s.getinitialprice() > 500)
				s.setprice_per_unit(s.getinitialprice() / 2);
			return s;
		}
		else if (name == to_string(FIXED))
		{
			if (FIXED < s.getprice_per_unit())
				s.setprice_per_unit(s.getprice_per_unit() - FIXED);
			else
				s.setprice_per_unit(0);

			return s;
		}
	}
	product operator- (product& z)
	{
		product& s = z;
		applydiscount(s); 
		return s; 
	}
	


}; 
#endif