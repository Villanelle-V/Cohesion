#include "Item.h"

Item::Item(const std::string& name, Category* category) {
	this->category = category;
	this->name = name;

	nextId[0] += 1;
	this->id = nextId;

	this->category->addItem(this);
}

Item::~Item() {}

const string& Item::getName() const {
	return this->name;
}

string Item::getId() const {
	return this->id;
}

const Category* Item::getCategory() const {
	return category;
}

const set<Order*>& Item::getOrders() const {
	return *orders;
}

void Item::addOrder(Order* order) {
	this->orders->insert(order);
}

void Item::deleteInOrder(Order* order) {
	this->orders->erase(order);
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
	set<Order*> orders = item.getOrders();
	out << "Item: " << item.getName() << " in Category: " << item.getCategory();

	for (set<Order*>::iterator it = orders.begin(); it != orders.end(); ) {
		cout << ' ' << *(*it);
	}
	return out;
}

string Item::nextId = "0 Item";

