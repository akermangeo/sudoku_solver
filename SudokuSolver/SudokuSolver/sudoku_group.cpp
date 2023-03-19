#include <functional>
#include <memory>

#include "sudoku_group.h"
#include "sudoku_update_error.h"

using namespace std;


sudoku_group::sudoku_group(const std::vector<std::shared_ptr<sudoku_cell>>& cells) : cells_{cells}
{
	for (int index = 0; index < 9; index++)
	{
		cells[index]->register_group([&, index](const change_type type) { this->update(index, type); });
	}
}

void sudoku_group::update(const int change_index, const change_type type) const
{
	if (type == value_known)
	{
		const sudoku_value set_value = cells_[change_index]->get_value();
		if (!set_value.is_certain())
		{
			throw sudoku_update_error("Value not known when change type indicates known value");
		}
		for (int index = 0; index < 9; index++)
		{
			if (index != change_index)
			{
				cells_[index]->remove_possibility(set_value.get_value());
			}
		}
	}
	else
	{
		throw runtime_error("Change type not implemented.");
	}
}
