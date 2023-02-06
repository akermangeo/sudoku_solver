#pragma once
#include <vector>

#include "solve_result.h"
#include "sudoku_group.h"
#include "sudoku_square.h"

class sudoku
{
public:
	void set_value(int row, int column, int value);
	solve_result solve();

private:
	std::vector<std::vector<sudoku_square>> squares{9, std::vector<sudoku_square>{9}};
	std::vector<sudoku_group> groups;

};
