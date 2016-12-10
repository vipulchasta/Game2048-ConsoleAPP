#include"WinCheck.h"

bool WinCheck::anyFree( int mat[][4] )
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 0 ; c_i < 4 ; c_i++)
            if( mat[r_i][c_i] == 0 )
                return true;
    }
    return false;
}

bool WinCheck::isWon( int mat[][4] )
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
    {
        for( int c_i = 0 ; c_i < 4 ; c_i++)
            if( mat[r_i][c_i] == 2048 )
                return true;
    }
    return false;
}



bool WinCheck::isAnyMove( int mat[][4] )
{
    for( int r_i = 0 ; r_i < 4 ; r_i++ )
        for( int c_i = 0 ; c_i < 3 ; c_i++ )
            if( mat[r_i][c_i] == mat[r_i][c_i+1] )
                return true;

    for( int r_i = 0 ; r_i < 4 ; r_i++ )
        for( int c_i = 3 ; c_i > 0 ; c_i-- )
            if( mat[r_i][c_i] == mat[r_i][c_i-1] )
                return true;

    for( int c_i = 0 ; c_i < 4 ; c_i++ )
        for( int r_i = 3; r_i > 0 ; r_i-- )
            if( mat[r_i][c_i] == mat[r_i-1][c_i] )
                return true;

    for( int c_i = 0 ; c_i < 4 ; c_i++ )
        for( int r_i = 0; r_i < 3 ; r_i++ )
            if( mat[r_i][c_i] == mat[r_i+1][c_i] )
                return true;
}