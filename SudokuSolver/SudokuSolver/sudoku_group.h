#pragma once
#include <memory>

#include "sudoku_cell.h"


class sudoku_group
{
public:
	explicit sudoku_group(const std::vector<std::shared_ptr<sudoku_cell>>& sudoku_cells);

	sudoku_validity update(int change_index, change_type type) const;

private:
	const std::vector<std::shared_ptr<sudoku_cell>> cells_;
};
