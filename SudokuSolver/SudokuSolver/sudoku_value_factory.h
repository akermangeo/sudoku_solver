#pragma once
#include "sudoku_value.h"

class sudoku_value_factory
{
public:
	sudoku_value_factory() = delete;
	static sudoku_value create_sudoku_value(int value);
};
