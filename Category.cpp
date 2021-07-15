#include "Category.h"

Category::Category(const string& name) : name(name) {
	nextId[0] += 1;
	this->id = nextId;
}
Category::~Category() {}

const string Category::getName() const {
	return this->name;
}

string Category::getId() const {
	return this->id;
}

const set<Item*>& Category::getItems() const {
	return *items;
}

void Category::addItem(Item* item) {
	this->items->insert(item);
}

void Category::deleteItem(Item* item) {
	this->items->erase(item);
}

ostream& operator<<(ostream& out, const Category& category) {
	set<Item*> items = category.getItems();
	out << "Category: " << category.getName();

	for (set<Item*>::iterator it = items.begin(); it != items.end(); ) {
		cout << ' ' << *(*it);
	}
		return out;
}

string Category::nextId = "0 Category";