#include "sudoku.h"


solve_result::solve_result(const sudoku& result, const solve_outcome outcome) : outcome_{outcome},
	sudoku_{std::make_unique<sudoku>(result)}
{
}
