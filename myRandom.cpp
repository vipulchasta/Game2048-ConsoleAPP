#include<iostream>
#include"myRandom.h"
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

using namespace std;

static int mySet[3];

myRandom :: myRandom()
{
    srand( time(NULL) );
    mySet[0] = 2;
    mySet[1] = 4;
    mySet[2] = 8;
}

int myRandom :: gen( )                     // Return the value 2,4,8 to be putted in the Game Table
{
    int index = rand() % 3;
    return mySet[index];
}
int  myRandom :: genIndex( )                     // Return the value 0,1,2,3 to select the index
{
    return ( rand() % 4 );
}
