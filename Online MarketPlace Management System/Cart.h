#pragma once
#include <stack>
#include "MarketingProduct.h"
class Cart
{
public:
	Cart();
	~Cart();
	void DisplayCarts(stack<MarketingProduct>);
};

