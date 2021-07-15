#include "Customer.h"

Customer::Customer(const string& name) : name(name) {
	nextCustomerId[0] += 1;
	this->id = nextCustomerId;
}
Customer::~Customer() {};

const string& Customer::getName() const {
	return this->name;

}

string Customer::getId() const {
	return this->id;
}

const set<Order*>& Customer::getOrders() const{
	return *orders;
}

void Customer::addOrder(Order* order) {
	this->orders->insert(order);
}

ostream& operator<<(ostream& out, const Customer& customer) {
	set<Order*> orders = customer.getOrders();
	out << "Customer: " << customer.getName() << " has orders: ";

	for (set<Order*>::iterator it = orders.begin(); it != orders.end(); ) {
		out << ' ' << *(*it);
	}
	return out;
}

string Customer::nextCustomerId = "0 Customer";