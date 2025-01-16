#include "AllGameHeader.h"

#include <iostream>
using namespace std;

void Inventory::addItem(const shared_ptr<Item>& item)
{
    items.push_back(item);
    cout << "Added " << item->getName() << " to inventory.\n";
}

void Inventory::useItem(Character& character)
{
    if (items.empty()) {
        cout << "Inventory is empty!\n";
        return;
    }

    cout << "\n=== Inventory ===" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i]->getName() << endl;
    }
    cout << items.size() + 1 << ". Exit\n";

    cout << "Select the item number you want to use: ";
    int choice;
    cin >> choice;

    if (choice == items.size() + 1) {
        cout << "Closing inventory.\n";
        return;
    }

    if (choice < 1 || choice > items.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    items[choice - 1]->use(character);
    items.erase(items.begin() + (choice - 1)); // Remove after use
}

void Inventory::showInventory() const
{
    cout << "\n=== Current Inventory ===\n";
    if (items.empty()) {
        cout << "Inventory is empty.\n";
    }
    else {
        for (const auto& item : items) {
            cout << "- " << item->getName() << endl;
        }
    }
}

