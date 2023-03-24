 #include "sudoku_cell.h"
#include "sudoku_validity.h"


 sudoku_validity sudoku_cell::set_value(const int value)
 {
	 value_ = sudoku_value(value);
	 for (const auto& update : group_update_functions_)
	 {
		 if (const sudoku_validity validity = update(value_known); validity == invalid)
		 {
			 return invalid;
		 }
	 }
	 return valid;
 }

 void sudoku_cell::learn_knowledge_from(const sudoku_cell& other)
 {
	 value_ = other.get_value();
	 possibilities_ = other.get_possibilities();
 }

 sudoku_validity sudoku_cell::tell_cannot_be(const int value)
 {
	 if (value_.known_to_be(value))
	 {
		 return invalid;
	 }
	 if (!value_.is_certain())
	 {
		 possibilities_.erase(value);

		 if (possibilities_.size() == 1)
		 {
			 if (const sudoku_validity validity = set_value(*possibilities_.cbegin()); validity == invalid)
			 {
				 return invalid;
			 }
		 }
	 }
	 return valid;
 }
