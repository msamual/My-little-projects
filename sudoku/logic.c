#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>

int     check_point(int x, int y, char array[9][10])
{
    static t_point used_point[100];
    static int flag = 0;

    int pos = 0;
    if (flag == 0) {
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j < 10; j++) {
                if (array[i][j] == '0') {
                    used_point[pos].x = i;
                    used_point[pos].y = j;
                    pos++;
                }
            }
        }
        flag = 1;
    }
    for (int k = 0; k < 100; k++) {
        if (used_point[k].x == x && used_point[k].y == y)
            return (1);
    }
    return (0);
}

int     check_valid_num(int x, int y, char sym, char array[9][10])
{
    /*check vertical */
    for (int i = 0; i < 9; i++) {
        if (x == i)
            continue ;
        if (array[i][y] == sym)
            return (1);
    }
    /* check horizontal */
    for (int j = 1; j < 10; j++) {
        if (y == j)
            continue ;
        if (array[x][j] == sym)
            return (1);
    }
    /* check region */
    int x1 = (x / 3) * 3;
    int y1 = ((y - 1) / 3) * 3 + 1;
    for (int i = x1; i < x1 + 3; i++) {
        for (int j = y1; j < y1 + 3; j++) {
            if (x == i || y == j)
                continue ;
            if (array[i][j] == sym)
                return (1);
        }
    }
    return (0);
}

int     load_file(char array[9][10])
{
    FILE *file;
    char buf;

    file = fopen("1", "r");
    if (file) {
        for (int i = 0; i < 9; i++) {
            for (int j = 1; j < 10; j++) {
                fread(&buf, 1, 1, file);
                if (buf == '.')
                    array[i][j] = '0';
                else
                    array[i][j] = buf;
            }
            fread(&buf, 1, 1, file);
        }
        return (1);
    }
    else
        printf("Dont open file!\n");
    return (0);
}

void    check_win(char array[9][10])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j < 10; j++) {
            if (array[i][j] == '0')
                return ;
        }
    }
    system("clear");
    printf("Congratulations!!!, YOU WIN!!!\n");
    printf("\
    oo  oo  oo    ooo    ooo     oo\n\
    oo  oo  oo    ooo    oooo    oo\n\
    oo  oo  oo    ooo    oo oo   oo\n\
    oo  oo  oo    ooo    oo  oo  oo\n\
     o o  o o     ooo    oo   oo oo\n\
      o    o      ooo    oo    oooo\n");
    exit(1);
}

int		is_solved(char array[][10])
{
    for (int i = 0; i < 9; i++)
        for (int j = 1; j < 10; j++)
        {
            if (array[i][j] == '0')
                return (0);
        }
    return (1);
}

void	sudoku(char array[][10])
{
    for (int i = 0; i < 9; i++)
        for (int j = 1; j < 10; j++)
        {
            if (array[i][j] == '0')
            {
                for (char n = '1'; n <= '9'; n++)
                    if (!check_valid_num(i, j, n, array))
                    {
                        array[i][j] = n;
                        sudoku(array);
                        if (is_solved(array))
                            return;
                        array[i][j] = '0';
                    }
                return;
            }
        }
}