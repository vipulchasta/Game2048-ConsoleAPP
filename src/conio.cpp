#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "conio.h"

int getch( void ) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int getche( void ) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void setColor( tColor color ) {
    switch (color) {
        case COLOR_RESET:
            printf("\033[0m");
            break;
        case RED:
            printf("\033[0;31m");
            break;
        case BOLD_RED:
            printf("\033[1;31m");
            break;
        case GREEN:
            printf("\033[0;32m");
            break;
        case BOLD_GREEN:
            printf("\033[1;32m");
            break;
        case YELLOW:
            printf("\033[0;33m");
            break;
        case BOLD_YELLOW:
            printf("\033[1;33m");
            break;
        case BLUE:
            printf("\033[0;34m");
            break;
        case BOLD_BLUE:
            printf("\033[1;34m");
            break;
        case MEGENTA:
            printf("\033[0;35m");
            break;
        case BOLD_MEGENTA:
            printf("\033[1;35m");
            break;
        case CYAN:
            printf("\033[0;36m");
            break;
        case BOLD_CYAN:
            printf("\033[1;36m");
            break;
        default:
            setColor(BOLD_RED);
            printf("\nInvalid Color\n");
            setColor(COLOR_RESET);
            break;
    }
}