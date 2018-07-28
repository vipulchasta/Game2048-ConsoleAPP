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
    tGestureType userGesture = GESTURE_LEFT;

    cout << "++++++++++ 2048 Game ++++++++++" << endl << endl;
    cout << "Enter Player Name: ";
    setColor( BOLD_BLUE );
    cin >> playerName;
    setColor( COLOR_RESET );

    while(1) {
        system( "clear" );
        cout << "++++++++++ 2048 Game ++++++++++" << endl ;
        cout << "Welcome " << playerName << endl;
        cout << "Moves: " << countMoves << " Score: " << countScore ;
        countScore = game.printTable( );

        char ch;
        ch = getch();
        switch( ch ) {
            case 'a':
                userGesture = GESTURE_LEFT;
                break;
            case 'd':
                userGesture = GESTURE_RIGHT;
                break;
            case 'w':
                userGesture = GESTURE_UP;
                break;
            case 's':
                userGesture = GESTURE_DOWN;
                break;
            default:
                printf("Invalid Key");
                break;
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
    }

    system( "clear" );
    cout << "++++++++++ 2048 Game ++++++++++" ;
    game.printTable( );
    cout << "++++++++++ Game Over ++++++++++" << endl;
    cout << "Player Name: " << playerName << endl;
    cout << "Moves: " << countMoves << " Score: " << countScore << endl;

    return 0;
}
