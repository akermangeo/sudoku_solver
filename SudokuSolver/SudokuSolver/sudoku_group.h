#pragma once
#include <memory>

#include "sudoku_cell.h"

class sudoku_group
{
public:
	explicit sudoku_group(std::vector<std::shared_ptr<sudoku_cell>>);

	void update(int change_index, change_type type);

private:
	const std::vector<std::shared_ptr<sudoku_cell>> cells_;
};
