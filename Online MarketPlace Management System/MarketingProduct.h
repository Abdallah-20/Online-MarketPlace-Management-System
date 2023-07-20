#pragma once
#include<string>
using namespace std;
class MarketingProduct
{
public:
    int Id;
	int SellersId;
	float Price;
	string Name, Category;
	MarketingProduct();
	MarketingProduct(int , string , string , float);
};

