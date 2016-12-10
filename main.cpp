#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include"doAction.h"
#include"WinCheck.h"

using namespace std;

doAction init;              //Call constructor of doAction

int main()
{
    int countScore = 0;
    int countMoves = 0;
    char playerName[20];

    cout << "++++++++++ 2048 Game ++++++++++" << endl << endl;
    cout << "Enter Player Name: ";
    cin >> playerName;

    while(1)
    {
        system( "cls" );
        cout << "++++++++++ 2048 Game ++++++++++" << endl ;
        cout << "Welcome " << playerName << endl;
        cout << "Moves: " << countMoves << " Score: " << countScore ;
        countScore = doAction::printTable( );

        char ch;
        ch = getch();

        switch( ch )
        {
        case 75:
            doAction::doLeft();
            doAction::doLeftSum();
            doAction::placeOnce();
            countMoves++;
            break;
        case 77:
            doAction::doRight();
            doAction::doRightSum();
            doAction::placeOnce();
            countMoves++;
            break;
        case 72:
            doAction::doUp();
            doAction::doUpSum();
            doAction::placeOnce();
            countMoves++;
            break;
        case 80:
            doAction::doDown();
            doAction::doDownSum();
            doAction::placeOnce();
            countMoves++;
            break;
        }

        if( doAction::wonOrLose() )
           break;
    }

    system( "cls" );
    cout << "++++++++++ 2048 Game ++++++++++" ;
    doAction::printTable( );
    cout << "++++++++++ Game Over ++++++++++" << endl;
    cout << "Player Name: " << playerName << endl;
    cout << "Moves: " << countMoves << " Score: " << countScore << endl;
    return 0;
}
