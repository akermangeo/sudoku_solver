#include <utility>
#include <vector>

#include "sudoku.h"
#include "sudoku_solver.h"


using namespace std;


vector<int> sudoku_solver::solve_sudoku(vector<int> sudoku_vector)
{
	const sudoku _sudoku{std::move(sudoku_vector)};
	sudoku attempt = attempt_solve(_sudoku);
	return _sudoku.get_coefficients();
}

sudoku sudoku_solver::attempt_solve(sudoku _sudoku)
{
	_sudoku.simplify();
	if (_sudoku.is_solved())
	{
		return _sudoku;
	}
	square& best_square = _sudoku.get_least_uncertain_square();
	auto candidates = best_square.get_candidates();
	int row = best_square.get_row();
	int column = best_square.get_column();
	for (int candidate : candidates)
	{
		_sudoku.set_value(candidate, row, column);
		sudoku attempt = attempt_solve(_sudoku);
		if (attempt.is_solved())
		{
			return attempt;
		}
	}
	return _sudoku;
	
}
