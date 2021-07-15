#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <set>
#include "Item.h"
#include "Customer.h"

using namespace std;

class Customer;
class Item;

class Order {
private:
	string id;
	set<Item*>* items;
	Customer* customer;
public:
	static string nextId;
	Order(Customer* customer, set<Item*>& items);
	~Order();
	string getId() const;
	const set<Item*>& getItems() const;
	const Customer* getCustomer() const;
	void addItem(Item* item);
	void deleteItem(Item* item);
};

ostream& operator<<(ostream& out, const Order& order);

#endif //ORDER_H
