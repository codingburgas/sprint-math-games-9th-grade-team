#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void game(double levelMultiplier) {
    int waveCount = 10;
    for (int waveCounter = 1; waveCounter <= waveCount;) {
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
                cout << endl;
                cout << "                                                        \033[97;4mWave " << "5" << "\033[0m" << endl;
                cout << "Mini Boss!" << endl;
                miniBossWave = true;
                finalBossWave = false;
            }
            if (waveCounter == 10) {
                cout << endl;
                cout << "                                                        \033[97;4mWave " << "10" << "\033[0m" << endl;
                cout << "Final Boss!" << endl;
                miniBossWave = false;
                finalBossWave = true;
            }
            else {
                cout << endl;
                cout << "                                                        \033[97;4mWave " << waveCounter << "\033[0m" << endl;
                miniBossWave = false;
                finalBossWave = false;
            }
            cout << endl;
            cout << "                                                  \033[93mCHOOSE YOUR WEAPON:\033[0m" << endl;
            cout << "                                            \033[96m   ___________\033[0m" << "  \033[91m ___________\033[0m" << endl;
            cout << "                                            \033[96m  | 1. Sword  |\033[0m" << " \033[91m|  2. Mace  |\033[0m" << endl;
            cout << "                                            \033[96m  |___________|\033[0m" << " \033[91m|___________|\033[0m" << endl;
            cout << "                                              \033[90m< 4. What each weapon does >\033[0m" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "                             _______" << "                                               _____" << endl;
            cout << "                            /       \\" << "                                             /     \\" << endl;
            cout << "                           |--0---0--|" << "                                           | () () |" << endl;
            cout << "                           |    ^    |" << "                                           |   ^   |" << endl;
            cout << "                           |   ---   |" << "                                            \\  ~  /" << endl;
            cout << "                            \\_______/" << "                                              |||||" << endl;
            cout << "                              |   |" << "                                                -----" << endl;
            cout << "                            _/     \\_" << "                                           ___|   |___" << endl;
            cout << "                      []___|         |___[]" << "                                 []__|         |___[]" << endl;
            cout << "                           |_________|" << "                                          |_________|" << endl;
            cout << "                             |     |" << "                                              |     |" << endl;
            cout << "                             |     |" << "                                              |     |" << endl;
            cout << "   \033[93m<0>\033[0m                       L     L" << "                     \033[91m<0>\033[0m                      V     V       \033[95m<0>\033[0m" << endl;
            cout << "\033[92m____|_______________________________/\\_/\\_________________|________/\\______/\\____________________|______________________\033[0m" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "                                                  \033[32m< 3. Check stats >\033[0m" << endl;
            cin >> chooseWpn;
            system("CLS");
            switch (chooseWpn) {
            case 1: {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                             _______" << "                                               _____" << endl;
                cout << "                            /       \\" << "                                             /     \\" << endl;
                cout << "                           |--0---0--|" << "                                           | () () |" << endl;
                cout << "                           |    ^    |" << "                                           |   ^   |" << endl;
                cout << "                           |   ---   |" << "                                            \\  ~  /" << endl;
                cout << "                            \\_______/" << "                                              |||||" << endl;
                cout << "                              |   |" << "                                                -----" << endl;
                cout << "                            _/     \\_" << "                                           ___|   |___" << endl;
                cout << "                      []___|         |___[]" << "                                 []__|         |___[]" << endl;
                cout << "                           |_________|" << "                                          |_________|" << endl;
                cout << "                             |     |" << "                                              |     |" << endl;
                cout << "                             |     |" << "                                              |     |" << endl;
                cout << "   \033[93m<0>\033[0m                       L     L" << "                     \033[91m<0>\033[0m                      V     V       \033[95m<0>\033[0m" << endl;
                cout << "\033[92m____|_______________________________/\\_/\\_________________|________/\\______/\\____________________|______________________\033[0m" << endl;
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
                    system("CLS");
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                                           \033[91;4mYou Lose! Type r to return to main menu!\033[0m" << endl;
                    cout << "                                                               ";
                    waveCounter = 10;
                    cin >> exitChar;
                    if (exitChar == 'r') {
                        system("CLS");
                        return;
                    }
                }
                else if (playerHP > 0) {
                    break;
                }


            case 2: {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                             _______" << "                                               _____" << endl;
                cout << "                            /       \\" << "                                             /     \\" << endl;
                cout << "                           |--0---0--|" << "                                           | () () |" << endl;
                cout << "                           |    ^    |" << "                                           |   ^   |" << endl;
                cout << "                           |   ---   |" << "                                            \\  ~  /" << endl;
                cout << "                            \\_______/" << "                                              |||||" << endl;
                cout << "                              |   |" << "                                                -----" << endl;
                cout << "                            _/     \\_" << "                                           ___|   |___" << endl;
                cout << "                      []___|         |___[]" << "                                 []__|         |___[]" << endl;
                cout << "                           |_________|" << "                                          |_________|" << endl;
                cout << "                             |     |" << "                                              |     |" << endl;
                cout << "                             |     |" << "                                              |     |" << endl;
                cout << "   \033[93m<0>\033[0m                       L     L" << "                     \033[91m<0>\033[0m                      V     V       \033[95m<0>\033[0m" << endl;
                cout << "\033[92m____|_______________________________/\\_/\\_________________|________/\\______/\\____________________|______________________\033[0m" << endl;
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
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << "                                           \033[91;4mYou Lose! Type r to return to main menu!\033[0m" << endl;
                    cout << "                                                               ";
                    waveCounter = 10;
                    cin >> exitChar;
                    if (exitChar == 'r') {
                        system("CLS");
                        return;
                    }
                }
                else if (playerHP > 0) {
                    break;
                }
            }
            case 3: {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "                                            ___________________________________" << endl;
                cout << "                                           |   Your Health == " << playerHP << "              |" << endl;
                cout << "                                           |   Enemy Damage == " << enemyDMG << "              |" << endl;
                cout << "                                           |   Enemy Health == " << enemyHP << "             |" << endl;
                cout << "                                           |                                   |" << endl;
                cout << "                                           |                                   |" << endl;
                cout << "                                           |    Type r to return to menu" << "       |" << endl;
                cout << "                                           |___________________________________|" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cin >> exitChar;
                if (exitChar == 'r') {
                    system("CLS");
                    break;
                }
            }
            case 4: {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << "  \033[43m                                     \033[0m  \033[93mThere are only 2 weapons to choose from\033[0m \033[43m                                   \033[0m" << endl;
                cout << endl;
                cout << "            \033[90mWill you choose\033[0m" << endl;
                cout << "                                                   \033[96m-The sword-\033[0m" << endl;
                cout << "        \033[46m  \033[0m             \033[36mIt's the middle ground weapon, meaning it's neither strong nor weak.\033[0m" << endl;
                cout << "        \033[46m  \033[0m            \033[36mYou have to answer a simple two digit addition question.\033[0m" << endl;
                cout << "        \033[46m  \033[0m            \033[36mFor a critical, you will have to multiply two single digit numbers.\033[0m" << endl;
                cout << "        \033[46m  \033[0m            \033[36mThe critical multiplier is 1.5x.\033[0m" << endl;
                cout << endl;
                cout << "            \033[90mOr\033[0m" << endl;
                cout << "                                                   \033[91m-The mace-\033[0m" << endl;
                cout << "        \033[41m  \033[0m           \033[31mAs you can probably guess, it's the heavy weapon, meaning it's strong but it is harder to use.\033[0m" << endl;
                cout << "        \033[41m  \033[0m        \033[31mYou will have to multiply two single digit numbers and it's base damage is the same\033[0m" << endl;
                cout << "        \033[41m  \033[0m        \033[31mas the sword's critical damage.  " << endl;
                cout << "        \033[41m  \033[0m        \033[31mAs for a critical, you will have to multiply a double digit number by a single digit number.\033[0m" << endl;
                cout << "        \033[41m  \033[0m        \033[31mThe critical multiplier is a whopping 4x.\033[0m" << endl;
                cout << "        \033[41m  \033[0m        \033[31mType r to return to menu.\033[0m" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << "            \033[90mPress 'r' to return:  \033[0m";
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
    cout << endl;
    cout << "        \033[106m                                                                                                       \033[0m" << endl;
    cout << endl;
    cout << "\033[1;35m         |    ____    ____        _        _________   ____  ____       _______      _______      ______     |   " << endl;
    cout << "         |   |_   \\  /   _|      / \\      |  _   _  | |_   ||   _|     |_   __ \\    |_   __ \\   .' ___  |    |  " << endl;
    cout << "         |     |   \\/   |       / _ \\     |_/ | | \\_|   | |__| |         | |__) |     | |__) | / .'   \\_|    |  " << endl;
    cout << "         |     | |\\  /| |      / ___ \\        | |       |  __  |         |  __ /      |  ___/  | |   ____    |" << endl;
    cout << "         |    _| |_\\/_| |_   _/ /   \\ \\_     _| |_     _| |  | |_       _| |  \\ \\_   _| |_     \\ `.___]  |   |" << endl;
    cout << "         |   |_____||_____| |____| |____|   |_____|   |____||____|     |____| |___| |_____|     `._____.'    |" << endl;
    cout << "         |                                                                                                   |\033[0m" << endl;
    cout << endl;
    cout << "        \033[104m                                                                                                       \033[0m" << endl;
    cout << endl;
    cout << "\033[1;36m                                      ,--.   ,--. ,------. ,--.  ,--. ,--. ,--.  " << endl;
    cout << "                                      |   `.'   | |  .---' |  ,'.|  | |  | |  |   " << endl;
    cout << "                                      |  |'.'|  | |  `--,  |  |' '  | |  | |  |  " << endl;
    cout << "                                      |  |   |  | |  `---. |  | `   | '  '-'  '  " << endl;
    cout << "                                      `--'   `--' `------' `--'  `--'  `-----'   \033[0m" << endl;

    cout << "                                    \033[35m_____________________________________________\033[0m " << endl;
    cout << "                                    \033[35m|                                           |\033[0m" << endl;
    cout << "                                    \033[35m|           \033[32m - 1. \033[4;32mPLAY\033[0m                      \033[35m|\033[0m" << endl;
    cout << "                                    \033[35m|           \033[31m - 2. \033[4;31mABOUT US\033[0m                  \033[35m|\033[0m" << endl;
    cout << "                                    \033[35m|           \033[33m - 3. \033[4;33mLEADERBOARD\033[0m               \033[35m|\033[0m" << endl;
    cout << "                                    \033[35m|                                           |\033[0m" << endl;

    cout << "        \033[45m                                                                                                       \033[0m" << endl;
    cout << endl;

    cout << "                                             \033[36m< | > Choose an option : \033[0m";

    int mainChoose;
    do {
        cin >> mainChoose;
    } while (mainChoose != 1 && mainChoose != 2 && mainChoose != 3);

    switch (mainChoose) {
    case 1: {
        system("CLS");
        cout << endl;
        cout << "                                \033[42m                                                        \033[0m" << endl;
        cout << "                                \033[42m  \033[0m                                                    \033[42m  \033[0m" << endl;
        cout << "                                \033[42m  \033[0m                  \033[1;4;44mCHOOSE YOUR LEVEL:\033[0m                \033[42m  \033[0m" << endl;
        cout << "                                \033[42m  \033[0m                                                    \033[42m  \033[0m" << endl;
        cout << "        \033[42m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                  \033[92;4m- 1. EASY\033[0m        \033[42m   \033[0m" << endl;
        cout << "                                                  \033[93;4m- 2. MEDIUM\033[0m      \033[43m   \033[0m" << endl;
        cout << "                                                  \033[91;4m- 3. HARD\033[0m        \033[41m   \033[0m" << endl;
        cout << endl;
        cout << "                                                \033[96m(?) 4. How To Play?\033[0m" << endl;
        cout << endl;
        cout << "                                                 \033[95m<~ 5. Return to Main Menu\033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "        \033[42m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                \033[36m< | > Choose an option : \033[0m";

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
            system("CLS");
            cout << endl;
            cout << endl;
            cout << "  \033[43m                                     \033[0m  \033[93mThere are only 2 weapons to choose from\033[0m \033[43m                                   \033[0m" << endl;
            cout << endl;
            cout << "            \033[90mWill you choose\033[0m" << endl;
            cout << "                                                   \033[96m-The sword-\033[0m" << endl;
            cout << "        \033[46m  \033[0m             \033[36mIt's the middle ground weapon, meaning it's neither strong nor weak.\033[0m" << endl;
            cout << "        \033[46m  \033[0m            \033[36mYou have to answer a simple two digit addition question.\033[0m" << endl;
            cout << "        \033[46m  \033[0m            \033[36mFor a critical, you will have to multiply two single digit numbers.\033[0m" << endl;
            cout << "        \033[46m  \033[0m            \033[36mThe critical multiplier is 1.5x.\033[0m" << endl;
            cout << endl;
            cout << "            \033[90mOr\033[0m" << endl;
            cout << "                                                   \033[91m-The mace-\033[0m" << endl;
            cout << "        \033[41m  \033[0m           \033[31mAs you can probably guess, it's the heavy weapon, meaning it's strong but it is harder to use.\033[0m" << endl;
            cout << "        \033[41m  \033[0m        \033[31mYou will have to multiply two single digit numbers and it's base damage is the same\033[0m" << endl;
            cout << "        \033[41m  \033[0m        \033[31mas the sword's critical damage.  " << endl;
            cout << "        \033[41m  \033[0m        \033[31mAs for a critical, you will have to multiply a double digit number by a single digit number.\033[0m" << endl;
            cout << "        \033[41m  \033[0m        \033[31mThe critical multiplier is a whopping 4x.\033[0m" << endl;
            cout << "        \033[41m  \033[0m        \033[31mType r to return to menu.\033[0m" << endl;
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
        cout << endl;
        cout << "                                \033[41m                                                        \033[0m" << endl;
        cout << "                                \033[41m  \033[0m                                                    \033[41m  \033[0m" << endl;
        cout << "                                \033[41m  \033[0m                      \033[1;4;44mABOUT US:\033[0m                     \033[41m  \033[0m" << endl;
        cout << "                                \033[41m  \033[0m                                                    \033[41m  \033[0m" << endl;
        cout << "        \033[41m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                       \033[96;4mOur team:\033[0m" << endl;
        cout << endl;
        cout << "                                           \033[92m- Martin: Scum Trainer and Leader\033[0m " << endl;
        cout << "                                           \033[93m- Denis: Backend Developer\033[0m  " << endl;
        cout << "                                           \033[91m- Stelian: Designer(1) & Frontend Developer\033[0m" << endl;
        cout << "                                           \033[35m- Stanimir: Designer(2) & Tester\033[0m" << endl;
        cout << endl;
        cout << "                                                 \033[95m<~ r. Return to Main Menu\033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "        \033[41m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                \033[36m< | > Choose an option : \033[0m";

        char choose;
        do {
            cin >> choose;
        } while (choose != 'r');

        system("CLS");
        goto mainMenu;
    }
    case 3: {
        system("CLS");
        cout << endl;
        cout << "                                \033[43m                                                        \033[0m" << endl;
        cout << "                                \033[43m  \033[0m                                                    \033[43m  \033[0m" << endl;
        cout << "                                \033[43m  \033[0m                    \033[1;4;44mLEADERBOARD:\033[0m                    \033[43m  \033[0m" << endl;
        cout << "                                \033[43m  \033[0m                                                    \033[43m  \033[0m" << endl;
        cout << "        \033[43m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                    \033[96;4mTOP 100 PLAYERS:\033[0m" << endl;
        cout << endl;
        cout << "                                                     \033[92m No results...\033[0m " << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "                                               \033[95m<~ r. Return to Main Menu\033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "        \033[43m                                                                                                       \033[0m" << endl;
        cout << endl;
        cout << endl;
        cout << "                                                \033[36m< | > Choose an option : \033[0m";

        char choose;
        do {
            cin >> choose;
        } while (choose != 'r');

        system("CLS");
        goto mainMenu;
    }
    }
    }
}
