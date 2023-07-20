#include "Customers.h"
#include "MarketingProduct.h"
#include "Cart.h"
#include "MainMenu.h"
#include <string>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;
bool isfound = false;
int Customers::Id = 0;
Customers::Customers() {}

Customers::Customers( string name, string email , string address , int phone ) {
	
	Name = name;
	Email = email;
	Address = address;
	Phone = phone;
	Id++;
}

void Customers::Login(vector<Customers> customer , vector<MarketingProduct> product, vector<string> category) {
	do {
		string e, n;
		cout << "enter your name:" << " ";
		cin >> n;
		cout << "enter your email :" << " ";
		cin >> e;

		for (Customers C1 : customer) {
			if (n == C1.Name && e == C1.Email) {
				isfound = true;
				break;
			}
		}

		if (isfound) {
			cout << "Welcome" << " " << n << endl;
			system("cls");
			Menu2(product , category);
		}
		else
		{
			cout << "invalid credentials!\n";
		}
	} while (isfound != true);


}

void Customers::Register(vector<Customers> customer, vector<MarketingProduct> product, vector<string> category) {
	string customerName;
	string customerEmail;
	string customerAdreess;
	int phone;
	cout << "enter your information :\n";

	cout << "Enter your name:";
	cin >> customerName;

	cout << "Enter your email:";
	cin >> customerEmail;

	cout << "Enter your address:";
	cin >> customerAdreess;

	cout << "Enter your phone:";
	cin >> phone;
	cout << endl;

	cout << "your regesartion is conifrmed" << endl;
	Customers customerObj(customerName , customerEmail , customerAdreess ,phone);
	customer.push_back(customerObj);
	Login(customer , product , category);
}

void Customers::AddProducts(vector<MarketingProduct> addproduct) {
	int size;
	char ans;
	int flag = 0;
	int j;
	bool isprofound = false;
	stack<MarketingProduct> cartCustomer;
	Cart cart;
	cout << "How many products you want to buy : ";
	cin >> size;
	int* answers = new int[size];
	cout << "Enter the id of the product you want to buy" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter Id " << i + 1 << " :";
		cin >> answers[i]; // id for item
	}
	for (int i = 0; i < size; i++) {
		for (j = 0; j < addproduct.size(); j++) {
			if (answers[i] == addproduct[j].Id) {
				isprofound = true;
				break;
			}
		}
	}

	if (isprofound == true) {
		cartCustomer.push(addproduct[j]);
		flag = 0;
	}
	else if (isprofound == false) {
		cout << "This id is not available" << endl;
		flag = 1;
	}
	if (flag == 0) {
		cout << "Do you want to confirm your order : ";
		cin >> ans;

		if (ans == 'y' || ans == 'Y') {
			cart.DisplayCarts(cartCustomer);
		}
	}
	else {
		cout << "Do you want to continue purchasing : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {

			AddProducts(addproduct);

		}
	}
	/*int size;
	char ans;
	stack<MarketingProduct> cartCustomer;
	Cart cart;
	int flag = 0;
	int j = 0;
	bool isprofound = false;
	cout << "How many products you want to buy : ";
	cin >> size;
	int* answers = new int[size];
	cout << "Enter the id of the product you want to buy" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter Id "<< i + 1 << " :" ;
		cin >> answers[i];
	}
	for (int i = 0; i < size; i++) {
		for (j = 0; j < addproduct.size(); j++) {
			if (answers[i] == addproduct[j].Id) {
				isprofound = true;
				break;
			}
		}
	}
	if (isprofound == true) {
		cartCustomer.push(addproduct[j]);
		flag = 0;
		cout << addproduct[j].Id << endl;
	}else if (isprofound == false) {
		cout << "This id is not available" << endl;
		flag = 1;
	}

	if (flag == 0) {
		cout << "Do you want to confirm your order : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			cart.DisplayCarts(cartCustomer);
		}
	}
	else {
		cout << "Do you want to continue purchasing : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {

			AddProducts(addproduct);

		}
	}*/
}

void Customers::DisplayCategories(vector<string> category) {
	int size = category.size();
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "." << category.at(i) << "     ";
	}
	cout << endl;
}

void Customers::Browse(vector<MarketingProduct> product , vector<string> category) {
	string chosenCategory;
	bool isfound1 = false;
	char ans;
	cout << "Choose your category (1-3)" << endl;
	DisplayCategories(category);
	cin >> chosenCategory;
	for (string Category : category) {
		if (chosenCategory == Category) {
			isfound1 = true;
			break;
		}
	}
	if (isfound1 == true) {
		for (MarketingProduct pro : product) {
			if (chosenCategory == pro.Category) {
				cout << pro.Id<< "  " << pro.Name << "  " << pro.Price << "  " << endl;
			}
		}
		cout << "Do you want to make an order : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			AddProducts(product);
		}
		while (ans == 'y' || ans == 'Y') {


			cout << "Do want to make another order from the same category?(y/n)" << endl;
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				AddProducts(product);
			}

		}
	}
	else {
		cout << "Category not found" << endl;
		cout << "do you want to purchase from different category?";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			Menu2(product, category);
		}
	}
	cout << "do you want to purchase from different category?";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') {
		Menu2(product, category);
	}
	else {
		system("cls");
		MainMenu BackToMenu;
		BackToMenu.MenuOfMarket();
	}
}

void Customers::Menu1(vector<Customers> customer , vector<MarketingProduct> product  , vector<string> category ) {
	char ans;
	
		cout << "Please choose one of the options below:" << endl;
		cout << "1.Log in" << endl;
		cout << "2.Register" << endl;
		int answer;
		cin >> answer;
		switch (answer) {
		case 1:
			system("cls");
			Login(customer , product , category);
			break;
		case 2:
			Register(customer , product , category);
			break;
		}
}

void Customers::Menu2(vector<MarketingProduct> product, vector<string> category) {
	Browse(product, category);
}


