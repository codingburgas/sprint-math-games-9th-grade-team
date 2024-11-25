#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void game(double levelMultiplier) {
    int waveCount = 10;
    for (int waveCounter = 1; waveCounter < waveCount;) {
        double enemyHP = 100 * levelMultiplier, enemyDMG = 99 * levelMultiplier;
        double miniBossHP = enemyHP * 1.5, miniBossDMG = enemyHP * 1.5;
        double finalBossHP = miniBossHP * 2, finalBossDMG = miniBossDMG * 2;
        double playerHP = 100, playerDMG = 100;
        bool miniBossWave, finalBossWave;
        bool playerMiss;
        int swrgn1 = rand() % 100;//generating random numbers for each case
        int swrgn2 = rand() % 100;
        int swrgn1Crit = rand() % 10;
        int swrgn2Crit = rand() % 10;
        int macergn1Crit = rand() % 100;
        int macergn2Crit = rand() % 10;
        int macergn1 = rand() % 10;
        int macergn2 = rand() % 10;
        while (enemyHP > 0) {
            srand((unsigned)time(NULL));
            int counter = 0, answer, rightAnswer, critAnswer, critRightAnswer;
            char exitChar;
            int chooseWpn;
            if (waveCounter == 5) {
                cout << "Wave 5" << endl;
                cout << "Mini Boss!" << endl;
                miniBossWave = true;
                finalBossWave = false;
            }
            if (waveCounter == 10) {
                cout << "Wave 10" << endl;
                cout << "Final Boss!" << endl;
                miniBossWave = false;
                finalBossWave = true;
            }
            else {
                cout << "Wave " << waveCounter << endl;
                miniBossWave = false;
                finalBossWave = false;
            }
            cout << "Choose your weapon" << endl;
            cout << "1. Sword" << endl;
            cout << "2. Mace" << endl;
            cout << "3. Check stats" << endl;
            cout << "4. What each weapon does" << endl;
            cin >> chooseWpn;
            system("CLS");
            switch (chooseWpn) {
            case 1: {
                system("CLS");
                cout << "You chose sword, so..." << endl;
                cout << "You have 3 tries!" << endl;
                cout << "Solve this: " << swrgn1 << " + " << swrgn2 << endl;
                cout << "Type your answer here: ";
                rightAnswer = swrgn1 + swrgn2;

                do {
                    cin >> answer;
                    counter++;
                    if (answer != rightAnswer) {
                        cout << "Wrong answer!" << endl;//adding if to output either try or tries
                        if (3 - counter == 1) {
                            cout << "1 try left!" << endl;
                            cout << "Type your answer here: ";
                        }
                        else if (3 - counter != 1) {
                            cout << 3 - counter << " tries left" << endl;
                            cout << "Type your answer here: ";
                        }
                        else if (answer != rightAnswer && counter == 3) {
                            break;
                        }
                    }
                } while (answer != rightAnswer && counter < 3);
                if (miniBossWave == false && finalBossWave == false) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << swrgn1Crit << " * " << swrgn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = swrgn1Crit * swrgn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            enemyHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << enemyHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            enemyHP -= playerDMG;
                            cout << "Enemy HP == " << enemyHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        enemyHP -= playerDMG;
                        cout << "Enemy HP == " << enemyHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= enemyDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (enemyHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << enemyHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (enemyHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << enemyDMG << endl;
                        playerHP -= enemyDMG;
                        cout << "Your HP == " << playerHP << endl;
                    }
                }
                else if (miniBossWave == true) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << swrgn1Crit << " * " << swrgn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = swrgn1Crit * swrgn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            miniBossHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << miniBossHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            miniBossHP -= playerDMG;
                            cout << "Enemy HP == " << miniBossHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        miniBossHP -= playerDMG;
                        cout << "Enemy HP == " << miniBossHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= miniBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (miniBossHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << miniBossHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (miniBossHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << miniBossDMG << endl;
                        playerHP -= miniBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        system("CLS");
                    }
                }
                else if (finalBossWave == true) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << swrgn1Crit << " * " << swrgn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = swrgn1Crit * swrgn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            finalBossHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << finalBossHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            finalBossHP -= playerDMG;
                            cout << "Enemy HP == " << finalBossHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        finalBossHP -= playerDMG;
                        cout << "Enemy HP == " << finalBossHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= finalBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (finalBossHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << finalBossHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (finalBossHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << finalBossDMG << endl;
                        playerHP -= finalBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        system("CLS");
                    }
                }
                if (playerHP <= 0) {
                    cout << "You Lose! Type r to return to main menu!" << endl;
                    waveCounter = 10;
                    cin >> exitChar;
                    if (exitChar == 'r') {
                        system("CLS");
                        break;
                    }
                }
                else if (playerHP > 0) {
                    break;
                }


            case 2: {
                system("CLS");
                cout << "You chose mace, and..." << endl;
                cout << "You have 2 tries!" << endl;
                cout << "Solve this: " << macergn1 << " * " << macergn2 << endl;
                cout << "Type your answer here: ";
                rightAnswer = macergn1 * macergn2;
                do {
                    cin >> answer;
                    counter++;
                    if (answer != rightAnswer) {
                        cout << "Wrong answer!" << endl;
                        cout << "1 try left!";
                    }
                    else if (answer != rightAnswer && counter == 2) {
                        break;
                    }

                } while (answer != rightAnswer && counter < 2);
                if (miniBossWave == false && finalBossWave == false) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << macergn1Crit << " * " << macergn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = macergn1Crit * macergn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            enemyHP -= playerDMG * 4;
                            cout << "Enemy HP == " << enemyHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            enemyHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << enemyHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        enemyHP -= playerDMG * 1.5;
                        cout << "Enemy HP == " << enemyHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= enemyDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (enemyHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << enemyHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (enemyHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << enemyDMG << endl;
                        playerHP -= enemyDMG;
                        cout << "Your HP == " << playerHP << endl;
                        system("CLS");
                    }
                }
                else if (miniBossWave == true) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << macergn1Crit << " * " << macergn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = macergn1Crit * macergn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            miniBossHP -= playerDMG * 4;
                            cout << "Enemy HP == " << miniBossHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            miniBossHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << miniBossHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        miniBossHP -= playerDMG * 1.5;
                        cout << "Enemy HP == " << miniBossHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= miniBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (miniBossHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << miniBossHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (miniBossHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << miniBossDMG << endl;
                        playerHP -= miniBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        system("CLS");
                    }
                }
                else if (finalBossWave == true) {
                    if (answer == rightAnswer && counter == 1) {
                        cout << "Perfect!" << endl;
                        cout << "Now's your chance to do critical damage!" << endl;
                        cout << macergn1Crit << " * " << macergn2Crit << endl;
                        cout << "Type your answer here: ";
                        critRightAnswer = macergn1Crit * macergn2Crit;
                        cin >> critAnswer;

                        if (critAnswer == critRightAnswer) {
                            cout << "Perfect!" << endl;
                            finalBossHP -= playerDMG * 4;
                            cout << "Enemy HP == " << finalBossHP << endl;
                            playerMiss = false;
                        }
                        else {
                            cout << "You didn't get it, but you got a hit" << endl;
                            finalBossHP -= playerDMG * 1.5;
                            cout << "Enemy HP == " << finalBossHP << endl;
                            playerMiss = false;
                        }
                    }
                    else if (answer == rightAnswer) {
                        cout << "Good hit!" << endl;
                        finalBossHP -= playerDMG * 1.5;
                        cout << "Enemy HP == " << finalBossHP << endl;
                        playerMiss = false;
                    }
                    else {
                        cout << "You missed an attack!" << endl;
                        playerHP -= finalBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        playerMiss = true;
                    }

                    if (finalBossHP <= 0) {
                        system("CLS");
                        cout << "Enemy HP == " << finalBossHP << endl;
                        cout << "Wave cleared!" << endl;
                        waveCounter++;
                        break;
                    }
                    else if (finalBossHP > 0 && playerMiss == false) {
                        cout << "Enemy turn!" << endl;
                        cout << "-" << finalBossDMG << endl;
                        playerHP -= finalBossDMG;
                        cout << "Your HP == " << playerHP << endl;
                        system("CLS");
                    }
                }
                if (playerHP <= 0) {
                    cout << "You Lose! Type r to return to main menu!" << endl;
                    waveCounter = 10;
                    cin >> exitChar;
                    if (exitChar == 'r') {
                        system("CLS");
                        break;
                    }
                }
                else if (playerHP > 0) {
                    break;
                }
            }
            case 3: {
                system("CLS");
                cout << "Your Health == " << playerHP << endl;
                cout << "Enemy Damage == " << enemyDMG << endl;
                cout << "Enemy Health == " << enemyHP << endl;
                cout << "Type r to return to menu" << endl;
                cin >> exitChar;
                if (exitChar == 'r') {
                    system("CLS");
                    break;
                }
            }
            case 4: {
                system("CLS");
                cout << "There are only 2 weapons to choose from" << endl;
                cout << "Will you choose" << endl;
                cout << "The sword:" << endl;
                cout << "It's the middle ground weapon, meaning it's neither strong nor weak" << endl;
                cout << "You have to answer a simple two digit addition question" << endl;
                cout << "For a critical, you will have to multiply two single digit numbers" << endl;
                cout << "The critical multiplier is 1.5x" << endl;
                cout << "Or" << endl;
                cout << "The mace:" << endl;
                cout << "As you can probably guess, it's the heavy weapon, meaning it's strong but it is harder to use" << endl;
                cout << "You will have to multiply two single digit numbers and it's base damage is the same as the sword's critical damage" << endl;
                cout << "As for a critical, you will have to multiply a double digit number by a single digit number" << endl;
                cout << "The critical multiplier is a whopping 4x" << endl;
                cout << "Type r to return to menu" << endl;
                cin >> exitChar;
                if (exitChar == 'r') {
                    system("CLS");
                    break;
                }





            }
            }
            }
        }
    }
}




