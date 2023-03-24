#include <functional>
#include <memory>

#include "sudoku_group.h"
#include "sudoku_update_error.h"

using namespace std;


sudoku_group::sudoku_group(const std::vector<std::shared_ptr<sudoku_cell>>& cells) : cells_{cells}
{
	for (int index = 0; index < 9; index++)
	{
		cells[index]->register_group([&, index](const change_type type){ return this->update(index, type); });
	}
}

sudoku_validity sudoku_group::update(const int change_index, const change_type type) const
{
	if (type == value_known)
	{
		const sudoku_value set_value = cells_[change_index]->get_value();
		if (!set_value.is_certain())
		{
			throw runtime_error("Value known update called when value was not known.");
		}
		for (int index = 0; index < 9; index++)
		{
			if (index != change_index)
			{
				const sudoku_validity validity = cells_[index]->tell_cannot_be(set_value.get_value());
				if (validity == invalid)
				{
					return invalid;
				}
			}
		}
		return valid;
	}
	throw runtime_error("Change type not implemented.");
}
