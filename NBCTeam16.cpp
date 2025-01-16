#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AllGameHeader.h"
#include "Title.h"

using namespace std;

int main()
{
	
    srand(static_cast<unsigned int>(time(0)));
    titleDraw();
    BattleManager::GetBattleManager().startGame();

    return 0;
}