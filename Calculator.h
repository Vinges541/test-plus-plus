#pragma once
#include <cstddef>
#include <vector>

#include "Account.h"

class Calculator
{
public:
	static auto getExpenses(const std::vector<std::pair<Account, std::size_t>>& workers)
	{
		auto expenses = 0.0;
		for(const auto& [worker, count]: workers)
		{
			expenses += count * worker.getTotalSalary();
		}
		return expenses;
	}
};

