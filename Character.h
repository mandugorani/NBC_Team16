#pragma once

#include <string>
#include <iostream>
#include "Inventory.h"

// ������� ����
class Character
{
public:
    std::string name;       // ĳ���� �̸�
    int level;              // ����
    int currentHealth;      // ���� ü��
    int maxHealth;          // �ִ� ü��
    int attackPower;        // ���ݷ�
    int experience;         // ����ġ
    int experienceToLevelUp; // �������� �ʿ��� ����ġ
    int gold;               // ������
    int maxMana;            // �ִ� ����
    int currentMana;        // ���� ����
    int monstersDefeated;   // óġ�� ���� ��

    // ������
    Character(std::string charName);

    // ĳ���� ���� ��� �Լ�
    void displayStatus();

    // ����ġ ���
    void gainExperience(int exp);

    // ������ �Լ�
    void levelUp();

    // ��ų ��� �Լ�
    void useSkill(const std::string& skillName, int manaCost);

    // ���� óġ ī��Ʈ ����
    void defeatMonster();

    Inventory myInventory;
};