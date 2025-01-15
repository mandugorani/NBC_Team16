
#include "AllGameHeader.h"

using namespace std;

void BattleManager::startGame() {
    string name;
    cout << "캐릭터의 이름을 입력하세요: ";
    getline(cin, name);

    while (name.empty() || name.find(' ') != string::npos) {
        cout << "캐릭터의 이름에 공백을 넣을 수 없습니다: ";
        getline(cin, name);
    }

    Character player(name);
    cout << "캐릭터 생성 완료!" << endl;
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
        cout << "전투를 시작하시겠습니까? (Y/N): ";
        cin >> choice;
        choice = toupper(choice); // 대소문자 구분 없애기

        if (choice == 'Y') {
            battle(player);
            break;
        }
        else if (choice == 'N') {
            cout << "전투를 건너뛰고 메인 루프로 돌아갑니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. Y 또는 N을 입력해주세요." << endl;
        }
    }
}

void BattleManager::battle(Character& player) {
    Monster enemy = generateRandomMonster(player.level); // 이 메서드도 정의 필요
    cout << enemy.name << " 몬스터 등장! HP: " << enemy.health << ", 공격력: " << enemy.attackPower << endl;

    while (enemy.health > 0) {
        enemy.health -= player.attackPower;
        cout << player.name << " 이(가) " << enemy.name << "을(를) 공격! 남은 HP : " << enemy.health << endl;

        if (enemy.health <= 0) {
            cout << "승리!" << endl;
            player.gainExperience(50);
            player.gold += enemy.goldDrop;
            cout << player.name << " 이(가) " << enemy.goldDrop << " 골드를 획득했습니다!" << endl;
            generateItem(player);
            break;
        }

        player.currentHealth -= enemy.attackPower;
        cout << enemy.name << "의 공격! " << player.name << " 의 HP가 " << player.currentHealth << "로 감소!" << endl;

        if (player.currentHealth <= 0) {
            cout << player.name << " 가 패배했습니다." << endl;
            exit(0);
        }
    }
}

void BattleManager::generateItem(Character& player) {
    if (rand() % 100 < 30) { // 30%
        int itemEffect = rand() % 2; // 0: 체력 회복, 1: 공격력 증가
        if (itemEffect == 0) {
            player.currentHealth += 50;
            if (player.currentHealth > player.maxHealth) {
                player.currentHealth = player.maxHealth; // 체력 초과 방지
            }
            cout << "체력을 회복해주는 아이템 발견! 체력 회복 후 체력: " << player.currentHealth << endl;
        }
        else {
            player.attackPower += 10;
            cout << "공격력을 올려주는 아이템 발견! 총 공격력: " << player.attackPower << endl;
        }
    }
    else {
        cout << "아이템이 없다." << endl;
    }
}