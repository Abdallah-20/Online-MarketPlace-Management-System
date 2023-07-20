#include "Cart.h"
#include<stack>
#include "MarketingProduct.h"
#include <iostream>
using namespace std;
Cart::Cart(){}

Cart::~Cart() {

}

void Cart::DisplayCarts(stack<MarketingProduct> cartCust) {
	float totalPrice = 0;
	while (!cartCust.empty()) {
		cout << "The name of the product you made the order for : " <<cartCust.top().Name << endl;
		cout << "The price of the product you made the order for : " <<cartCust.top().Price << endl;
		totalPrice = totalPrice + cartCust.top().Price;
		cartCust.pop();
	}
	cout << "The total price of the products you made an order for : " <<totalPrice << endl;
}