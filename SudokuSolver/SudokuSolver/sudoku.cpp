#include "sudoku.h"

#include <algorithm>


using namespace std;


sudoku::sudoku(vector<int> values)
{

	for (int row = 0; row < 9; ++row)
	{
		vector<square> square_row{};
		vector<square*> row_group{};
		for (int column = 0; column < 9; column++)
		{
			int index = row * 9 + column;
			int value = values[index];
			square _square{ value, row, column};
			group_map_[_square] = vector<square_group*>{};
			square_row.push_back(_square);
			row_group.push_back(&_square);
			if (value == 0)
			{
				++unknowns_;
			}
		}
		square_group group{ row_group };
		assign_group_to_elements(group);
		squares_.push_back(square_row);
		groups_.push_back(group);
	}

	add_cells();
	add_diagonals();
}

void sudoku::assign_group_to_elements(square_group group)
{
	for (square _square : group.get_squares())
	{
		group_map_[_square].push_back(&group);
	}
}


std::vector<int> sudoku::get_coefficients() const
{
	vector<int> coefficients{};
	for (auto row :squares_)
	{
		for (auto square : row)
		{
			coefficients.push_back(square.get_value());
		}
	}
	return coefficients;
}

square& sudoku::get_least_uncertain_square() const
{
	vector<square*> rowmins{};
	for (vector<square> row : squares_)
	{
		auto iterator = ranges::min_element(row, [](const square& lhs, const square& rhs)
		{
			return lhs.number_of_candidates() < rhs.number_of_candidates();
		});

		if (iterator != row.end())
		{
			rowmins.push_back(&iterator[0]);
		}
	}

	return *ranges::min_element(rowmins, [](const square* lhs, const square* rhs)
		{
			return lhs->number_of_candidates() < rhs->number_of_candidates();
		})[0];
}

void sudoku::set_value(int candidate, int row, int column)
{
	squares_[row][column].set_value(candidate);
}

void sudoku::simplify()
{
	for (auto row : squares_)
	{
		for (square _square : row)
		{
			
		}
	}
}
