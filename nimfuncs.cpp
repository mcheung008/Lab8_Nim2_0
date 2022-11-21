//
// Created by mcheu on 11/19/2022.
//
#include <iostream>
#include "nimfuncs.h"
#include <limits>

using std::cout;
using std::endl;
using std::cin;

const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

// Function that displays the instructions to the player.
void showInstructions() {
//std::cout << "Display instructions here" << std::endl;
        static bool first = true;
        if (first) {
            std::cout << "Hello, welcome to Nim Game Version 2.0!" << std::endl;
            std::cout << "As a reminder, in this game, players take turns removing 1,2, or 3 stick(s) from an initial amount of 11." << std::endl;
            std::cout << "The player who removes the last stick wins." << std::endl;
            first = false;
        std::cout << endl;
        } else {
            std::cout << "Let's play again!" << std::endl;
        }
}
// Function that shows the current stick count and who's turn it is.
    void showBoard(int num_sticks) {
//    const int MAX_STICKS = 11;
//    cout << num_sticks << endl;

        int player;
        const std::string sticks = "|";
        if (num_sticks != 0 )
        {
            player = (player == 1)?2:1;
        }

        cout << "It is Player " << player << "'s turn." << endl;
        cout << "The game currently looks like this:" << endl;


        for (int i = 0; i < num_sticks; i++) {
            cout << sticks;
        }
        cout << endl;

    }
// Function that gets the move from the player as well as validating their stick input.
    int getMove(int num_sticks) {
    //    cout << "choose sticks" << endl;
    //    cin >> num_sticks;
    //    return num_sticks;

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

    }
// Bool function that asks if the player would like to play again with input validation.
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




