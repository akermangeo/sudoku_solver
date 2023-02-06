#include "square.h"

#include <algorithm>


using namespace std;

namespace 
{
	vector all_candidates{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
}


square::square(const int value, const int row, const int column)
: value_{ value }, row_{row}, column_{column}
{
	if (value == 0)
	{
		candidates_ = all_candidates;
	}
	else
	{
		candidates_ = { value };
	}
}

