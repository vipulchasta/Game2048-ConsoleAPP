#include "MyRandom.h"
#include "types.h"

class Game2048 {
    MyRandom random;
    int mat[4][4];

public:
    Game2048( void );

    void doShift( tGestureType gesture );
    void doSum( tGestureType gesture );

    bool placeOnce( void );
    int printTable( void );

    int wonOrLose( void );

    bool anyFree( int mat[][4] );

    bool isWon( int mat[][4] );

    bool isAnyMove( int mat[][4] );


};
