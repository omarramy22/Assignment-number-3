


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
	thediscount d1(thediscount::fixed);
	thediscount d2(thediscount::coupon);
	productmanager <product> p1;
	p1.add(elect1);
	p1.add(food1);
	p1.add(book1);
	p1.add(food2);
	p1.add(elect2);
	p1.sort_by("price");
	p1.sort_by("quantity"); 
	p1.sort_by("Name"); 
	p1 - elect2; 
	p1 + elect2; 
	d1.setdiscount("10");
	d2.setdiscount("NileCart50 ");
	shoppingcart <booksproduct>cart1; 
	shoppingcart <foodproduct>cart2;
	shoppingcart <electronicsproduct>cart3;
	cart1.add(book1, p1, 2); 
	cart2.add(food1, p1, 2);
	cart3.add(elect1, p1, 1); 
	cout << p1.get_max_warranty(); 


	

 

	
	
	
	

}

