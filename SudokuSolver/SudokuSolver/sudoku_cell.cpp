 #include "sudoku_cell.h"

#include "sudoku_unsolvable_error.h"


 void sudoku_cell::set_value(const int value)
 {
	 value_ = sudoku_value(value);
	 for (const auto& update : group_update_functions_)
	 {
		 update(value_known);
	 }
 }

 void sudoku_cell::remove_possibility(const int value)
{
	if (value_.known_to_be(value))
	{
		throw sudoku_unsolvable_error("Cell has no possibilities.");
	}
	if (value_.is_certain())
	possibilities_.erase(value);
	if (possibilities_.size() == 1)
	{
		set_value(*possibilities_.cbegin());
	}
}