int main() {
mainMenu: {
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
    cout << "        <=-=================================================================================================-=>" << endl;
    cout << endl;
    cout << "                                              - 1. PLAY" << endl;
    cout << "                                              - 2. ABOUT US" << endl;
    cout << "                                              - 3. Exit" << endl;
    cout << endl;
    cout << "        <=-=================================================================================================-=>" << endl;
    cout << endl;
    cout << "                                             < | > Choose an option : ";

    int mainChoose;
    do {
        cin >> mainChoose;
    } while (mainChoose != 1 && mainChoose != 2 && mainChoose != 3 && mainChoose != 4);

    switch (mainChoose) {
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

        int gameChoose;
        do {
            cin >> gameChoose;
        } while (gameChoose < 1 || gameChoose > 5);

        switch (gameChoose) {
        case 1: {
            system("CLS");
            game(1);
            goto mainMenu;
        }
        case 2: {
            system("CLS");
            game(1.5);
            goto mainMenu;
        }
        case 3: {
            system("CLS");
            game(2);
            goto mainMenu;
        }
        case 4: {
            cout << "\n*** How to Play Instructions ***\n";
            break;
        }
        case 5:
            system("CLS");
            goto mainMenu;
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
        cout << "Type r to return to Main Menu: ";
        char choose;
        do {
            cin >> choose;
        } while (choose != 'r');

        system("CLS");
        goto mainMenu;
    }
    case 3: {
        return 0;
    }
    }
    }
}
