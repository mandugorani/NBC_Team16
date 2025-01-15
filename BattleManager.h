#pragma once

class BattleManager
{
public:
	static BattleManager& GetBattleManager()
	{
		static BattleManager instance;
		return instance;
	}

private:
	BattleManager() {};
	~BattleManager() {};

};

