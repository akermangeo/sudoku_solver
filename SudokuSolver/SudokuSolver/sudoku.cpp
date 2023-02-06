#include "sudoku.h"

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
		shared_ptr<const sudoku_group> new_group = make_shared<const sudoku_group>( get_row_cells(row_index) );
		groups.push_back(new_group);
	}

	//create columns
	for (int column_index = 0; column_index < 9; ++column_index)
	{
		shared_ptr<const sudoku_group> new_group = make_shared<const sudoku_group>( get_column_cells(column_index) );
		groups.push_back(new_group);
	}

	//create cages
	for (int cage_index = 0; cage_index < 9; ++cage_index)
	{
		shared_ptr<const sudoku_group> new_group = make_shared<const sudoku_group>( get_cage_cells(cage_index) );
		groups.push_back(new_group);
	}
	return groups;
}



sudoku::sudoku() : cells_{create_cells()}, groups_{create_groups()} {}

void sudoku::set_value(int row, int column, int value)
{
	cells_[row][column]->set_value(value);
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_row_cells(int row_index) const
{
	return cells_[row_index];
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_column_cells(int column_index) const
{
	vector<std::shared_ptr<sudoku_cell>> cells{};
	cells.reserve(9);
	for (int row_index = 0; row_index < 9; row_index++)
	{
		cells.push_back(cells_[row_index][column_index]);
	}
	return cells;
}

std::vector<std::shared_ptr<sudoku_cell>> sudoku::get_cage_cells(int cage_index) const
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


