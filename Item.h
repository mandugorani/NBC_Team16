#pragma once

#include <string>
#include "Character.h" //@TODO: 살펴봐야함.

using namespace std;

class Item 
{
public:
    virtual ~Item() {}
    virtual string getName() const = 0; // 아이템 이름 반환
    virtual int getPrice() const = 0;  // 아이템 가격 반환
    virtual void use(Character& Character) const = 0; // 아이템 효과 적용
};

// 체력 포션(소) 클래스
class SmallHealthPotion : public Item 
{
public:
    string getName() const override 
    {
        return "체력 포션(소)";
    }

    int getPrice() const override 
    {
        return 30;
    }

    void use(Character& Character) const override 
    {
        int healAmount = 80;
        //Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
        //cout << "체력이 " << healAmount << "만큼 회복되었습니다. (현재 체력: "
        //    << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
    }
};

// 체력 포션(대) 클래스
class LargeHealthPotion : public Item 
{
public:
    string getName() const override {
        return "체력 포션(대)";
    }

    int getPrice() const override {
        return 60;
    }

    void use(Character& Character) const override {
        int healAmount = 200;
        //Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
        //cout << "체력이 " << healAmount << "만큼 회복되었습니다. (현재 체력: "
        //    << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
    }
};

// 마나 포션 클래스
class ManaPotion : public Item {
public:
    string getName() const override {
        return "마나 포션";
    }

    int getPrice() const override {
        return 30;
    }

    void use(Character& Character) const override {
        int manaAmount = 100;
        //Character.mana = min(Character.mana + manaAmount, Character.maxMana);
        //cout << "마나가 " << manaAmount << "만큼 회복되었습니다. (현재 마나: "
        //    << Character.mana << "/" << Character.maxMana << ")" << endl;
    }
};

// 공격력 강화 클래스
class AttackBoost : public Item {
public:
    string getName() const override {
        return "공격력 강화";
    }

    int getPrice() const override {
        return 50;
    }

    void use(Character& Character) const override {
        //Character.attackPower = static_cast<int>(Character.attackPower * 1.5);
        //cout << "공격력이 강화되었습니다! (현재 공격력: " << Character.attackPower << ")" << endl;
    }
};