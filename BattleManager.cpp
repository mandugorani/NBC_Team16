
#include "AllGameHeader.h"

using namespace std;

void BattleManager::startGame() {
    string name;
    cout << "Input Character Name: ";
    getline(cin, name);

    while (name.empty() || name.find(' ') != string::npos) {
        cout << "The character's name cannot be blank: ";
        getline(cin, name);
    }

    Character player(name);
    cout << "Character has been Created!" << endl;
    player.displayStatus();

    while (player.level < 10) {
        battleStart(player);
    }

    //cout << "축하합니다! " << player.name << " 레벨 10 달성!" << endl;
    //cout << "보스 몬스터 등장:" << endl;
    //Monster boss = generateBossMonster(); // 이 메서드도 구현이 필요함
    //cout << "보스 이름: " << boss.name << " HP: " << boss.health << ", 공격력: " << boss.attackPower << endl;
}

void BattleManager::battleStart(Character& player) {
    char choice;
    while (true) {
        cout << "Do Battle? (Y/N): ";
        cin >> choice;
        choice = toupper(choice); // 대소문자 구분 없애기

        if (choice == 'Y') {
            battle(player);
            break;
        }
        else if (choice == 'N') {
            cout << "Skip battle and return to the main loop. " << endl;
            break;
        }
        else {
            cout << "Invalid input, please enter Y or N." << endl;
        }
    }
}

void BattleManager::battle(Character& player) {
    Monster enemy = generateRandomMonster(player.level); // 이 메서드도 정의 필요
    cout << enemy.name << " Monster appers! HP: " << enemy.health << ", ATK: " << enemy.attackPower << endl;

    while (enemy.health > 0) {
        enemy.health -= player.attackPower;
        cout << player.name << " Attacked " << enemy.name << "! remaining enemy HP : " << enemy.health << endl;

        if (enemy.health <= 0) {
            cout << "Victory!" << endl;
            player.gainExperience(50);
            player.gold += enemy.goldDrop;
            cout << player.name << " earned " << enemy.goldDrop << " gold!" << endl;
            generateItem(player);
            break;
        }

        player.currentHealth -= enemy.attackPower;
        cout << enemy.name << "Attack! " << player.name << " 's HP decreased to " << player.currentHealth << "!" << endl;

        if (player.currentHealth <= 0) {
            cout << player.name << " Defeated." << endl;
            exit(0);
        }
    }
}

void BattleManager::generateItem(Character& player) {
    if (rand() % 100 < 30) { // 30%
        int itemEffect = rand() % 2; // 0: Health recovery, 1: Increase attack power
        if (itemEffect == 0) {
            player.currentHealth += 50;
            if (player.currentHealth > player.maxHealth) {
                player.currentHealth = player.maxHealth; // Prevent exceeding max health
            }
            cout << "Found a health recovery item! Health after recovery: " << player.currentHealth << endl;
        }
        else {
            player.attackPower += 10;
            cout << "Found an attack power increase item! Total attack power: " << player.attackPower << endl;
        }
    }
    else {
        cout << "No item found." << endl;
    }
}