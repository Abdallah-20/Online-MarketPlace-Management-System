#pragma once
#include <string>
#include <vector>
#include "MarketingProduct.h"
#include "Cart.h"
using namespace std;
class Customers
{
public:
	static int Id;
	int Phone;
	string Name, Email, Address;
	Customers();
	Customers( string , string , string , int);
	void Login(vector<Customers> , vector<MarketingProduct> , vector<string>);
	void Register(vector<Customers>, vector<MarketingProduct>, vector<string>);
	void AddProducts(vector<MarketingProduct>);
	void DisplayCategories(vector<string>);
	void Browse(vector<MarketingProduct> , vector<string>);
	void Menu1(vector<Customers> , vector<MarketingProduct> , vector<string>);
	void Menu2(vector<MarketingProduct>, vector<string>);
};

