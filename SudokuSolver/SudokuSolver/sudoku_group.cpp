#include "sudoku_group.h"

#include <functional>
#include <memory>

using namespace std;

sudoku_group::sudoku_group(std::vector<std::shared_ptr<sudoku_cell>> cells) : cells_{cells}
{
	for (int index = 0; index < 9; index++)
	{
		cells[index]->register_group([&](change_type type) {this->update(index, type); });
	}
}

void sudoku_group::update(int change_index, change_type type)
{
	//TODO implement
}

