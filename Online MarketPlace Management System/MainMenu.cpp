#include "MainMenu.h"
#include<iostream>
#include "Sellers.h"
#include "MarketingProduct.h"
#include "Customers.h"
#include<vector>
#include<string>
#include<fstream>
using namespace std;

MainMenu::MainMenu() {
}

void MainMenu::MenuOfMarket() {
	vector<Customers> customers;
	vector<string> category;
	vector<MarketingProduct> products;
	int choose;
	cout << "\n";
	cout << "\t\t\t\t------------------------------------------------------\t\t\t\t\t";
	cout << "\t\t\t\t\tW e l c o m e  i n  O n l i n e  M a r k e t p l a c e\n";
	cout << "\t\t\t\t------------------------------------------------------\t\t\t\t\t";
	cout << "\n\n";
	cout << "\t\t\t\t1-Seller\n";
	cout << "\n";
	cout << "\t\t\t\t2-customar\n";
	cout << "\n";
	cout << "\t\t\t\t3-Exit\n";
	cout << "\n";
	cout << "\t\t\t\tEnter Your Choose :";
	cin >> choose;

	if (choose == 1) {
		system("cls");
		Sellers s;
		s.MainPageWebsite();
	}
	else if (choose == 2) {
		system("cls");
		ifstream Fruits("Fruits.txt", ios::app);
		ifstream Vegetables("Vegetables.txt", ios::app);
		ifstream Other("Other.txt", ios::app);
		int loadprice, loadIdProduct, loadSellerId;
		string loadCate, loadName;
		Customers customer1("ali", "123ali", "nasrcity", 01001452);
		customers.push_back(customer1);
		Customers customer2("ganna", "246ganna", "newcairo", 1248564);
		customers.push_back(customer2);
		Customers cust;
		category.push_back("fruits");
		category.push_back("vegetables");
		category.push_back("other");

		while (Fruits >> loadIdProduct >> loadName >> loadprice >> loadCate >> loadSellerId) {
			MarketingProduct P(loadIdProduct, loadName, loadCate, loadprice);
			products.push_back(P);
		}
		while (Vegetables >> loadIdProduct >> loadName >> loadprice >> loadCate >> loadSellerId) {
			MarketingProduct P(loadIdProduct, loadName, loadCate, loadprice);
			products.push_back(P);
		}
		while (Other >> loadIdProduct >> loadName >> loadprice >> loadCate >> loadSellerId) {
			MarketingProduct P(loadIdProduct, loadName, loadCate, loadprice);
			products.push_back(P);
		}
		cust.Menu1(customers, products, category);
	}
}