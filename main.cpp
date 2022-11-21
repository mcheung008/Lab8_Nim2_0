/*------------------------------------------
 * Author: Michael Cheung
 * Program Title: Nim Game 2.0
 * Last Modified: 11/20/2022
 *
 * Description:-----------------------------
 *  In this program revamp, the goal of the
 *  game remains the same - two players take
 *  turns removing 1,2, or 3 sticks from an
 *  initial pile of 11. The last person to
 *  remove the last stick wins.
 ------------------------------------------*/

#include <iostream>
#include "nimfuncs.h"

using namespace std;

int main()
{
    const int MAX_STICKS = 11;

    // outer replay game loop

    do {

        // define initial start for game
        int numSticks = MAX_STICKS;
        int player = 1;

        // tell the user how to play the game
        showInstructions();

        // game loop, continues until no sticks left
        do {
            // display the board
            showBoard(numSticks);

            // get a valid move and update the board state
            int the_move = getMove(numSticks);

            numSticks -= the_move;

            // switch player if not done
            if (numSticks != 0 )
            {
                player = (player == 1)?2:1;
            }

        } while (numSticks != 0);

        // game over, show who won
        std::cout << "Player " << player << " won!!\n";

        // do they want to go again?
    } while ( playAgain() );

    return 0;
}

/*Commentary--------------------------------------------
 * This lab was somewhat easy and hard at the same time.
 * It was easy because we had created this game before so,
 * we had all the functions written out already,
 * but it was hard as well because we had to adapt our
 * previous functions into a pre-written main function
 * as well as adapting it into a separate compilation
 * file system. Also, I am still struggling in
 * employing the use of stubs and drivers when writing
 * out my program.
 * ----------------------------------------------------*/