#include <vector>

#include "sudoku.h"
#include "SudokuSolver.h"


solve_result solve_sudoku(const std::vector<std::vector<int>>& sudoku_vector)
{
	const sudoku _sudoku{ sudoku_vector };
	return _sudoku.solve();
}
