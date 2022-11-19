//
// Created by mcheu on 11/19/2022.
//
#include <iostream>
#include "nimfuncs.h"

using std::cout;
using std::endl;
using std::cin;

char answer = 'y';
const std::string sticks = "|||||||||||";
const int BIG_NUM = INT_MAX;
const char END_LINE = '\n';

void showInstructions()
{
std::cout << "Display instructions here" << std::endl;
}
void showBoard(int num_sticks)
{
    cout << num_sticks << endl;
}

int getMove(int num_sticks)
{
    cout << "choose sticks" << endl;
    cin >> num_sticks;
    return num_sticks;
}

bool playAgain()
{
    return false;
}



