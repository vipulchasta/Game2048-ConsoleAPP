#include<iostream>
#include "Game2048.h"
#include "conio.h"

using namespace std;


Game2048::Game2048( void ){
    for( int c_i = 0 ; c_i < 4 ; c_i++ ) {
        for( int r_i = 0; r_i < 4 ; r_i++ ) {
            mat[r_i][c_i] = 0;
        }
    }
    placeOnce( );
    placeOnce( );
}

void Game2048::doShift( tGestureType gesture ) {
    switch( gesture ) {
        case GESTURE_UP:
            for( int c_i = 0 ; c_i < 4 ; c_i++ ) {
                for( int r_i = 1; r_i < 4 ; r_i++ ) {
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
            break;
        case GESTURE_DOWN:
            for( int c_i = 0 ; c_i < 4 ; c_i++ ) {
                for( int r_i = 2; r_i >= 0 ; r_i-- ) {
                    int r_iTemp = 3;
                    while( r_iTemp > r_i ) {
                        if( mat[r_iTemp][c_i] == 0 ) {
                            mat[r_iTemp][c_i] = mat[r_i][c_i];
                            mat[r_i][c_i] = 0;
                        }
                        r_iTemp--;
                    }
                }
            }
            break;
        case GESTURE_RIGHT:
            for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
                for( int c_i = 2 ; c_i >= 0 ; c_i-- ) {
                    int c_iTemp = 3;
                    while( c_iTemp > c_i ) {
                        if( mat[r_i][c_iTemp] == 0 ) {
                            mat[r_i][c_iTemp] = mat[r_i][c_i];
                            mat[r_i][c_i] = 0;
                        }
                        c_iTemp--;
                    }
                }
            }
            break;
        case GESTURE_LEFT:
            for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
                for( int c_i = 1 ; c_i < 4 ; c_i++ ) {
                    int c_iTemp = 0;
                    while( c_iTemp < c_i ) {
                        if( mat[r_i][c_iTemp] == 0 ) {
                            mat[r_i][c_iTemp] = mat[r_i][c_i];
                            mat[r_i][c_i] = 0;
                        }
                        c_iTemp++;
                    }
                }
            }
            break;
        default:
            printf("Invalid Gesture");
            break;

    }
}

void Game2048::doSum( tGestureType gesture ) {
    switch( gesture ) {
        case GESTURE_UP:
            for( int c_i = 0 ; c_i < 4 ; c_i++ ) {
                for( int r_i = 0; r_i < 3 ; r_i++ ) {
                    if( mat[r_i][c_i] == mat[r_i+1][c_i] ) {
                        mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i+1][c_i];
                        mat[r_i+1][c_i] = 0;
                    }
                }
            }
            break;
        case GESTURE_DOWN:
            for( int c_i = 0 ; c_i < 4 ; c_i++ ) {
                for( int r_i = 3; r_i > 0 ; r_i-- ) {
                    if( mat[r_i][c_i] == mat[r_i-1][c_i] ) {
                        mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i-1][c_i];
                        mat[r_i-1][c_i] = 0;
                    }
                }
            }
            break;
        case GESTURE_RIGHT:
            for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
                for( int c_i = 3 ; c_i > 0 ; c_i-- ) {
                    if( mat[r_i][c_i] == mat[r_i][c_i-1] ) {
                        mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i][c_i-1];
                        mat[r_i][c_i-1] = 0;
                    }
                }
            }
            break;
        case GESTURE_LEFT:
            for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
                for( int c_i = 0 ; c_i < 3 ; c_i++ ) {
                    if( mat[r_i][c_i] == mat[r_i][c_i+1] ) {
                        mat[r_i][c_i] = mat[r_i][c_i] + mat[r_i][c_i+1];
                        mat[r_i][c_i+1] = 0;
                    }
                }
            }
            break;
        default:
            printf("Invalid Gesture");
            break;

    }
}

bool Game2048::placeOnce( void ) {
    if( anyFree( mat ) ) {
        int i;
        int j;
        do {
            i = random.genIndex( );
            j = random.genIndex( );
        }while( mat[i][j] != 0 );

        mat[i][j] = random.gen( );

        return true;
    } else {
        if( isAnyMove( mat ) )
            return true;
        else
            return false;
    }
}

int Game2048::printTable( void ) {
    int sum = 0;
        cout << endl;
        cout << endl;

    for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
        cout << "\t -----------------------------------------------------------------"<<endl;
        cout << "\t |";
        for( int c_i = 0 ; c_i < 4 ; c_i++) {
            setColor( (tColor) mat[r_i][c_i]  );
            if( 0 != mat[r_i][c_i] )
                cout <<  "\t" << mat[r_i][c_i] ;
            else
                cout <<  "\t" << " " ;
            setColor( COLOR_RESET );
            cout <<  "\t |";
            sum+= mat[r_i][c_i];
        }
        cout << endl;
    }
    cout << "\t -----------------------------------------------------------------"<<endl;
    return sum;
}

int Game2048::wonOrLose( void ) {
    if( isWon(mat) )
        return 1;
    if( !isAnyMove(mat) )
        return -1;
    return 0;
}



bool Game2048::anyFree( int mat[][4] ) {
    for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
        for( int c_i = 0 ; c_i < 4 ; c_i++)
            if( mat[r_i][c_i] == 0 )
                return true;
    }
    return false;
}

bool Game2048::isWon( int mat[][4] ) {
    for( int r_i = 0 ; r_i < 4 ; r_i++ ) {
        for( int c_i = 0 ; c_i < 4 ; c_i++)
            if( mat[r_i][c_i] == 2048 )
                return true;
    }
    return false;
}

bool Game2048::isAnyMove( int mat[][4] ) {
    if( anyFree( mat ) )
        return true;

    for( int r_i = 0 ; r_i < 4 ; r_i++ )                //To check if there is any move in Left and Right Move
        for( int c_i = 0 ; c_i < 3 ; c_i++ )
            if( mat[r_i][c_i] == mat[r_i][c_i+1] )
                return true;

    for( int c_i = 0 ; c_i < 4 ; c_i++ )                //To check if there is any move in Up or Down
        for( int r_i = 0; r_i < 3 ; r_i++ )
            if( mat[r_i][c_i] == mat[r_i+1][c_i] )
                return true;

    return false;
}
