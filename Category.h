#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <set>
#include "Item.h"

using namespace std;

class Item;

class Category {
private:
	string name;
	set<Item*>* items;
	string id;
public:
	static string nextId;

	Category(const string& name);
	~Category();
	const string getName() const;
	string getId() const;
	const set<Item*>& getItems() const;
	void addItem(Item* item);
	void deleteItem(Item* item);
};

ostream& operator<<(ostream& out, const Category& category);

#endif //CATEGORY_H
