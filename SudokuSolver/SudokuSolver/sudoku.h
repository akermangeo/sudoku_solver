#pragma once
#include <memory>
#include <vector>

#include "solve_result.h"
#include "sudoku_group.h"
#include "sudoku_cell.h"

class sudoku
{
public:
	
	sudoku();
	void set_value(int row, int column, int value);
	solve_result solve();

private:
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_row_cells(int row_index) const;
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_column_cells(int column_index) const;
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_cage_cells(int cage_index) const;

	[[nodiscard]] static std::vector<std::vector<std::shared_ptr<sudoku_cell>>> create_cells();
	[[nodiscard]] std::vector<std::shared_ptr<const sudoku_group>> create_groups() const;

	const std::vector<std::vector<std::shared_ptr<sudoku_cell>>> cells_;
	const std::vector<std::shared_ptr<const sudoku_group>> groups_;

	
};
