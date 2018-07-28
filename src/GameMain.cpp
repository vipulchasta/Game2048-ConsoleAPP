#include<iostream>
#include<stdlib.h>
#include "conio.h"
#include "Game2048.h"

using namespace std;


int main() {
    int countScore = 0;
    int countMoves = 0;
    char playerName[40] = {0};
    Game2048 game;
    tGestureType userGesture;

    cout << "++++++++++ 2048 Game ++++++++++" << endl << endl;
    cout << "Enter Player Name: ";
    setColor( BOLD_BLUE );
    cin >> playerName;
    setColor( COLOR_RESET );

    while(1) {
        system( "clear" );
        setColor( BOLD_BLUE );
        cout << "++++++++++ 2048 Game ++++++++++" << endl ;
        cout << "Welcome " << playerName << endl;
        cout << "Moves: " << countMoves << " Score: " << countScore ;
        setColor( COLOR_RESET );
        countScore = game.printTable( );

        char ch;
        ch = getch();
        if (ch == '\033') {
            getch();
            ch = getch();
            switch( ch ) {
                case 'D':
                    userGesture = GESTURE_LEFT;
                    break;
                case 'C':
                    userGesture = GESTURE_RIGHT;
                    break;
                case 'A':
                    userGesture = GESTURE_UP;
                    break;
                case 'B':
                    userGesture = GESTURE_DOWN;
                    break;
                default:
                    //printf("Invalid Key");
                    break;
            }
        }
        if( isValidGesture(userGesture) ) {
            game.doShift(userGesture);
            game.doSum(userGesture);
            game.doShift(userGesture);
            game.placeOnce();
            countMoves++;
        }

        if( game.wonOrLose() )
           break;

       userGesture = GESTURE_INVALID;
    }

    system( "clear" );
    cout << "++++++++++ 2048 Game ++++++++++" ;
    game.printTable( );
    cout << "++++++++++ Game Over ++++++++++" << endl;
    cout << "Player Name: " << playerName << endl;
    cout << "Moves: " << countMoves << " Score: " << countScore << endl;

    return 0;
}
