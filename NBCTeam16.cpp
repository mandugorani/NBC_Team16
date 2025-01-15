#include <iostream>
#include "AllGameHeader.h"

using namespace std;

// ĳ���� Ŭ������ �����Ѵٸ�?
void battleStart(Character& player);

// ���� �Լ�
void startGame();
void battle(Character& player);
void generateItem(Character& player);

int main()
{
    srand(time(0));
    startGame();

    return 0;
}

void startGame() {
    string name;
    cout << "ĳ������ �̸��� �Է��ϼ���: ";
    getline(cin, name);

    while (name.empty() || name.find(' ') != string::npos) {
        cout << "ĳ������ �̸��� ������ ���� �� �����ϴ�: ";
        getline(cin, name);
    }

    Character player(name);
    cout << "ĳ���� ���� �Ϸ�!" << endl;
    player.displayStatus();

    // ĳ���� ���� �� ����
    while (player.level < 10) {
        battleStart(player);
    }

    // ������ �����ϴ°� ����
    cout << "�����մϴ�! " << player.name << " ���� 10 �޼�!" << endl;
    cout << "���� ���� ����:" << endl;
    Monster boss = generateBossMonster();
    cout << "���� �̸�: " << boss.name << " HP: " << boss.health << ", ���ݷ�: " << boss.attackPower << endl;

    // �ؿ� ������ �ڵ� �߰�(�ٸ��������? �����������?)
}

void battleStart(Character& player) {
    char choice;
    while (true) {
        cout << "������ �����Ͻðڽ��ϱ�? (Y/N): ";
        cin >> choice;
        choice = toupper(choice); // ��ҹ��� ���� ���ֱ�

        if (choice == 'Y') {
            battle(player);
            break;
        }
        else if (choice == 'N') {
            cout << "������ �ǳʶٰ� ���� ������ ���ư��ϴ�." << endl;
            break;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. Y �Ǵ� N�� �Է����ּ���." << endl;
        }
    }
}

void battle(Character& player) {
    Monster enemy = generateRandomMonster(player.level);
    cout << enemy.name << "���� ����! HP: " << enemy.health << ", ���ݷ�: " << enemy.attackPower << endl;

    while (enemy.health > 0) {
        // Player attack
        enemy.health -= player.attackPower;
        cout << player.name << " ��(��) " << enemy.name << "��(��) ����! ���� HP : " << enemy.health << endl;

        // Check if monster is defeated
        if (enemy.health <= 0) {
            cout << "�¸�!" << endl;
            player.gainExperience(50); // ����ġ�� 50 ��´ٰ� ����
            player.gold += enemy.goldDrop; // ���Ϳ� ������ ��� ��   
            cout << player.name << " ��(��) " << enemy.goldDrop << " ��带 ȹ���߽��ϴ�!" << endl;
            generateItem(player); // ������ ��� �Լ� ȣ��
            break;
        }

        // ����(������)
        player.currentHealth -= enemy.attackPower;
        cout << enemy.name << "�� ����" << player.name << " �� HP�� " << player.currentHealth << "�� ����!" << endl;

        // �й��
        if (player.currentHealth <= 0) {
            cout << player.name << " �� �й��߽��ϴ�." << endl;
            exit(0);
        }
    }
}

void generateItem(Character& player) {
    if (rand() % 100 < 30) { // 30%
        int itemEffect = rand() % 2; // 0: ü�� ȸ��, 1: ���ݷ� ����
        if (itemEffect == 0) {
            player.currentHealth += 50;
            if (player.currentHealth > player.maxHealth) {
                player.currentHealth = player.maxHealth; // ü�� �ʰ� ����
            }
            cout << "ü���� ȸ�����ִ� ������ �߰�! ü�� ȸ�� �� ü��: " << player.currentHealth << endl;
        }
        else {
            player.attackPower += 10;
            cout << "���ݷ��� �÷��ִ� ������ �߰�! �� ���ݷ�: " << player.attackPower << endl;
        }
    }
    else {
        cout << "�������� ����." << endl;
    }
}