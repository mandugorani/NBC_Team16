#include "Title.h"
#include <iostream>
#include "AllGameHeader.h"

using namespace std;

void titleDraw() {

    system("mode con:cols=100 lines=30 | title Game Title");
    cout << endl << endl << endl << endl;
    cout << "                            ##          #         ############    " << endl;
    cout << "                             #         #               ##         " << endl;
    cout << "                             #        # #            #    #       " << endl;
    cout << "                             #       #    #         #   #  #      " << endl;
    cout << "                             #       #    #             #         " << endl;
    cout << "                             #        # #         #############   " << endl;
    cout << endl << endl << endl << endl << endl << endl;
    cout << "                                      1. Start Game" << endl;
    cout << "                                      2. Exit Game" << endl;
    cout << endl << endl << endl << endl;
    cout << "                                      Choice: ";
    int choice;
    cin >> choice;

    if (choice == 2) {
        cout << "Exiting the game." << endl;
        exit(0); // 프로그램 종료
    }
    else if (choice == 1) {
        cout << "Starting the game!" << endl;
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        titleDraw();
    }

}
