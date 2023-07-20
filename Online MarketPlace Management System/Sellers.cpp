#include "Sellers.h"
#include "MarketingProduct.h"
#include <list>
#include "MainMenu.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
Sellers::Sellers() {}

int RegisterOperation::id = 0;
string CheckNameSeller;

RegisterOperation::RegisterOperation(string name , string email) {
	this->name = name;
	this->email = email;
	id++;
}


LoginOperation::LoginOperation(){}
LoginOperation::LoginOperation(string name , string email) {
	inputName = name;
	inputEmail = email;
}
void LoginOperation::Login() {
	int exist = -1;
	cout << "\n\n";
	cout << "\t\t\t\t\t----------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\t  Welcome in Login process\n";
	cout << "\t\t\t\t\t----------------------------\t\t\t\t\t\n";
	do {
		int loadId;
		string loadName, loadEmail , inputSellerName , inputSellerEmail;
		cout << "\t\t\t\tEnter Name : ";
		cin >> inputSellerName;
		cout << "\t\t\t\tEnter Email : ";
		cin >> inputSellerEmail;
		ifstream input("SaveData.txt", ios::app);
		while (input >> loadId >> loadName >> loadEmail)
		{
			vector<LoginOperation> loadAllDataOfseller;
			LoginOperation LoginCheck;
			LoginOperation storageDataSeller(loadName , loadEmail);
			loadAllDataOfseller.push_back(storageDataSeller);
			for (int i = 0; i < loadAllDataOfseller.size(); i++) {
				LoginCheck = loadAllDataOfseller.at(i);
			}
			if (LoginCheck.inputName == inputSellerName && LoginCheck.inputEmail == inputSellerEmail) {
				exist = 1;
				break;
			}
		}
		input.close();
		if (exist == 1) {
			system("cls");
			cout << "\n\n";
			cout << "\t\t\t\tHello " << inputSellerName << " in our website Now you can add product\n";
			CheckNameSeller = inputSellerName;
			Sellers S;
			S.AddProducts();
		}
		else {
			cout << "\t\t\t\tSorry,Your name and email incorrect , please Enter correct data\n";
		}

	} while (exist != 1);
}

void RegisterOperation::Register() {

	int loadId ,exist = -1;
	string AddName, AddEmail, loadName, loadEmail;
	list<RegisterOperation> SaveDataSeller;
	cout << "\n\n";
	cout << "\t\t\t\t\t----------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\tWelcome Back Please Register\t\t\t\t\t\n";
	cout << "\t\t\t\t\t----------------------------\t\t\t\t\t\n";

	cout << "\t\t\tEnter Your Name: ";
	cin >> AddName;

	cout << "\t\t\tEnter Your Email: ";
	cin >> AddEmail;

	RegisterOperation registerOperation(AddName, AddEmail);
	SaveDataSeller.push_back(registerOperation);

	ofstream reg("SaveData.txt", ios::app);
	for (auto li : SaveDataSeller) {
		reg << li.id << ' ' << li.name << ' ' << li.email << endl;
	}
	reg.close();
}

void Sellers::MainPageWebsite() {
	int choose;
	cout << "\n\n";
	cout << "\t\t\t\t\t-----------------------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\t\tWelcome in Seller Window\t\t\t\t\t\n";
	cout << "\t\t\t\t\t-----------------------------------------\t\t\t\t\t\n";
	cout << "\n";
	cout << "\t\t\tPLEASE CHOOSE THE OPERATION YOU WANT TO ABLE TO ADD PRODUCT :\n";
	cout << "\t\t\t1-Log in\n";
	cout << "\t\t\t2-Register\n";
	cout << "\t\t\tEnter your Choose :";
	cin >> choose;
	if (choose == 1) {
		system("cls");
		LoginOperation loginPage;
		loginPage.Login();
	}
	else if (choose == 2) {
		RegisterOperation registerPage;
		system("cls");
		registerPage.Register();
		system("cls");
		MainPageWebsite();
	}
}

void Sellers::AddProducts() {
	MarketingProduct P;
	int exist = 0, loadidseller;
	string loadname, loademail;
	list<MarketingProduct> SaveProducts;
	ofstream Fruits("Fruits.txt" , ios::app);
	ofstream Vegetables("Vegetables.txt", ios::app);
	ofstream Other("Other.txt", ios::app);
	char choice;
	cout << "\n\n";
	cout << "\t\t\t\t\t------------------------------\t\t\t\t\t\n";
	cout << "\t\t\t\t\tWelcome in Add Product Window\t\t\t\t\t\n";
	cout << "\t\t\t\t\t------------------------------\t\t\t\t\t\n";
	do {

		cout << "\t\t\t\t\tEnter Product Id: ";
		cin >> P.Id;

		cout << "\t\t\t\t\tEnter Product Name: ";
		cin >> P.Name;

		cout << "\t\t\t\t\tEnter Product Price: ";
		cin >> P.Price;

		cout << "\t\t\t\t\tEnter Product Category: ";
		cin >> P.Category;
		do {
			cout << "\t\t\t\t\tEnter your Seller Id: ";
			cin >> P.SellersId;
			ifstream checksellerId("SaveData.txt");

			while (checksellerId >> loadidseller >> loadname >> loademail) {
				vector<int> loadid;
				loadid.push_back(loadidseller);
				for (int i = 0; i < loadid.size(); i++) {
					if (loadname == CheckNameSeller) {
						if (loadid.at(i) == P.SellersId) {
							exist = 1;
							break;
						}
					}
					break;
				}
			}
			if (exist == 1) {
				SaveProducts.push_back(P);
			}
			else {
				cout << "\t\t\t\t\tPlease Enter Correct Id\n";
			}
		} while (exist != 1);
		
		cout << "\t\t\t\tDo you want to add another product? (Y / N) :";
		cin >> choice;

		if (P.Category == "Fruits" || P.Category == "fruits") {
			Fruits << P.Id << ' ' << P.Name << ' ' << P.Price << ' ' << P.Category << ' ' << P.SellersId << endl;
		}
		else if (P.Category == "Vegetables" || P.Category == "vegetables") {
			Vegetables << P.Id << ' ' << P.Name << ' ' << P.Price << ' ' << P.Category << ' ' << P.SellersId << endl;
		}
		else{
			Other << P.Id << ' ' << P.Name << ' ' << P.Price << ' ' << P.Category << ' ' << P.SellersId << endl;
		}
		cout << "\t\t\t\tThank you, product has been successfully added " << endl;

	} while (choice == 'Y' || choice == 'y');
	system("cls");
	MainMenu BackToMenu;
	BackToMenu.MenuOfMarket();
}

RegisterOperation::RegisterOperation(){}