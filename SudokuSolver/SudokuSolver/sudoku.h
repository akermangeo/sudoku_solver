#pragma once
#include <vector>
#include <map>

#include "square.h"
#include "square_group.h"

class sudoku
{
public:
	explicit sudoku(std::vector<int> values);

	sudoku(const sudoku& other) : sudoku{other.get_coefficients()} {}

	std::vector<int> get_coefficients() const;

	[[nodiscard]] bool is_solved() const
	{
		return unknowns_ == 0;
	}

	square& get_least_uncertain_square() const;

	void set_value(int candidate, int row, int column);

	void simplify();

private:
	void add_cells();
	void add_diagonals();

	std::map<square, std::vector<square_group*>, std::function<bool(
		const square&, const square&)>> group_map_{[](const square& lhs, const square& rhs)
	{
		return lhs.get_row() == rhs.get_row() && rhs.get_column() == lhs.get_column();
	} };

	std::vector<std::vector<square>> squares_;
	std::vector<square_group> groups_;
	int unknowns_ = 0;
};
