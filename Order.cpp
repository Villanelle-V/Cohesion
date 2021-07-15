#include "Order.h"

Order::Order(Customer* customer, set<Item*>& item) {
	this->customer = customer;
	this->items = &item;

	nextId[0] += 1;
	this->id = nextId;
}

Order::~Order() {}

string Order::getId() const {
	return this->id;
}

const set<Item*>& Order::getItems() const {
	return *items;
}

const Customer* Order::getCustomer() const {
	return customer;
}

void Order::addItem(Item* item) {
	this->items->insert(item);
	item->addOrder(this);
	customer->addOrder(this);
}

void Order::deleteItem(Item* item) {
	this->items->erase(item);
	item->deleteInOrder(this);
}

ostream& operator<<(ostream& out, const Order& order) {
	set<Item*> items = order.getItems();
	out << "Order: " << order.getId();

	for (set<Item*>::iterator it = items.begin(); it != items.end(); ) {
		cout << ' ' << *(*it);
	}
	return out;
}

string Order::nextId = "0 order";