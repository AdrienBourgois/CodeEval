#pragma once
#include <functional>
#include <map>
#include <string>

#include "ExerciceType/ExerciseBase.h"

class TestRegistry
{
public:
	static void RegisterTest(const std::string& testName, const std::function<ExerciseBase*()>& creator)
	{
		tests[testName] = creator;
	}

	ExerciseBase* CreateTestInstance(const std::string& testName) const
	{
		if (tests.contains(testName))
		{
			return tests[testName]();
		}
		return nullptr;
	}

private:
	static std::map<std::string, std::function<ExerciseBase*()>> tests;
};
