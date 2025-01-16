#include "AllGameHeader.h"
#include <algorithm>

using namespace std;

string Item::getName() const {
    return "";
}

int Item::getPrice() const {
    return 0;
}

void Item::use(Character& Character) const {
    // 아무 동작도 안 함 (워닝 없애는 용도)
}

// 체력 포션(소) 구현
string SmallHealthPotion::getName() const {
    return "Lesser Health Potion";
}

int SmallHealthPotion::getPrice() const {
    return 30;
}

void SmallHealthPotion::use(Character& Character) const {
    int healAmount = 80;
    Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
    cout << "Restored " << healAmount << "HP. Current HP: ("
        << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
}

// 체력 포션(대) 구현
string LargeHealthPotion::getName() const {
    return "Health potion";
}

int LargeHealthPotion::getPrice() const {
    return 60;
}

void LargeHealthPotion::use(Character& Character) const {
    int healAmount = 200;
    Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
    cout << "Restored " << healAmount << "HP. Current HP: ("
        << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
}

// 마나 포션 구현
string ManaPotion::getName() const {
    return "Mana Potion";
}

int ManaPotion::getPrice() const {
    return 30;
}

void ManaPotion::use(Character& Character) const {
    int manaAmount = 100;
    Character.currentMana = min(Character.currentMana + manaAmount, Character.maxMana);
    cout << "restored " << manaAmount << "mana. Current mana: ("
        << Character.currentMana << "/" << Character.maxMana << ")" << endl;
}

// 공격력 강화 구현
string AttackBoost::getName() const {
    return "Increase Attack Power";
}

int AttackBoost::getPrice() const {
    return 50;
}

void AttackBoost::use(Character& Character) const {
    Character.attackPower = static_cast<int>(Character.attackPower * 1.5);
    cout << "ATK increased! current atk: (" << Character.attackPower << ")" << endl;
}
