
#include "Item.h"
#include "AllGameHeader.h"
#include <algorithm>

using namespace std;

string Item::getName() const {
    return "";
}

int Item::getPrice() const {
    return 0;
}

// 체력 포션(소) 구현
string SmallHealthPotion::getName() const {
    return "체력 포션(소)";
}

int SmallHealthPotion::getPrice() const {
    return 30;
}

void SmallHealthPotion::use(Character& InCharacter) const 
{
    int healAmount = 80;
    InCharacter.currentHealth = min(InCharacter.currentHealth + healAmount, InCharacter.maxHealth);
    cout << "체력이 " << healAmount << "만큼 회복되었습니다. (현재 체력: "
        << InCharacter.currentHealth << "/" << InCharacter.maxHealth << ")" << endl;
}

// 체력 포션(대) 구현
string LargeHealthPotion::getName() const {
    return "체력 포션(대)";
}

int LargeHealthPotion::getPrice() const {
    return 60;
}

void LargeHealthPotion::use(Character& InCharacter) const {
    int healAmount = 200;
    InCharacter.currentHealth = min(InCharacter.currentHealth + healAmount, InCharacter.maxHealth);
    cout << "체력이 " << healAmount << "만큼 회복되었습니다. (현재 체력: "
        << InCharacter.currentHealth << "/" << InCharacter.maxHealth << ")" << endl;
}

// 마나 포션 구현
string ManaPotion::getName() const {
    return "마나 포션";
}

int ManaPotion::getPrice() const {
    return 30;
}

void ManaPotion::use(Character& InCharacter) const {
    int manaAmount = 100;
    InCharacter.currentMana = min(InCharacter.currentMana + manaAmount, InCharacter.maxMana);
    cout << "마나가 " << manaAmount << "만큼 회복되었습니다. (현재 마나: "
        << InCharacter.currentMana << "/" << InCharacter.maxMana << ")" << endl;
}

// 공격력 강화 구현
string AttackBoost::getName() const {
    return "공격력 강화";
}

int AttackBoost::getPrice() const {
    return 50;
}

void AttackBoost::use(Character& InCharacter) const {
    InCharacter.attackPower = static_cast<int>(InCharacter.attackPower * 1.5);
    cout << "공격력이 강화되었습니다! (현재 공격력: " << InCharacter.attackPower << ")" << endl;
}
