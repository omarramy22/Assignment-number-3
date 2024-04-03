#include <iostream>
#include<string>
#include"theproduct.h"
#include "Productmanager.h"
#ifndef shoppingcart_h
#define shoppingcart_h
using namespace std;
template <class T>
class shoppingcart {
private: 
	vector <product> customerproducts;

	void add_for_update(product p)
	{
		customerproducts.push_back(p);
		cout << "the product " << p.getname() << " has been replaced " << endl;
	}
	void remove_for_update(product p)
	{
		for (int i = 0; i < customerproducts.size(); i++)
		{
			if (customerproducts.at(i).getname() == p.getname() && customerproducts.at(i).getprice_per_unit() == p.getprice_per_unit()) {
				customerproducts.erase(customerproducts.begin() + i);
				cout << "the product " << p.getname() << " has been updated " << endl;
			}
		}
	}

public:
	product getproduct(int i)
	{
		return customerproducts.at(i);
	}
	int getproductssize()
	{
		return customerproducts.size();
	}
	bool add(T &p, productmanager<product> &y, unsigned int quan)
	
	{
		for (int i = 0; i < y.getproductssize(); i++)
		{
			while (i < customerproducts.size()) 
			{
				if (customerproducts.at(i).getname() == p.getname())
				{
					cout << "This product already exist in your cart ";
					return false;
				}
			}
			if (y.getproduct(i).getname() == p.getname() && p.getquantity() < quan)
			{
				cout << "there isn't enough quantity, you will get the maximum offered " << endl;
				customerproducts.push_back(p);
				p.setquantity(0);
				y.update(p);
				return true; 

			}
			
			else if (y.getproduct(i).getname() == p.getname() && y.getproduct(i).getquantity() >= quan && quan != 0)
			{
				cout << "the quantity " << quan << " of the product " << p.getname() << " has been added to your cart " << endl;
				T x = p;
				x.setquantity(quan); 
				customerproducts.push_back(x);
				p.setquantity(p.getquantity() - quan);
				return true; 
			}
			
			

		}
		
	}
	void remove(T& p, productmanager<product>& y, unsigned int quan)

	{
		for (int i = 0; i < customerproducts.size(); i++)
		{
			 if (customerproducts.at(i).getname() == p.getname() && quan != 0)
			{
				cout << "the quantity " << quan << " of the product " << p.getname() << " has been removed from your cart " << endl; 
				customerproducts.at(i).setquantity(customerproducts.at(i).getquantity() - quan);
				p.setquantity(p.getquantity() + quan);
				y.update(p);
			}
		}

	}
	void display()
	{
		for (int i = 0; i < customerproducts.size(); i++)
		{
			cout << customerproducts.at(i) << "\n";
		}
	}
	float getprice()
	{
		float sum = 0.0; 
		for (int i = 0; i < customerproducts.size(); i++)
		{
			sum += customerproducts.at(i).getquantity() * customerproducts.at(i).getprice_per_unit(); 
		}
		cout << "the total price for this cart is " << sum << endl; 
		return sum; 
	}

	bool update(product& x)
	{
		bool cond = false;
		for (int i =0; i<getproductssize(); i++)
		{
			if (getproduct(i).getname() == x.getname())
			{
				cond = true;
				cout << "Update!! to the shopping cart " << endl;
				remove_for_update(getproduct(i)); // removing the old object 
				add_for_update(x); // putting a new object with new specifications (price, quantity)
				return cond;
			}
			return cond;
			
		}
		
		if (cond == false)
			return cond; 
	}


};




#endif