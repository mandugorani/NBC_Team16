#pragma once

#include <string>
#include <iostream>

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

    // ������
    Character(std::string charName);

    // ĳ���� ���� ��� �Լ�
    void displayStatus();

    // ����ġ ���
    void gainExperience(int exp);

    // ������ �Լ�
    void levelUp();

    // ��ų ��� �Լ� (���÷� "Judgment Blade" ���)
    void useSkill(const std::string& skillName, int manaCost);

};

