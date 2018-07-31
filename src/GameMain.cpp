#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "conio.h"
#include "Game2048.h"

using namespace std;


int main() {
    char playerName[40] = {0};
    Game2048 game;
    tGestureType userGesture;

    cout << "++++++++++ 2048 Game ++++++++++" << endl << endl;
    cout << "Enter Player Name: ";
    setColor( BOLD_BLUE );
    //gets(playerName);
    fgets(playerName,sizeof(playerName),stdin);
    setColor( COLOR_RESET );

    while(1) {
        system( "clear" );
        setColor( BOLD_BLUE );
        cout << "++++++++++ 2048 Game ++++++++++" << endl ;
        cout << "Welcome ";
        puts(playerName);
        cout << "Moves: " << game.getCountMoves() << " Score: " << game.getScore() ;
        setColor( COLOR_RESET );
        game.printTable( );

        cout << endl << endl;
        setColor( GREEN );
        cout << "++++++++++ Game Instructions ++++++++++" << endl ;
        cout << "=> Use Arrow Keys to Move Tiles" << endl ;
        cout << "=> Use 'u' to Undo Last Operation" << endl ;
        setColor( COLOR_RESET );


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
        } else if( ch == 'u' ) {
            game.doUndo();
        }
        if( isValidGesture(userGesture) ) {
            game.doAction(userGesture);
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
    cout << "Moves: " << game.getCountMoves() << " Score: " << game.getScore() << endl;

    return 0;
}
