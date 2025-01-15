#pragma once

#include <vector>
#include <memory>

#include "Item.h"
#include "Character.h"

class Item;
class Character;

class Inventory
{
public:
	void addItem(std::unique_ptr<Item> InItem);

	void useItem(Character& InCharacter);

	void showInventory() const;

private:
	std::vector<std::unique_ptr<Item>> items;

};

