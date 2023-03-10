#pragma once
#include <functional>
#include <vector>

#include "change_type.h"
#include "sudoku_value.h"
#include "sudoku_value_factory.h"

class sudoku_cell
{
public:
	void set_value(const int value) { value_ = sudoku_value_factory::create_sudoku_value(value); } //TODO needs to fire updaters

	void register_group(const std::function<void(change_type)>& updater) { group_update_functions_.push_back(updater); }
	[[nodiscard]] sudoku_value get_value() const { return value_; }
	void remove_possibility(int value);

private:
	sudoku_value value_ = sudoku_value_factory::create_sudoku_value(0);
	std::vector<int> possibilities_{ 1,2,3,4,5,6,7,8,9 };
	std::vector<std::function<void(change_type)>> group_update_functions_{};
};
