#pragma once

#include <string>
#include <vector>

using namespace std;

// ���� Ÿ�� ����ü ����
struct MonsterType
{
    string name;        // ���� �̸�
    int minHealth;      // �ּ� ü��
    int maxHealth;      // �ִ� ü��
    int minAttack;      // �ּ� ���ݷ�
    int maxAttack;      // �ִ� ���ݷ�
    int minGold;        // �ּ� ���
    int maxGold;        // �ִ� ���
    double spawnChance; // ���� Ȯ�� (%)

    MonsterType(const string& name, int minHealth, int maxHealth, int minAttack, int maxAttack, int minGold, int maxGold, double spawnChance);
};

// Monster Ŭ���� ����
class Monster
{
public:
    string name;    // ���� �̸�
    int health;     // ü��
    int attackPower;// ���ݷ�
    int goldDrop;   // ���

    //������ ����
    Monster(const string& MonsterName, int Level, int minHealth, int maxHealth, int minAttack, int maxAttack, int minGold, int maxGold);
};

// ���� ���� ����Ʈ ����
extern vector<MonsterType> monsterTypes;

// ������� ���� �־�� �Ѵ�
// ���� ���� �Լ� ����
int randRange(int min, int max);

// ���� ���� ���� �Լ� ����
Monster generateRandomMonster(int playerLevel);

// ���� ���� ����
Monster generateBossMonster();
