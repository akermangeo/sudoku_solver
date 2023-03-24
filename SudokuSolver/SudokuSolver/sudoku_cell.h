#pragma once
#include <functional>
#include <set>

#include "change_type.h"
#include "sudoku_validity.h"
#include "sudoku_value.h"


class sudoku_cell
{
public:
	sudoku_validity set_value(int value);
	void learn_knowledge_from(const sudoku_cell& other);

	void register_group(const std::function<sudoku_validity(change_type)>& updater)
	{
		group_update_functions_.push_back(updater);
	}

	[[nodiscard]] sudoku_value get_value() const { return value_; }
	sudoku_validity tell_cannot_be(int value);
	[[nodiscard]] std::set<int> get_possibilities() const { return possibilities_; }

private:
	sudoku_value value_ = sudoku_value::create_unknown_value();
	std::set<int> possibilities_{1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<std::function<sudoku_validity(change_type)>> group_update_functions_{};
};
