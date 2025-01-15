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
    experienceToLevelUp = 100;  // 처음엔 100 경험치로 레벨업
    gold = 0;
    maxMana = 50;
    currentMana = 50;
    monstersDefeated = 0; // 생성 시 처치 몬스터 수는 0
}

// 현재 상태
void Character::displayStatus()
{
    cout << "\n=== 플레이어 상태 ===" << endl;
    cout << "이름: " << name << endl;
    cout << "레벨: " << level << endl;
    cout << "경험치: " << experience << "/" << experienceToLevelUp
        << " (레벨업까지 " << (experienceToLevelUp - experience) << " 남음)" << endl;
    cout << "체력: " << currentHealth << "/" << maxHealth << endl;
    cout << "마나: " << currentMana << "/" << maxMana << endl;
    cout << "공격력: " << attackPower << endl;
    cout << "보유 골드: " << gold << "G" << endl;
    cout << "처치한 몬스터 수: " << monstersDefeated << endl;
    
    //  현재 인벤토리 정보를 표시합니다.
    myInventory.showInventory();
}

// 경험치 획득
void Character::gainExperience(int exp)
{
    experience += exp;
    std::cout << name << " 이(가) " << exp << " 경험치를 얻었습니다!" << std::endl;

    // 경험치가 충분하면 레벨업
    while (experience >= experienceToLevelUp) {
        experience -= experienceToLevelUp;
        levelUp();
    }
}

// 레벨업 구현
void Character::levelUp()
{
    if (level < 10) {
        level++;
        experienceToLevelUp = 100;  // 레벨업 시 필요한 경험치 증가
        maxHealth += (level * 20);     // 레벨업 시 체력 증가
        attackPower += level * 5;    // 레벨업 시 공격력 증가
        currentHealth = maxHealth;  // 체력은 최대 체력으로 회복
        maxMana += 10;    // 최대 마나
        currentMana = maxMana;      // 현재 마나
        cout << name << " 이(가) 레벨 " << level << " 로 레벨업했습니다!" << std::endl;
    }
}

// 스킬 사용
void Character::useSkill(const std::string& skillName, int manaCost)
{
    if (currentMana >= manaCost) { // 마나가 충분한 경우
        currentMana -= manaCost;  // 마나 차감
        cout << skillName << " 스킬을 사용했습니다! 마나 " << manaCost << " 소모!" << std::endl;
        cout << "남은 마나: " << currentMana << "/" << maxMana << std::endl;
    }
    else { // 마나가 부족한 경우
        cout << "마나가 부족합니다! " << skillName << " 스킬을 사용할 수 없습니다." << std::endl;
    }
}

// 몬스터 처치
void Character::defeatMonster() {
    monstersDefeated++;
    std::cout << name << " 이(가) 몬스터를 처치했습니다! (총 처치 수: "
        << monstersDefeated << ")" << std::endl;
    gainExperience(50);
}