class doAction
{
public:
    doAction();

    static void doUp();
    static void doDown();
    static void doRight();
    static void doLeft();

    static void doUpSum();
    static void doDownSum();
    static void doRightSum();
    static void doLeftSum();

    static bool placeOnce();    //Places 2,4,8 on the arbitrary place which is free
    static int printTable();   //Prints the current game table on the Screen

    static int wonOrLose();

};
