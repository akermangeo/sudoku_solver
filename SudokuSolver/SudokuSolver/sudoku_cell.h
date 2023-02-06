#pragma once
#include <functional>
#include <vector>

#include "change_type.h"

class sudoku_cell
{
public:
	void set_value(int value) { value_ = value; }

	void register_group(const std::function<void(change_type)>& updater) { group_update_functions_.push_back(updater); }

private:
	int value_ = 0;
	std::vector<int> possibilities_{ 1,2,3,4,5,6,7,8,9 };
	std::vector<std::function<void(change_type)>> group_update_functions_{};
};
