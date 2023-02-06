#include "sudoku.h"

void sudoku::set_value(int row, int column, int value)
{
	squares[row][column].set_value(value);
}


