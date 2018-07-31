#include "MyRandom.h"
#include "types.h"

class Game2048 {

    MyRandom random;

    int currentScore = 0;
    int countMoves = 0;
    int mat[4][4];

    int bkp_currentScore = 0;
    int bkp_countMoves = 0;
    int bkp_mat[4][4];


public:
    Game2048( void );

    void calculateScore( void );

    void doAction( tGestureType gesture );

    void doShift( tGestureType gesture );
    void doSum( tGestureType gesture );
    void doCheckpoint();
    void doUndo();

    int getScore();
    int getCountMoves();



    bool placeOnce( void );
    void printTable( void );

    int wonOrLose( void );

    bool anyFree( int mat[][4] );

    bool isWon( int mat[][4] );

    bool isAnyMove( int mat[][4] );


};
