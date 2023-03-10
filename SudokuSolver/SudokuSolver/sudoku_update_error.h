#pragma once
#include <stdexcept>

class sudoku_update_error : std::runtime_error
{
public:
	explicit sudoku_update_error(const std::string& message) : runtime_error{message} {}
	explicit sudoku_update_error(const char* message) : runtime_error{ message } {}
};

