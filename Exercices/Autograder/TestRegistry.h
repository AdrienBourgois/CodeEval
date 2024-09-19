#pragma once
#include <functional>
#include <map>
#include <string>
#include "Exercice.h"

class TestRegistry
{
public:
	static void RegisterTest(const std::string& testName, const std::function<Exercice*()>& creator)
	{
		tests[testName] = creator;
	}

	Exercice* CreateTestInstance(const std::string& testName) const
	{
		if (tests.contains(testName))
		{
			return tests[testName]();
		}
		return nullptr;
	}

private:
	static std::map<std::string, std::function<Exercice*()>> tests;
};
