
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
}

void BattleManager::battleStart(Character& player) {
	char choice;
	while (true) {
		cout << "Do you Want to: " << endl;
		cout << "1. Battle" << endl;
		cout << "2. Visit Shop" << endl;
		cout << "3. Display Status" << endl;
		cout << "4. Exit Game" << endl;

		cin >> choice;
		choice = toupper(choice); // 대소문자 구분 없애기

		switch (choice) {
		case '1':
			if (player.level >= 10) {
				// 레벨이 10 이상일 때 보스 등장 로직
				cout << "Congrats! " << player.name << " Achieved Level 10!" << endl;
				cout << "BOSS APPEARED:" << endl;
				Monster boss = generateBossMonster(); // 보스를 생성하는 함수 호출
				cout << "Boss name: " << boss.name << " HP: " << boss.health << ", ATK: " << boss.attackPower << endl;
				BossBattle(player, boss);

			}else{
				battle(player);
			}
			break;
		case '2':
			shop(player, player.myInventory.getItems());
			break;
		case '3':
			player.displayStatus();
			break;
		case '4':
			cout << "Game Over." << endl;
			exit(0);
		default:
			cout << "Invalid input." << endl;
			break;

		}
	}
}

void BattleManager::battle(Character& player) {
	Monster enemy = generateRandomMonster(player.level); // 이 메서드도 정의 필요
	cout << enemy.name << " Monster appears! HP: " << enemy.health << ", ATK: " << enemy.attackPower << endl;

	while (enemy.health > 0) {
		// Player attack (choice)
		cout << "1. Attack, 2. Use Skill, 3. Use Item" << endl; //
		int choice;
		cin >> choice;

		if (choice == 1) { // 공격을 선택
			enemy.health -= player.attackPower;
			cout << player.name << " Attacked " << enemy.name << "! remaining HP: " << enemy.health << endl;
		}
		else if (choice == 2) { // 스킬을 선택
			player.useSkill("Power strike"); // 스킬 사용 함수를 호출
			enemy.health -= player.attackPower * 2; // 스킬이 하나밖에 없으며 공격력의 2배만큼의 데미지를 준다고 가정
			cout << player.name << " used Power Strike on " << enemy.name << "! remaining HP: " << enemy.health << endl;
		}
		else if (choice == 3) { // 아이템을 선택
			player.myInventory.useItem(player); // 아이템 사용 함수를 호출
		}
		else {
			cout << "Invalid input." << endl;
			continue;
		}

		if (enemy.health <= 0) {
			player.defeatMonster();
			cout << "Victory!" << endl;
			player.gold += enemy.goldDrop;
			cout << player.name << " earned " << enemy.goldDrop << " gold!" << endl;
			generateItem(player);
			break;
		}

		player.currentHealth -= enemy.attackPower;
		cout << enemy.name << " attacks! " << player.name << "'s HP decreased to " << player.currentHealth << "!" << endl;

		if (player.currentHealth <= 0) {
			cout << player.name << " Defeated." << endl;
			exit(0);
		}
	}
}

void BattleManager::BossBattle(Character& player, Monster& boss) {
	while (boss.health > 0) {
		cout << "1. Attack, 2. Use Skill, 3. Use Item" << endl;
		int choice;
		cin >> choice;

		if (choice == 1) { // 공격을 선택
			boss.health -= player.attackPower;
			cout << player.name << " Attacked " << boss.name << "! remaining HP: " << boss.health << endl;
		}
		else if (choice == 2) { // 스킬을 선택
			player.useSkill("Power strike"); // 스킬 사용
			boss.health -= player.attackPower * 2; // 스킬로 증가된 데미지
			cout << player.name << " used Power Strike on " << boss.name << "! remaining HP: " << boss.health << endl;
		}
		else if (choice == 3) { // 아이템을 선택
			player.myInventory.useItem(player); // 아이템 사용
		}
		else {
			cout << "Invalid input." << endl;
			continue;
		}

		if (boss.health <= 0) {
			cout << "You have defeated the Boss!" << endl;
			player.defeatMonster();
			// 보스 처치 시?
			break;
		}
		player.currentHealth -= boss.attackPower;
		cout << boss.name << " attacks! " << player.name << "'s HP decreased to " << player.currentHealth << "!" << endl;

		if (player.currentHealth <= 0) {
			cout << player.name << " Defeated." << endl;
			exit(0);
		}
	}
}


void BattleManager::generateItem(Character& player) {
	if (rand() % 100 < 30) { // 30%
		int itemEffect = rand() % 4; // 0:체력포션(소), 1:체력포션(대), 2:마나포션, 3:공격력증가
		shared_ptr<Item> item;

		switch (itemEffect) {
		case 0:
			item = make_shared<SmallHealthPotion>();
			cout << "Found Lesser Health Potion!" << endl;
			break;
		case 1:
			item = make_shared<LargeHealthPotion>();
			cout << "Found Health Potion!" << endl;
			break;
		case 2:
			item = make_shared<ManaPotion>();
			cout << "Found Mana Potion!" << endl;
			break;
		case 3:
			item = make_shared<AttackBoost>();
			cout << "Found Attack Boost!" << endl;
			break;
		}
		player.myInventory.addItem(item);

	}
	else {
		cout << "No item found." << endl;
	}
}