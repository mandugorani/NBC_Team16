#include "Shop.h"
#include "Character.h"
#include "Item.h"
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
        cout << "\n=== 상점 ===" << endl;
        Character.displayStatus();
        cout << endl << endl;
        cout << "1. 아이템 구매" << endl;
        cout << "2. 아이템 판매" << endl;
        cout << "3. 상점 나가기" << endl;

        cout << "원하는 작업을 선택하세요: ";
        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "상점을 나갑니다." << endl;
            break;
        }

        if (choice == 1) {
            // 아이템 구매
            cout << "\n구매 가능한 아이템 목록:" << endl;
            for (size_t i = 0; i < shopItems.size(); ++i) {
                cout << i + 1 << ". " << shopItems[i]->getName()
                    << " - " << shopItems[i]->getPrice() << "G" << endl;
            }
            cout << shopItems.size() + 1 << ". 뒤로 가기" << endl;

            cout << "구매할 아이템 번호를 선택하세요: ";
            int itemChoice;
            cin >> itemChoice;

            if (itemChoice == shopItems.size() + 1) {
                continue;
            }

            if (itemChoice < 1 || itemChoice > shopItems.size()) {
                cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = shopItems[itemChoice - 1];
            if (Character.gold >= selectedItem->getPrice()) {
                Character.gold -= selectedItem->getPrice();
                inventory.push_back(selectedItem);
                cout << selectedItem->getName() << "을(를) 구매했습니다!" << endl;
            }
            else {
                cout << "골드가 부족합니다!" << endl;
            }
        }
        else if (choice == 2) {
            // 아이템 판매
            if (inventory.empty()) {
                cout << "인벤토리가 비어 있습니다!" << endl;
                continue;
            }

            cout << "\n판매 가능한 아이템 목록:" << endl;
            for (size_t i = 0; i < inventory.size(); ++i) {
                cout << i + 1 << ". " << inventory[i]->getName()
                    << " - " << inventory[i]->getPrice() / 2 << "G (판매 가격)" << endl;
            }
            cout << inventory.size() + 1 << ". 뒤로 가기" << endl;

            cout << "판매할 아이템 번호를 선택하세요: ";
            int sellChoice;
            cin >> sellChoice;

            if (sellChoice == inventory.size() + 1) {
                continue;
            }

            if (sellChoice < 1 || sellChoice > inventory.size()) {
                cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = inventory[sellChoice - 1];
            int sellPrice = selectedItem->getPrice() / 2;
            Character.gold += sellPrice;
            inventory.erase(inventory.begin() + sellChoice - 1);

            cout << selectedItem->getName() << "을(를) " << sellPrice
                << "G에 판매했습니다!" << endl;
        }
        else {
            cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
        }
    }
}
