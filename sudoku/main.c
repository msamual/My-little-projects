#include <stdio.h>
#include "sudoku.h"

int main()
{
    char *array[10] =
    {
        "123000789",
        "123456000",
        "000456789",
        "123450009",
        "100056789",
        "123000789",
        "123400089",
        "120006789",
        "020406080",
    };
    sudoku_print(9, 9, array);
    return 0;
}
