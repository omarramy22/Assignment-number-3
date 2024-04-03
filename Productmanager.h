#include <iostream>
#include <string>
#include<vector>
#include "Electronicsproduct.h"
#ifndef productmanager_h
#define productmanager_h
using namespace std;
template <class T> 
class productmanager {
private : 
	vector <T> products; 
	vector<T> arr; 
	string namecomparison(const string& x, const string& y)
	{
		int result = x.compare(y);
		if (result > 0) {
			return x;
		}
		else {
			return y;
		}

	}
public:
	
	productmanager() {}; 
	T getproduct(int i)
	{
		return products.at(i); 
	}
	int getproductssize()
	{
		return products.size(); 
	}


	void add(T p)
	{
		products.push_back(p);
		cout << "the product " << p.getname() << " has been added to the product manager " << endl;
	}
	void operator+ (product x)
	{
		add(x); 
	}
	void remove(T p)
	{
		for (int i = 0; i < products.size(); i++)
		{
			if (products.at(i).getname() == p.getname() && products.at(i).getprice_per_unit() == p.getprice_per_unit()) {
				products.erase(products.begin() + i);
				cout << "the product " << p.getname() << " has been deleted from the product manager " << endl;
			}
		}
	}
	void operator- (product x)
	{
		remove(x); 
	}
	
	void display()
	{ 
		for (int i = 0; i < products.size(); i++)
		{
			cout << "the product number " << i + 1 << " in your product manager is" << products.at(i) << "\n";
		}
	}
	void update(product& x)
	{
		bool cond = false;
		int count = 0;
		while (!cond)
		{
			if (getproduct(count).getname() == x.getname())
			{
				cond = true;
				cout << "Update!! " << endl; 
				remove(getproduct(count)); // removing the old object 
				add(x); // putting a new object with new specifications (price, quantity)
			}
			count++;
		}
	}
	vector <T> sort_by(string x)
	{
		if (x == "price" )
		{
			for (int i = 0; i < products.size() - 1; i++)
			{
				for (int j = 0; j < products.size() - 1 - i; j++)
				{
					if (products.at(j).getprice_per_unit() > products.at(j + 1).getprice_per_unit())
					{
						product x = products.at(j + 1);
						products.at(j + 1) = products.at(j);
						products.at(j) = x;
					}
				}
			}
			display(); 
			cout << endl;
			return products;
		}
		else if (x == "quantity")
		{
			for (int i = 0; i < products.size() - 1; i++)
			{
				for (int j = 0; j < products.size()- i - 1; j++)
				{
					if (products.at(j).getquantity() > products.at(j + 1).getquantity())
					{
						product x = products.at(j + 1);
						products.at(j + 1) = products.at(j);
						products.at(j) = x;
					}
				}
			}
			display();
			cout << endl;
			return products;
		}
		else if (x == "Name")
		{
			for (int i = 0; i < products.size() - 1; i++)
			{
				for (int j = 0; j < products.size() - i - 1; j++)
				{
					if (namecomparison(products.at(j).getname(), products.at(j + 1).getname()) == products.at(j).getname())
					{
						product x = products.at(j + 1);
						products.at(j + 1) = products.at(j);
						products.at(j) = x;
					}
				}
			}
			display();
			cout << endl; 
			return products;
		}
	}
	template <class T>
	float get_max_warranty()
	{

	}

	template<>
		float get_max_warranty() {
		float maxwarranty = 0.0; 
		for (int i =0; i<hu.getproductssize(); i++)
		{
			if (hu.getproduct(i).getwarranty() > maxwarranty)
				maxwarranty = hu.getproduct(i).getwarranty(); 

		}
		return maxwarranty;
	}

	
	friend std::ostream& operator<<(std::ostream& os, productmanager p)
	{
		p.display();
		return os; 
	}
};
#endif


