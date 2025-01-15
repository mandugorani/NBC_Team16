#include "Shop.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// ���� �Լ�
void shop(Character& Character, vector<shared_ptr<Item>>& inventory)
{
    vector<shared_ptr<Item>> shopItems = {
        make_shared<SmallHealthPotion>(),
        make_shared<LargeHealthPotion>(),
        make_shared<ManaPotion>(),
        make_shared<AttackBoost>(),
    };

    while (true) {
        cout << "\n=== ���� ===" << endl;
        Character.displayStatus();
        cout << endl << endl;
        cout << "1. ������ ����" << endl;
        cout << "2. ������ �Ǹ�" << endl;
        cout << "3. ���� ������" << endl;

        cout << "���ϴ� �۾��� �����ϼ���: ";
        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "������ �����ϴ�." << endl;
            break;
        }

        if (choice == 1) {
            // ������ ����
            cout << "\n���� ������ ������ ���:" << endl;
            for (size_t i = 0; i < shopItems.size(); ++i) {
                cout << i + 1 << ". " << shopItems[i]->getName()
                    << " - " << shopItems[i]->getPrice() << "G" << endl;
            }
            cout << shopItems.size() + 1 << ". �ڷ� ����" << endl;

            cout << "������ ������ ��ȣ�� �����ϼ���: ";
            int itemChoice;
            cin >> itemChoice;

            if (itemChoice == shopItems.size() + 1) {
                continue;
            }

            if (itemChoice < 1 || itemChoice > shopItems.size()) {
                cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = shopItems[itemChoice - 1];
            if (Character.gold >= selectedItem->getPrice()) {
                Character.gold -= selectedItem->getPrice();
                inventory.push_back(selectedItem);
                cout << selectedItem->getName() << "��(��) �����߽��ϴ�!" << endl;
            }
            else {
                cout << "��尡 �����մϴ�!" << endl;
            }
        }
        else if (choice == 2) {
            // ������ �Ǹ�
            if (inventory.empty()) {
                cout << "�κ��丮�� ��� �ֽ��ϴ�!" << endl;
                continue;
            }

            cout << "\n�Ǹ� ������ ������ ���:" << endl;
            for (size_t i = 0; i < inventory.size(); ++i) {
                cout << i + 1 << ". " << inventory[i]->getName()
                    << " - " << inventory[i]->getPrice() / 2 << "G (�Ǹ� ����)" << endl;
            }
            cout << inventory.size() + 1 << ". �ڷ� ����" << endl;

            cout << "�Ǹ��� ������ ��ȣ�� �����ϼ���: ";
            int sellChoice;
            cin >> sellChoice;

            if (sellChoice == inventory.size() + 1) {
                continue;
            }

            if (sellChoice < 1 || sellChoice > inventory.size()) {
                cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
                continue;
            }

            shared_ptr<Item> selectedItem = inventory[sellChoice - 1];
            int sellPrice = selectedItem->getPrice() / 2;
            Character.gold += sellPrice;
            inventory.erase(inventory.begin() + sellChoice - 1);

            cout << selectedItem->getName() << "��(��) " << sellPrice
                << "G�� �Ǹ��߽��ϴ�!" << endl;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }
}
