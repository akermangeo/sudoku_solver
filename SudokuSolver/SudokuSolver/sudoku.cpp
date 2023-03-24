#include "sudoku.h"

#include <algorithm>

#include "sudoku_unsolvable_error.h"

using namespace std;


vector<vector<shared_ptr<sudoku_cell>>> sudoku::create_cells()
{
	vector<vector<shared_ptr<sudoku_cell>>> rows{};
	rows.reserve(9);
	for (int row_index = 0; row_index < 9; ++row_index)
	{
		vector<shared_ptr<sudoku_cell>> row{};
		row.reserve(9);
		for (int column_index = 0; column_index < 9; ++column_index)
		{
			row.push_back(make_shared<sudoku_cell>());
		}
		rows.push_back(row);
	}
	return rows;
}

std::vector<shared_ptr<const sudoku_group>> sudoku::create_groups() const
{
	std::vector<shared_ptr<const sudoku_group>> groups{};
	//create rows
	for (int row_index = 0; row_index < 9; ++row_index)
	{
		auto new_group = make_shared<const sudoku_group>(get_row_cells(row_index));
		groups.push_back(new_group);
	}

	//create columns
	for (int column_index = 0; column_index < 9; ++column_index)
	{
		auto new_group = make_shared<const sudoku_group>(get_column_cells(column_index));
		groups.push_back(new_group);
	}

	//create cages
	for (int cage_index = 0; cage_index < 9; ++cage_index)
	{
		auto new_group = make_shared<const sudoku_group>(get_cage_cells(cage_index));
		groups.push_back(new_group);
	}
	return groups;
}

sudoku::sudoku() : cells_{ create_cells() }, groups_{ create_groups() } {}

sudoku::sudoku(const std::vector<std::vector<int>>& sudoku_vector) : sudoku{}
{
	for (int row = 0; row < 9; ++row)
	{
		for (int column = 0; column < 9; ++column)
		{
			if (const int value_to_set = sudoku_vector[row][column]; value_to_set != 0)
			{
				set_value(row, column, value_to_set);
			}
		}
	}
}

sudoku::sudoku(const sudoku& other) : sudoku{}
{
	for (int row = 0; row < 9; ++row)
	{
		for (int column = 0; column < 9; ++column)
		{
			cells_[row][column]->learn_knowledge_from(*other.get_cell(row, column));
		}
	}
}

void sudoku::set_value(const int row, const int column, const int value) const
{
	cells_[row][column]->set_value(value);
}

tuple<int, int> sudoku::find_uncertain_cell() const
{
	int best_row = 0;
	int best_column = 0;
	int best_options = 10;
	for (int row = 0; row < 9; ++row)
	{
		for (int column = 0; column < 9; ++column)
		{
			if (auto& cell = *cells_[row][column]; !cell.get_value().is_certain())
			{
				if (const int possibilities_size = static_cast<int>(cell.get_possibilities().size()); possibilities_size
					< best_options)
				{
					best_options = possibilities_size;
					best_column = column;
					best_row = row;
				}
			}
		}
	}
	return tuple{best_row, best_column};
}

solve_result sudoku::solve() const
{
	if (is_solved())
	{
		return solved;
	}
	const auto indexes = find_uncertain_cell();
	const int row = get<0>(indexes);
	const int column = get<1>(indexes);
	for (const int possibility : cells_[row][column]->get_possibilities())
	{
		sudoku sudoku_copy = *this;
		if (const sudoku_validity validity = sudoku_copy.get_cell(row, column)->set_value(possibility); validity ==
			valid)
		{
			if (const solve_result result = sudoku_copy.solve(); result == solved)
			{
				return solved;
			}
		}
	}
	return impossible;
}

bool sudoku::is_solved() const
{
	return ranges::all_of(cells_, [](auto row)
		{
			return ranges::all_of(row.begin(), row.end(), [](auto cell)
				{
					return cell->get_value().is_certain();
				});
		});
}


shared_ptr<sudoku_cell> sudoku::get_cell(int row, int column) const
{
	return cells_[row][column];
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_row_cells(const int row_index) const
{
	return cells_[row_index];
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_column_cells(const int column_index) const
{
	vector<std::shared_ptr<sudoku_cell>> cells{};
	cells.reserve(9);
	for (int row_index = 0; row_index < 9; row_index++)
	{
		cells.push_back(cells_[row_index][column_index]);
	}
	return cells;
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_cage_cells(const int cage_index) const
{
	//row, column for top left corner
	const int row_start = (cage_index / 3) * 3;
	const int column_start = (cage_index % 3) * 3;

	vector<std::shared_ptr<sudoku_cell>> cells{};
	cells.reserve(9);
	for (int row_index = 0; row_index < 3; ++row_index)
	{
		for (int column_index = 0; column_index < 3; ++column_index)
		{
			cells.push_back(cells_[row_start + row_index][column_start + column_index]);
		}
	}
	return cells;
}
