#include <json/json.h>
#include <fstream>
#include <iostream>

#include "Account.h"
#include "Settings.h"
#include "Calculator.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "usage: it-nova-test.exe settings.json";
		return -1;
	}
	Json::Value config;
	std::ifstream{ argv[1], std::ifstream::binary } >> config;

	const auto& settings = Settings::getInstance().load(config);
	const Account teacher{ settings.getTeacherSalary(), settings.getTeacherPremiumRate() };
	const Account assistant{ settings.getAssistantSalary(), settings.getAssistantPremiumRate() };

	std::cout << "Total salaries cost: " << Calculator::getExpenses({
		std::make_pair(teacher, settings.getTeachersCount()),
		std::make_pair(assistant, settings.getAssistantsCount()) });
	return 0;
}
