#pragma once
#include <vector>
#include <functional>

class square
{
public:
	explicit square(int value, int row, int column);

	void set_value(int new_value)
	{
		value_ = new_value;
	}

	[[nodiscard]] int get_value() const
	{
		return value_;
	}

	[[nodiscard]] int number_of_candidates() const
	{
		return static_cast<int>(candidates_.size());
	}

	[[nodiscard]] std::vector<int> get_candidates() const
	{
		return candidates_;
	}

	[[nodiscard]] int get_row() const
	{
		return row_;
	}

	[[nodiscard]] int get_column() const
	{
		return column_;
	}

private:
	int value_;
	std::vector<int> candidates_;
	const int row_;
	const int column_;
};
