#include <iostream>
#include<string>
#ifndef order_h
#define order_h
#include"theproduct.h"
#include "Productmanager.h"
#include "shoppingcart.h"
#include "thediscount.h"
#include "Electronicsproduct.h"
#include "foodproduct.h"
#include "booksproduct.h"
using namespace std; 
class order {
private :
	int Id; 
	shoppingcart <electronicsproduct> elec_cart; 
	shoppingcart <booksproduct> book_cart;
	shoppingcart <foodproduct> food_cart;
	vector <thediscount> arr; 
	static int count;
public: 
	order(shoppingcart <electronicsproduct> elec, shoppingcart <booksproduct> book, shoppingcart <foodproduct> food) : elec_cart(elec), book_cart(book), food_cart(food){
		Id = count;
		count++; 
	}
	void setshoppingcart_elec(shoppingcart <electronicsproduct> elec)
	{
		elec_cart = elec; 
	}
	void setshoppingcart_book(shoppingcart <booksproduct> book)
	{
		book_cart = book;
	}
	void setshoppingcart_food(shoppingcart <foodproduct> food)
	{
		food_cart = food;
	}
	shoppingcart <electronicsproduct> getelec_cart()
	{
		return elec_cart; 
	}
	shoppingcart <foodproduct> getfood_cart()
	{
		return food_cart;
	}
	shoppingcart <booksproduct> getbook_cart()
	{
		return book_cart;
	}
	void add_discounts(thediscount d1)
	{
		arr.push_back(d1); 
	}
	void display()
	{
		cout << " This is the details of the order with ID " << Id << endl; 
		elec_cart.display(); 
		food_cart.display(); 
		book_cart.display(); 
	}
	template <typename T>
	 void applydiscounts(shoppingcart<T> &x)
	{
		string code; 
		bool cond = false; 
			for (int j = 0; j < arr.size(); j++)
			{
				while (cond == false) {
					cout << "write the product you want to apply the discount " << arr.at(j).getname() << " ";
					cin >> code;
					for (int i = 0; i < x.getproductssize(); i++)
					{
						if (code == x.getproduct(i).getname())
						{
							product z = arr.at(j).applydiscount(x.getproduct(i));
							x.update(z);
							elec_cart.update(z); 
							food_cart.update(z); 
							book_cart.update(z); 
							arr.erase(arr.begin() + j);
							cond = true;
						}

					}
					if (cond == false)
					{
						cout << "This product isn't in the shopping cart " << endl;

					}
				}
			}		
	}

	 

	  void checkout()
	  {
		  cout << "the total money to be paid for the order with id " << Id << " is " << elec_cart.getprice() + food_cart.getprice() + book_cart.getprice() << endl; 
	  }

};
int order::count = 1;
#endif
