#pragma once

#include <vector>
#include <memory>
#include "Item.h"

class Inventory
{
public:
	void addItem(const shared_ptr<Item>& item);

	void useItem(Character& character);

	void showInventory() const;

private:
	vector<shared_ptr<Item>> items;

};

