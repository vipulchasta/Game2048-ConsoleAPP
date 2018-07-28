typedef enum color {
    COLOR_RESET = 0,
    RED = 2,
    GREEN = 4,
    YELLOW = 8,
    BLUE = 16,
    MEGENTA = 32,
    CYAN = 64,
    BOLD_RED = 128,
    BOLD_GREEN = 256,
    BOLD_YELLOW = 512,
    BOLD_BLUE = 1024,
    BOLD_MEGENTA = 2048,
    BOLD_CYAN = 4096
}tColor;

/*
 *	@brief	:	Reads from Keypress, Doesn't Echo
 *	@parm1 void	:	Nothing
 *	@return	int :	ASCII of the Typed Character By User
 */
int getch( void );

/*
 *	@brief	:	Reads from Keypress, Echoes
 *	@parm1 void	:	Nothing
 *	@return	int :	ASCII of the Typed Character By User
 */
int getche( void );

void setColor( tColor color );