#include "AllGameHeader.h"
#include <iostream>

using namespace std;

Character::Character(string charName)
{
	name = charName;
	level = 1;
	currentHealth = 200;
	maxHealth = 200;
	attackPower = 30;
	experience = 0;
	experienceToLevelUp = 100;  // 100 경험치로 레벨업
	gold = 0;
	maxMana = 50;
	currentMana = 50;
	monstersDefeated = 0; // 생성 시 처치 몬스터 수는 0

	// 히든 캐릭터 구현?
    if (name == "Sparta")
    {
        maxHealth += 200;
        currentHealth = maxHealth;
        attackPower += 20;
        cout << name << " is a hidden character!" << endl;
    }
}

// Current Status
void Character::displayStatus()
{
    cout << "\n=== Player Status ===" << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Experience: " << experience << "/" << experienceToLevelUp
        << " (Remaining to level up: " << (experienceToLevelUp - experience) << ")" << endl;
    cout << "Health: " << currentHealth << "/" << maxHealth << endl;
    cout << "Mana: " << currentMana << "/" << maxMana << endl;
    cout << "Attack Power: " << attackPower << endl;
    cout << "Gold: " << gold << "G" << endl;
    cout << "Monsters Defeated: " << monstersDefeated << endl;

    // Display current inventory information.
    myInventory.showInventory();
}

// Gain Experience
void Character::gainExperience(int exp)
{
    experience += exp;
    cout << name << " gained " << exp << " experience points!" << endl;

    // Level up if experience is sufficient
    while (experience >= experienceToLevelUp) {
        experience -= experienceToLevelUp;
        levelUp();
    }
}

// Level Up Implementation
void Character::levelUp()
{
    if (level < 10) {
        level++;
        experienceToLevelUp = 100;  // Increase required experience for level-up
        maxHealth += (level * 20);  // Increase health on level-up
        attackPower += level * 5;   // Increase attack power on level-up
        currentHealth = maxHealth;  // Restore health to max health
        maxMana += 10;              // Increase max mana
        currentMana = maxMana;      // Restore mana to max mana on level-up
        cout << name << " leveled up to level " << level << "!" << endl;
    }
}

// Use Skill
void Character::useSkill(const std::string& skillName)
{
    const int manaCost = 20;  // Fixed mana cost of 20

    if (currentMana >= manaCost) // If mana is sufficient
    {
        currentMana -= manaCost;  // Subtract mana
        cout << "Used Judgment Blade skill! Mana cost: " << manaCost << std::endl;
        cout << "Remaining mana: " << currentMana << "/" << maxMana << std::endl;
    }
    else { // If mana is insufficient
        cout << "Insufficient mana! Unable to use Judgment Blade skill." << std::endl;
    }
}


// Defeat Monster
void Character::defeatMonster()
{
    monstersDefeated++;
    cout << name << " defeated a monster! (Total defeated: "
        << monstersDefeated << ")" << endl;
    gainExperience(50);
}