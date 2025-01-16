#include "AllGameHeader.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// 상점 함수
void shop(Character& Character, vector<shared_ptr<Item>>& inventory)
{
    vector<shared_ptr<Item>> shopItems = {
        make_shared<SmallHealthPotion>(),
        make_shared<LargeHealthPotion>(),
        make_shared<ManaPotion>(),
        make_shared<AttackBoost>(),
    };

    while (true) {
        cout << "\n=== Shop ===" << endl;
        Character.displayStatus();
        cout << endl << endl;
        cout << "1. Buy Item" << endl;
        cout << "2. Sell Item" << endl;
        cout << "3. Exit Shop" << endl;

        cout << "Select the action you want: ";
        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the shop." << endl;
            break;
        }

        if (choice == 1) {
            // 아이템 구매
            cout << "\nAvailable items for purchase:" << endl;
            for (size_t i = 0; i < shopItems.size(); ++i) {
                cout << i + 1 << ". " << shopItems[i]->getName()
                    << " - " << shopItems[i]->getPrice() << "G" << endl;
            }
            cout << shopItems.size() + 1 << ". Go Back" << endl;

            cout << "Select the item number you want to buy: ";
            int itemChoice;
            cin >> itemChoice;

            if (itemChoice == shopItems.size() + 1) {
                continue;
            }

            if (itemChoice < 1 || itemChoice > shopItems.size()) {
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = shopItems[itemChoice - 1];
            if (Character.gold >= selectedItem->getPrice()) {
                Character.gold -= selectedItem->getPrice();
                inventory.push_back(selectedItem);
                cout << "Purchased " << selectedItem->getName() << "!" << endl;
            }
            else {
                cout << "Insufficient gold!" << endl;
            }
        }
        else if (choice == 2) {
            // 아이템 판매
            if (inventory.empty()) {
                cout << "Inventory is empty!" << endl;
                continue;
            }

            cout << "\nItems available for sale:" << endl;
            for (size_t i = 0; i < inventory.size(); ++i) {
                cout << i + 1 << ". " << inventory[i]->getName()
                    << " - " << inventory[i]->getPrice() / 2 << "G (Sale Price)" << endl;
            }
            cout << inventory.size() + 1 << ". Go Back" << endl;

            cout << "Select the item number you want to sell: ";
            int sellChoice;
            cin >> sellChoice;

            if (sellChoice == inventory.size() + 1) {
                continue;
            }

            if (sellChoice < 1 || sellChoice > inventory.size()) {
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = inventory[sellChoice - 1];
            int sellPrice = selectedItem->getPrice() / 2;
            Character.gold += sellPrice;
            inventory.erase(inventory.begin() + sellChoice - 1);

            cout << "Sold " << selectedItem->getName() << " for " << sellPrice
                << "G!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
