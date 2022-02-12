#pragma once
#include <cstddef>
class Account
{
	std::size_t salary_;
	double premium_modifier_;
public:

	Account(std::size_t salary, double premium_modifier): salary_(salary), premium_modifier_(premium_modifier)
	{
	}

	[[nodiscard]] auto getTotalSalary() const
	{
		return this->salary_ * (1+this->premium_modifier_);
	}
};

