#include "sudoku_value_factory.h"

sudoku_value sudoku_value_factory::create_sudoku_value(const int value)
{
	certainty_type certainty = known;
	if (value == 0)
	{
		certainty = unknown;
	}//TODO lambda assignement

	return sudoku_value{ value, certainty };
}
