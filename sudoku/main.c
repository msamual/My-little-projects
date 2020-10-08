#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "sudoku.h"

/* Установка терминала в неканонический режим */
struct termios save_attr;

void    reset_input_mode(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &save_attr);
}

void    set_input_mode(void)
{
    struct termios attr;

    tcgetattr(STDIN_FILENO, &save_attr);
    tcgetattr (STDIN_FILENO, &attr);
    attr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &attr);
}
/* end set terminal */

void    set_num(int x, int y, char sym, char array[9][10])
{
    if (check_point(x, y, array)) {
        if (sym == 'x')
            array[x][y] = '0';
        else if (!check_valid_num(x, y, sym, array))
            array[x][y] = sym;
    }
}

/* move cursor */
void    move_cursor(int *x, int *y, char sym)
{
    if (sym == 'w')
        (*x)--;
    if (sym == 's')
        (*x)++;
    if (sym == 'd')
        (*y)++;
    if (sym == 'a')
        (*y)--;
    if (*x < 0 || *x > 8 || *y < 1 || *y > 9) {
        *x = 4;
        *y = 5;
    }
}
int main()
{
    char array[][10] = {
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
        "0000000000",
    };
    int x = 4;
    int y = 5;
    char sym = 0;

    load_file(array);
    /* set terminal */
    set_input_mode();
    /* Game loop */
    while (sym != 'Q') {
        sudoku_print(x, y, array);
        read(0, &sym, 1);
        if ((sym >= '1' && sym <= '9') || sym == 'x')
            set_num(x, y, sym, array);
        move_cursor(&x, &y, sym);
        check_win(array);
    }
    /* reset terminal */
    reset_input_mode();
    return 0;
}
