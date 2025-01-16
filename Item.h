#pragma once

#include <string>
#include <iostream>

using namespace std;

class Character;

class Item
{
public:
    virtual ~Item() {}
    virtual string getName() const = 0; // 아이템 이름 반환
    virtual int getPrice() const = 0;  // 아이템 가격 반환
    virtual void use(Character& Character) const = 0; // 아이템 효과 적용
};

class SmallHealthPotion : public Item
{
public:
    string getName() const override;
    int getPrice() const override;
    void use(Character& Character) const override;
};

class LargeHealthPotion : public Item
{
public:
    string getName() const override;
    int getPrice() const override;
    void use(Character& Character) const override;
};

class ManaPotion : public Item
{
public:
    string getName() const override;
    int getPrice() const override;
    void use(Character& Character) const override;
};

class AttackBoost : public Item
{
public:
    string getName() const override;
    int getPrice() const override;
    void use(Character& Character) const override;
};