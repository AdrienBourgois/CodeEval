#pragma once
#include <functional>
#include <map>
#include <string>
#include "ExerciceBase.h"

class TestRegistry
{
public:
	static void RegisterTest(const std::string& testName, const std::function<ExerciceBase*()>& creator)
	{
		tests[testName] = creator;
	}

	ExerciceBase* CreateTestInstance(const std::string& testName) const
	{
		if (tests.contains(testName))
		{
			return tests[testName]();
		}
		return nullptr;
	}

private:
	static std::map<std::string, std::function<ExerciceBase*()>> tests;
};
