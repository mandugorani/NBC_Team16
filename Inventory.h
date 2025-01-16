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
	std::vector<std::shared_ptr<Item>>& getItems() {
		return items;  // 아이템 목록을 반환
	}

private:
	vector<shared_ptr<Item>> items;

};

