#pragma once

#include <string>
#include "Character.h" //@TODO: ���������.

using namespace std;

class Item 
{
public:
    virtual ~Item() {}
    virtual string getName() const = 0; // ������ �̸� ��ȯ
    virtual int getPrice() const = 0;  // ������ ���� ��ȯ
    virtual void use(Character& Character) const = 0; // ������ ȿ�� ����
};

// ü�� ����(��) Ŭ����
class SmallHealthPotion : public Item 
{
public:
    string getName() const override 
    {
        return "ü�� ����(��)";
    }

    int getPrice() const override 
    {
        return 30;
    }

    void use(Character& Character) const override 
    {
        int healAmount = 80;
        //Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
        //cout << "ü���� " << healAmount << "��ŭ ȸ���Ǿ����ϴ�. (���� ü��: "
        //    << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
    }
};

// ü�� ����(��) Ŭ����
class LargeHealthPotion : public Item 
{
public:
    string getName() const override {
        return "ü�� ����(��)";
    }

    int getPrice() const override {
        return 60;
    }

    void use(Character& Character) const override {
        int healAmount = 200;
        //Character.currentHealth = min(Character.currentHealth + healAmount, Character.maxHealth);
        //cout << "ü���� " << healAmount << "��ŭ ȸ���Ǿ����ϴ�. (���� ü��: "
        //    << Character.currentHealth << "/" << Character.maxHealth << ")" << endl;
    }
};

// ���� ���� Ŭ����
class ManaPotion : public Item {
public:
    string getName() const override {
        return "���� ����";
    }

    int getPrice() const override {
        return 30;
    }

    void use(Character& Character) const override {
        int manaAmount = 100;
        //Character.mana = min(Character.mana + manaAmount, Character.maxMana);
        //cout << "������ " << manaAmount << "��ŭ ȸ���Ǿ����ϴ�. (���� ����: "
        //    << Character.mana << "/" << Character.maxMana << ")" << endl;
    }
};

// ���ݷ� ��ȭ Ŭ����
class AttackBoost : public Item {
public:
    string getName() const override {
        return "���ݷ� ��ȭ";
    }

    int getPrice() const override {
        return 50;
    }

    void use(Character& Character) const override {
        //Character.attackPower = static_cast<int>(Character.attackPower * 1.5);
        //cout << "���ݷ��� ��ȭ�Ǿ����ϴ�! (���� ���ݷ�: " << Character.attackPower << ")" << endl;
    }
};