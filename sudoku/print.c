#include "sudoku.h"
#include <stdio.h>
#define M 9
#define N 10
#define BACKGROUNDGREEN "\033[42m"
#define BACKGROUNDYELLOW "\033[1m"
#define BACKGROUNDGREY "\033[31m"
#define DEFAULTATTR "\033[0m"

void    sudoku_print(int x, int y, char array[9][10])
{
    printf("\r");
    printf("\033[20A");
    for (int i = 0; i < M; i++) {
        printf("+---+---+---+---+---+---+---+---+---+");
        if (i == 0)
            printf("         Sudoku 0.0.1");
        if (i == 3)
            printf("          Q - Quit");
        if (i == 6)
            printf("         Press 0 - 9 to set number");
        printf("\n");
        for (int j = 1; j < N; j++) {
            printf("%s", "|");
            if (check_point(i, j, array))
                printf("%s", BACKGROUNDYELLOW);
            else
                printf("%s", BACKGROUNDGREY);
            if (i == x && j == y)
                printf("%s", BACKGROUNDGREEN);
            if (array[i][j] > '0')
                printf(" %c ", array[i][j]);
            else
                printf("   ");
            printf("%s", DEFAULTATTR);
        }
        printf("%c", '|');
        if (i == 0)
            printf("         Level: easy");
        if (i == 2)
            printf("         Commands");
        if (i == 3)
            printf("          r - Redraw");
        if (i == 6)
            printf("         Press x to delete number");
        if (i == 7)
            printf("         W, A, S, D, to move cursor");
        printf("\n");
    }
    printf("%s", "+---+---+---+---+---+---+---+---+---+\n");
}
