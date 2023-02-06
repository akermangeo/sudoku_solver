#pragma once
#include <vector>

class sudoku_square
{
public:
	void set_value(int value) { value_ = value; }

private:
	int value_ = 0;
	std::vector<int> possibilities_{ 1,2,3,4,5,6,7,8,9 };
};
