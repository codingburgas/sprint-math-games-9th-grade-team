#include <iostream>
#include <string>
using namespace std;

int main() {
mainmenu: {
    // Simple ASCII Art Header for Main Menu
    cout << "        <=-=================================================================================================-=>" << endl;
    cout << endl;
    cout << "          ____    ____        _        _________   ____  ____       _______      _______      ______   " << endl;
    cout << "         |_   \\  /   _|      / \\      |  _   _  | |_   ||   _|     |_   __ \\    |_   __ \\   .' ___  |  " << endl;
    cout << "           |   \\/   |       / _ \\     |_/ | | \\_|   | |__| |         | |__) |     | |__) | / .'   \\_|  " << endl;
    cout << "           | |\\  /| |      / ___ \\        | |       |  __  |         |  __ /      |  ___/  | |   ____  " << endl;
    cout << "          _| |_\\/_| |_   _/ /   \\ \\_     _| |_     _| |  | |_       _| |  \\ \\_   _| |_     \\ `.___]  | " << endl;
    cout << "         |_____||_____| |____| |____|   |_____|   |____||____|     |____| |___| |_____|     `._____.'  " << endl;
    cout << endl;
    cout << endl;
    cout << "        <=-=================================================================================================-=>" << endl;
    cout << endl;
    cout << "                                      ,--.   ,--. ,------. ,--.  ,--. ,--. ,--.  " << endl;
    cout << "                                      |   `.'   | |  .---' |  ,'.|  | |  | |  |   " << endl;
    cout << "                                      |  |'.'|  | |  `--,  |  |' '  | |  | |  |  " << endl;
    cout << "                                      |  |   |  | |  `---. |  | `   | '  '-'  '  " << endl;
    cout << "                                      `--'   `--' `------' `--'  `--'  `-----'   " << endl;


    cout << endl;
    cout << "                                                \033[32m - 1. PLAY\033[0m" << endl;
    cout << "                                                \033[31m - 2. ABOUT US\033[0m" << endl;
    cout << "                                                \033[33m - 3. LEADERBOARD\033[0m" << endl;
    cout << endl;

    cout << "        <=-=================================================================================================-=>" << endl;
    cout << endl;

    cout << "                                             \033[36m< | > Choose an option : \033[0m";

    int mainchoose;
    do {
        cin >> mainchoose;
    } while (mainchoose != 1 && mainchoose != 2 && mainchoose != 3);

    switch (mainchoose) {
    case 1: {
        system("CLS");
        cout << "\n======================================" << endl;
        cout << "         Choose Your Level           " << endl;
        cout << "======================================" << endl;
        cout << "\n1. EASY" << endl;
        cout << "2. MEDIUM" << endl;
        cout << "3. HARD" << endl;
        cout << "4. How To Play" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "======================================" << endl;
        cout << "Choose an option: ";

        int gamechoose;
        do {
            cin >> gamechoose;
        } while (gamechoose < 1 || gamechoose > 5);

        switch (gamechoose) {
        case 1: cout << "\n*** Easy Level Selected ***\n"; break;
        case 2: cout << "\n*** Medium Level Selected ***\n"; break;
        case 3: cout << "\n*** Hard Level Selected ***\n"; break;
        case 4: cout << "\n*** How to Play Instructions ***\n"; break;
        case 5: system("CLS"); goto mainmenu;
        }
        break;
    }
    case 2: {
        system("CLS");
        cout << "\n======================================" << endl;
        cout << "              About Us               " << endl;
        cout << "======================================" << endl;
        cout << "Our team is comprised of talented individuals:" << endl;
        cout << "- Martin: Scum Trainer and Leader" << endl;
        cout << "- Denis: Backend Developer" << endl;
        cout << "- Stelian: Designer & Frontend Developer" << endl;
        cout << "- Stanimir: Designer & Tester" << endl;
        cout << "======================================" << endl;
        cout << "Type 5 to return to Main Menu: ";

        int choose;
        do {
            cin >> choose;
        } while (choose != 5);

        system("CLS");
        goto mainmenu;
    }
    case 3: {
        system("CLS");
        cout << "\n======================================" << endl;
        cout << "            Leaderboard               " << endl;
        cout << "======================================" << endl;
        cout << "Here you will see the top players!" << endl;
        cout << "======================================" << endl;
        cout << "Type 5 to return to Main Menu: ";

        int choose;
        do {
            cin >> choose;
        } while (choose != 5);

        system("CLS");
        goto mainmenu;
    }
    }
    }
}
