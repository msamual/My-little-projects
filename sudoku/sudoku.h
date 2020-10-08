#ifndef SUDOKU_H
#define SUDOKU_H

typedef struct {
    int x;
    int y;
}t_point;

void    sudoku_print(int x, int y, char array[9][10]);
int     check_valid_num(int x, int y, char sym, char array[9][10]);
int     check_point(int x, int y, char array[9][10]);
int     load_file(char array[9][10]);
void    check_win(char array[9][10]);
void	sudoku(char array[][10]);

#endif // SUDOKU_H
