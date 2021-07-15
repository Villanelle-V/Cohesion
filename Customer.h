#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <set>
#include "Order.h"

using namespace std;

class Order;

class Customer {
private:
	string name;
	set<Order*>* orders;
	string id;
public:
	static string nextCustomerId;
	Customer(const string& name);
	~Customer();
	const string& getName() const;
	string getId() const;
	const set<Order*>& getOrders() const;
	void addOrder(Order* order);
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif //CUSTOMER_H
