#include "sudoku.h"
#include <stdio.h>

void    sudoku_print(int m, int n, char **array)
{
    for (int i = 0; i < m; i++) {
        printf("+---+---+---+---+---+---+---+---+---+");
        if (i == 0)
            printf("         Sudoku 0.0.1");
        if (i == 3)
            printf("          Q - Quit");
        printf("\n");
        for (int j = 0; j < n; j++) {
            printf("%s", "| ");
            if (array[i][j] > '0')
                printf("%c ", array[i][j]);
            else
                printf("  ");
        }
        printf("%c", '|');
        if (i == 0)
            printf("         Level: easy");
        if (i == 2)
            printf("         Commands");
        if (i == 3)
            printf("          r - Redraw");
        printf("\n");
    }
    printf("%s", "+---+---+---+---+---+---+---+---+---+\n");
}
