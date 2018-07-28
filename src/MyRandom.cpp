#include"MyRandom.h"

MyRandom::MyRandom( void )
{
    srand( time(NULL) );
    mySet[0] = 2;
    mySet[1] = 4;
    mySet[2] = 8;
}
int MyRandom::gen( void )                     // Return the value 2,4,8 to be putted in the Game Table
{
    int index = rand() % 3;
    return mySet[index];
}
int MyRandom::genIndex( void )                     // Return the value 0,1,2,3 to select the index
{
    return ( rand() % 4 );
}
