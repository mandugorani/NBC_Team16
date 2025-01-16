#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


class BattleManager
{
public:
	static BattleManager& GetBattleManager()
	{
		static BattleManager instance;
		return instance;
	}
	void startGame();
	void battleStart(Character& player);
	void battle(Character& player);
	void generateItem(Character& player);
	void BossBattle(Character& player, Monster& boss);
	void displayEndMessage();

private:
	BattleManager() {};
	~BattleManager() {};

};

