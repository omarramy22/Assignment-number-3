


#include <iostream>
#include<string>
#include <vector>
#include"foodproduct.h"
#include "Electronicsproduct.h"
#include "booksproduct.h"
#include "thediscount.h"
#include "Productmanager.h"
#include "shoppingcart.h"
#include"order.h"
using namespace std; 
int main()
{
	booksproduct book1("Alchemist", 40, 100, "Couelo", booksproduct::novel); 
	electronicsproduct elect1("Ideapad", 600, 5, 2, "Lenovo ", electronicsproduct::laptop); 
	foodproduct food1("Mango", 10, 25, 5, foodproduct::fruit); 
	foodproduct food2("Apple", 50, 20, 10, foodproduct::fruit); 
	electronicsproduct elect2("Xiaomi", 1000, 10, 3, "Xiaomi", electronicsproduct::mobile); 
	thediscount d1(thediscount::coupon);
	thediscount d2(thediscount::bogo);
	productmanager <product> p1;
	p1.add(elect1);
	p1.add(food1);
	p1.add(book1);
	p1.add(food2);
	p1.add(elect2);
	p1.sort_by("price");
	p1.sort_by("Name"); 
	p1.sort_by("quantity"); 
	p1 - elect2; 
	p1 + elect2; 
	cout << p1; 
	shoppingcart <booksproduct>cart1; 
	shoppingcart <foodproduct>cart2;
	shoppingcart <electronicsproduct>cart3;
	shoppingcart <booksproduct>cart4;
	shoppingcart <foodproduct>cart5;
	shoppingcart <electronicsproduct>cart6;
	cart1.add(book1, p1, 2); 
	cart2.add(food1, p1, 1);
	cart3.add(elect1, p1, 2); 
	cart5.add(food2, p1, 3); 
	order del1(cart6, cart1, cart2); 
	order del2(cart3, cart4, cart5); 
	del1.display(); 
	del2.display(); 
	d1.setdiscount("Nilecart25");
	d2.setdiscount("bogo");
	del1.add_discounts(d1); 
	del1.applydiscounts(cart1); 
	del2.add_discounts(d2);
	del2.applydiscounts(cart3); 
	del1.display(); 
	del1.checkout(); 
	del2.display(); 
	del2.checkout();

}

