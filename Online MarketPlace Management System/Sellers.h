#pragma once
#include <string>
using namespace std;
class LoginOperation {
public:
	string inputName, inputEmail;
	void Login();
	LoginOperation();
	LoginOperation(string, string);
};

class RegisterOperation {
public :
	static int id;
	string name, email;
	void Register();
	RegisterOperation();
	RegisterOperation(string , string);
};

class Sellers
{
public:
	Sellers();
	void AddProducts();
	void MainPageWebsite();
};

