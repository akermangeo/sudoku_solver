#pragma once
#include <stdexcept>


class sudoku_unsolvable_error final : std::runtime_error
{
public:
	explicit sudoku_unsolvable_error(const std::string& message) : runtime_error{ message } {}
	explicit sudoku_unsolvable_error(const char* message) : runtime_error{ message } {}
};

