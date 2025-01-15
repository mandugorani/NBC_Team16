#include "AllGameHeader.h"
#include <iostream>

using namespace std;

Character::Character(std::string charName)
{
    name = charName;
    level = 1;
    currentHealth = 200;
    maxHealth = 200;
    attackPower = 30;
    experience = 0;
    experienceToLevelUp = 100;  // ó���� 100 ����ġ�� ������
    gold = 0;
    maxMana = 50;
    currentMana = 50;
    monstersDefeated = 0; // ���� �� óġ ���� ���� 0
}

// ���� ����
void Character::displayStatus()
{
    cout << "\n=== �÷��̾� ���� ===" << endl;
    cout << "�̸�: " << name << endl;
    cout << "����: " << level << endl;
    cout << "����ġ: " << experience << "/" << experienceToLevelUp
        << " (���������� " << (experienceToLevelUp - experience) << " ����)" << endl;
    cout << "ü��: " << currentHealth << "/" << maxHealth << endl;
    cout << "����: " << currentMana << "/" << maxMana << endl;
    cout << "���ݷ�: " << attackPower << endl;
    cout << "���� ���: " << gold << "G" << endl;
    cout << "óġ�� ���� ��: " << monstersDefeated << endl;
    cout << "���� ������: " << endl;
}

// ����ġ ȹ��
void Character::gainExperience(int exp)
{
    experience += exp;
    std::cout << name << " ��(��) " << exp << " ����ġ�� ������ϴ�!" << std::endl;

    // ����ġ�� ����ϸ� ������
    while (experience >= experienceToLevelUp) {
        experience -= experienceToLevelUp;
        levelUp();
    }
}

// ������ ����
void Character::levelUp()
{
    if (level < 10) {
        level++;
        experienceToLevelUp = 100;  // ������ �� �ʿ��� ����ġ ����
        maxHealth += (level * 20);     // ������ �� ü�� ����
        attackPower += level * 5;    // ������ �� ���ݷ� ����
        currentHealth = maxHealth;  // ü���� �ִ� ü������ ȸ��
        maxMana += 10;    // �ִ� ����
        currentMana = maxMana;      // ���� ����
        cout << name << " ��(��) ���� " << level << " �� �������߽��ϴ�!" << std::endl;
    }
}

// ��ų ���
void Character::useSkill(const std::string& skillName, int manaCost)
{
    if (currentMana >= manaCost) { // ������ ����� ���
        currentMana -= manaCost;  // ���� ����
        cout << skillName << " ��ų�� ����߽��ϴ�! ���� " << manaCost << " �Ҹ�!" << std::endl;
        cout << "���� ����: " << currentMana << "/" << maxMana << std::endl;
    }
    else { // ������ ������ ���
        cout << "������ �����մϴ�! " << skillName << " ��ų�� ����� �� �����ϴ�." << std::endl;
    }
}

// ���� óġ
void Character::defeatMonster() {
    monstersDefeated++;
    std::cout << name << " ��(��) ���͸� óġ�߽��ϴ�! (�� óġ ��: "
        << monstersDefeated << ")" << std::endl;
    gainExperience(50);
}