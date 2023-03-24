#include <vector>

#include "sudoku.h"
#include "SudokuSolver.h"
#include "solve_result.h"


void solve_sudoku(const std::vector<std::vector<int>>& sudoku_vector)
{
	sudoku _sudoku{ sudoku_vector };
	solve_result result = _sudoku.solve();
}
