#pragma once
#include <vector>

#include "sudoku.h"

class sudoku_solver
{
public:
	static std::vector<int> solve_sudoku(std::vector<int> sudoku_vector);

private:
	static sudoku attempt_solve(sudoku _sudoku);
};