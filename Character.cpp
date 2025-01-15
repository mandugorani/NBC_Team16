#include "Character.h"

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
	characterInventory = std::make_unique<Inventory>();
}

void Character::displayStatus()
{
    std::cout << "�̸�: " << name << ", ����: " << level << ", ü��: " << currentHealth << "/" << maxHealth << ", ���ݷ�: " << attackPower << ", ����ġ: " << experience << "/" << experienceToLevelUp << std::endl;

    characterInventory->showInventory();
}

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

void Character::levelUp()
{
    if (level < 10) {
        level++;
        experienceToLevelUp += 100;  // ������ �� �ʿ��� ����ġ ����
        maxHealth += level * 20;     // ������ �� ü�� ����
        attackPower += level * 5;    // ������ �� ���ݷ� ����
        currentHealth = maxHealth;  // ü���� �ִ� ü������ ȸ��
        maxMana += (level * 10);    // �ִ� ����
        currentMana;        // ���� ����
        std::cout << name << " ��(��) ���� " << level << " �� �������߽��ϴ�!" << std::endl;
    }
}

void Character::useSkill(const std::string& skillName, int manaCost)
{
    std::cout << skillName << " ��ų�� ����߽��ϴ�! ���� " << manaCost << " �Ҹ�!" << std::endl;
}
