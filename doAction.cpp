#include<iostream>
#include"doAction.h"
#include"myRandom.h"
#include"WinCheck.h"

using namespace std;

int mat[4][4];

doAction::doAction()            //Constructor
{
    myRandom init;              // To Call the Constructor of myRandom
    doAction::placeOnce( );
    doAction::placeOnce( );     //To Fill Any two locks in begin of game
}




void doAction::doLeft()
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 1 ; c_i < 4 ; c_i++ )
        {
            int c_iTemp = 0;

            while( c_iTemp < c_i )
            {
                if( mat[r_i][c_iTemp] == 0 )
                {
                    mat[r_i][c_iTemp] = mat[r_i][c_i];
                    mat[r_i][c_i] = 0;
                }
                c_iTemp++;
            }
        }
    }
}




void doAction::doRight()
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 2 ; c_i >= 0 ; c_i-- )
        {
            int c_iTemp = 3;

            while( c_iTemp > c_i )
            {
                if( mat[r_i][c_iTemp] == 0 )
                {
                    mat[r_i][c_iTemp] = mat[r_i][c_i];
                    mat[r_i][c_i] = 0;
                }
                c_iTemp--;
            }
        }
    }
}


void doAction::doUp()
{
    for( int c_i = 0 ; c_i < 4 ; c_i++ )
    {
        for( int r_i = 1; r_i < 4 ; r_i++ )
        {
            int r_iTemp = 0;

            while( r_iTemp < r_i )
            {
                if( mat[r_iTemp][c_i] == 0 )
                {
                    mat[r_iTemp][c_i] = mat[r_i][c_i];
                    mat[r_i][c_i] = 0;
                }
                r_iTemp++;
            }
        }
    }
}

void doAction::doDown()
{
    for( int c_i = 0 ; c_i < 4 ; c_i++ )
    {
        for( int r_i = 2; r_i >= 0 ; r_i-- )
        {
            int r_iTemp = 3;

            while( r_iTemp > r_i )
            {
                if( mat[r_iTemp][c_i] == 0 )
                {
                    mat[r_iTemp][c_i] = mat[r_i][c_i];
                    mat[r_i][c_i] = 0;
                }
                r_iTemp--;
            }
        }
    }
}


void doAction::doLeftSum()
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 0 ; c_i < 3 ; c_i++ )
        {
            if( mat[r_i][c_i] == mat[r_i][c_i+1] )
            {
                mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i][c_i+1];
                mat[r_i][c_i+1] = 0;
            }
        }
    }
    doAction::doLeft();
}

void doAction::doRightSum()
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 3 ; c_i > 0 ; c_i-- )
        {
            if( mat[r_i][c_i] == mat[r_i][c_i-1] )
            {
                mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i][c_i-1];
                mat[r_i][c_i-1] = 0;
            }
        }
    }
    doAction::doRight();
}

void doAction::doDownSum()
{
    for( int c_i = 0 ; c_i < 4 ; c_i++ )
    {
        for( int r_i = 3; r_i > 0 ; r_i-- )
        {
            if( mat[r_i][c_i] == mat[r_i-1][c_i] )
            {
                mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i-1][c_i];
                mat[r_i-1][c_i] = 0;
            }
        }
    }
    doAction::doDown();
}
void doAction::doUpSum()
{
    for( int c_i = 0 ; c_i < 4 ; c_i++ )
    {
        for( int r_i = 0; r_i < 3 ; r_i++ )
        {
            if( mat[r_i][c_i] == mat[r_i+1][c_i] )
            {
                mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i+1][c_i];
                mat[r_i+1][c_i] = 0;
            }
        }
    }
    doAction::doUp();
}


bool doAction::placeOnce()
{
    if( WinCheck::anyFree( mat ) )
    {
        int i;
        int j;
        do
        {
            i = myRandom::genIndex( );
            j = myRandom::genIndex( );
        }while( mat[i][j] != 0 );

        mat[i][j] = myRandom::gen( );

        return true;
    }
    else
    {
        if( WinCheck::isAnyMove( mat ) )
            return true;
        else
            return false;
    }
}

int doAction::printTable( )
{
    int sum = 0;
        cout << endl;
        cout << endl;
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 0 ; c_i < 4 ; c_i++)
        {
            cout << mat[r_i][c_i] << "\t";
            sum+= mat[r_i][c_i];
        }
        cout << endl;
    }
    return sum;
}

int doAction::wonOrLose()
{
    if( WinCheck::isWon(mat) )
        return 1;
    if( !WinCheck::isAnyMove(mat) )
        return -1;
    return 0;
}
