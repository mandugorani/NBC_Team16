#pragma once

#include <string>
#include <iostream>
#include "Inventory.h"

// 헤더에는 선언만
class Character
{
public:
    std::string name;       // 캐릭터 이름
    int level;              // 레벨
    int currentHealth;      // 현재 체력
    int maxHealth;          // 최대 체력
    int attackPower;        // 공격력
    int experience;         // 경험치
    int experienceToLevelUp; // 레벨업에 필요한 경험치
    int gold;               // 소지금
    int maxMana;            // 최대 마나
    int currentMana;        // 현재 마나
    int monstersDefeated;   // 처치한 몬스터 수

    // 생성자
    Character(std::string charName);

    // 캐릭터 상태 출력 함수
    void displayStatus();

    // 경험치 얻기
    void gainExperience(int exp);

    // 레벨업 함수
    void levelUp();

    // 스킬 사용 함수
    void useSkill(const std::string& skillName, int manaCost);

    // 몬스터 처치 카운트 증가
    void defeatMonster();

    Inventory myInventory;
};