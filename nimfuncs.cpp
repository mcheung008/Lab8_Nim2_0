//
// Created by mcheu on 11/19/2022.
//
#include <iostream>
#include "nimfuncs.h"
#include <limits>

using std::cout;
using std::endl;
using std::cin;
int player = 1;

const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';


void showInstructions() {
//std::cout << "Display instructions here" << std::endl;
        static bool first = true;
        if (first) {
            std::cout << "Hello, welcome to Nim Game Version 2.0!" << std::endl;
            std::cout << "As a reminder, in this game, players take turns removing 1,2, or 3"
                         " stick from an initial amount of 11. The player who removes the last"
                         " stick wins." << std::endl;
            first = false;
//        std::cout << endl;
        } else {
            std::cout << "How many sticks to remove?" << std::endl;
        }
}

    void showBoard(int num_sticks) {
//    const int MAX_STICKS = 11;

        const std::string sticks = "|";

        cout << "It is Player " << player << "'s turn:" << endl;
        cout << "The game currently looks like this:" << endl;


        for (int i = 0; i < num_sticks; i++) {
            cout << sticks;
        }
        cout << endl;
//    cout << num_sticks << endl;
    }

    int getMove(int num_sticks) {
        const int MAX_STICKS = num_sticks;

        bool numVal = true;

        while (numVal) {
            std::cout << "How many sticks would you like to remove?" << std::endl;
            std::cin >> num_sticks;

            if (!cin) {
                std::cout << "Invalid input!" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (num_sticks <= 0 || num_sticks > 3 || num_sticks > MAX_STICKS) {
                std::cout << "Please enter a valid number!" << endl;
                cin.ignore(BIG_NUM, END_LINE);
            } else {
                numVal = false;
            }
        }

        return num_sticks;
//    cout << "choose sticks" << endl;
//    cin >> num_sticks;
//    return num_sticks;
    }

    bool playAgain() {
        const char YES = 'y';
        const char NO = 'n';
        char answer;
        bool valid;

        do {

            cout << "Do you want to play again? (Y or N)" << endl;
            cin >> answer;
            answer = tolower(answer);
            valid = true;

            if (answer != YES && answer != NO) {
                cout << "Please enter 'y' or 'n' only." << endl;
                valid = false;
            }
            cin.ignore(BIG_NUM, END_LINE);

        } while (!valid);

        return answer == YES;

    }




