#pragma once

struct sudoku_value
{
	explicit sudoku_value(const int value) : value_{ value } {}
	[[nodiscard]] bool known_to_be(const int value) const { return value == value_; }
	[[nodiscard]] int get_value() const { return value_; }

	static sudoku_value create_unknown_value() { return sudoku_value{ 0 }; }

	[[nodiscard]] bool is_certain() const { return value_ != 0; }

	

private:
	int value_;
};
