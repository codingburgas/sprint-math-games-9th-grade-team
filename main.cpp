#include <iostream>
#include <string>
using namespace std;
int main() {
mainmenu: {
    cout << "Main menu" << endl;
    cout << "1. Play" << endl;
    cout << "\n2. About us" << endl;
    cout << "\n3. Leaderboard" << endl;
    cout << " " << endl;
    int mainchoose;
    do {
        cin >> mainchoose;
    } while (mainchoose != 1 && mainchoose != 2 && mainchoose != 3);

    switch (mainchoose) {  // choosing options
    case(1): {
        system("CLS");
        cout << "CHOOSE YOUR LEVEL:" << endl;
        cout << "\n1. EASY" << endl;
        cout << "\n2. MEDIUM" << endl;
        cout << "\n3. HARD" << endl;
        cout << "\n4. How To Play:" << endl;
        cout << "\nType 5 to exit to main menu : " << endl;
        int gamechoose;
        cin >> gamechoose;
        while (gamechoose != 1 && gamechoose != 2 && gamechoose != 3 && gamechoose != 4 && gamechoose != 5) {
            cin >> gamechoose;
        }
        switch (gamechoose) {
        case(1): {
            cout << "easy"; // easy
        }
        case(2): {
            cout << "easy";// medium
        }
        case(3): {
            cout << "easy";// hard
        }
        }
    case(5): {
        system("CLS");
        goto mainmenu;
    }



           break;
    }
    case(2): {
        system("CLS");
        cout << "About us" << endl;
        cout << "Our team:" << endl;
        cout << "\nOur team is comprised of some very masterful individuals:" << endl;
        cout << "\nMartin:  our scum trainer and leader;" << endl;
        cout << "\nDenis: our backend developer;" << endl;
        cout << "\nStelian: one of our designers and frontend developer;" << endl;
        cout << "\nStanimir: one of our designers and tester." << endl;
        cout << "Type 5 to exit to main menu: ";
        int choose;
        cin >> choose;
        while (choose != 5) {
            cin >> choose;
        }
        system("CLS");
        goto mainmenu;

        break;
    }
    case(3): {
        system("CLS");
        cout << "How to play";
        break;
        goto mainmenu;
    }
    }
    }
}