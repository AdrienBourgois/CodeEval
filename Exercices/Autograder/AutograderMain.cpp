#include <iostream>
#include "TestRegistry.h"

#include "ExerciceTemplate/ExerciceTemplate.h"

int main(const int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Test name not provided" << std::endl;
		return 1;
	}

	constexpr TestRegistry registry;

	const std::string testName = argv[1];
	const std::string inputStr = argc > 2 ? argv[2] : "";
	const std::string expectedOutputStr = argc > 3 ? argv[3] : "";

	ExerciseBase* exercise = registry.CreateTestInstance(testName);
	if (!exercise)
	{
		std::cerr << "Test not found: " << testName << std::endl;
		return 1;
	}

	exercise->EvalInternal(inputStr, expectedOutputStr);
	delete exercise;

	return 0;
}
