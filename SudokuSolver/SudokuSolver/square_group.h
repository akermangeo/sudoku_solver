#pragma once
#include "square.h"

class square_group
{
public:
	explicit square_group(std::vector<square*> squares) : squares_{squares} {}
	bool verify();
private:
	std::vector<square*> squares_;
};
