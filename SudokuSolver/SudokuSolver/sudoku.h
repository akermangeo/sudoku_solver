#pragma once

#include <memory>
#include <vector>

#include "solve_outcome.h"
#include "sudoku.h"
#include "sudoku_group.h"
#include "sudoku_cell.h"

class sudoku;

class solve_result
{
public:
	solve_result(const sudoku& result, const solve_outcome outcome);
	[[nodiscard]] bool is_solved() const { return outcome_ == solved; }
private:
	solve_outcome outcome_;
	std::unique_ptr<sudoku> sudoku_;
};


class sudoku
{
public:
	explicit sudoku(const std::vector<std::vector<int>>& sudoku_vector);
	sudoku(const sudoku& other);
	explicit sudoku(const sudoku&& other) = delete;
	sudoku& operator=(sudoku other) = delete;
	sudoku& operator=(sudoku&& other) = delete;
	~sudoku() = default;
	[[nodiscard]] solve_result solve() const;

private:
	sudoku();
	[[nodiscard]] bool is_solved() const;
	void set_value(int row, int column, int value) const;
	[[nodiscard]] std::tuple<int, int> find_uncertain_cell() const;
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_row_cells(int row_index) const;
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_column_cells(int column_index) const;
	[[nodiscard]] std::vector<std::shared_ptr<sudoku_cell>> get_cage_cells(int cage_index) const;
	[[nodiscard]] std::shared_ptr<sudoku_cell> get_cell(int row, int column) const;

	[[nodiscard]] static std::vector<std::vector<std::shared_ptr<sudoku_cell>>> create_cells();
	[[nodiscard]] std::vector<std::shared_ptr<const sudoku_group>> create_groups() const;

	const std::vector<std::vector<std::shared_ptr<sudoku_cell>>> cells_;
	const std::vector<std::shared_ptr<const sudoku_group>> groups_;
};
