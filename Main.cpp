#include <iostream>
#include <set>
#include <string>
#include "Category.h"
#include "Item.h"
#include "Order.h"
#include "Customer.h"

int main() {
	Category *fruit = new Category("fruit");
	Category* plant = new Category("plant");

	Item* banana = new Item("banana", fruit);
	Item* potato = new Item("potato", plant);
	Item* tomato = new Item("tomato", plant);

	std::set<Item*> one;
	one.insert(banana);
	one.insert(potato);

	Customer* artem = new Customer("Artem");
	Order* first = new Order(artem, one);

	std::cout << artem->getId() << std::endl;

    std::cout << *artem << std::endl;

	std::cout << &Category::getId << std::endl;

	delete fruit;
	delete plant;
	delete banana;
	delete potato;
	delete tomato;
	delete artem;

	return 0;
}