#include <iostream>
#include "TestRegistry.h"

#include "ExerciceTemplate/ExerciceTemplate.h"

#include "Exo1.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Test name not provided" << std::endl;
		return 1;
	}

	TestRegistry registry;

	std::string testName = argv[1];
	std::string inputStr = (argc > 2) ? argv[2] : "";
	std::string expectedOutputStr = (argc > 3) ? argv[3] : "";

	Exo1::Register();

	ExerciceBase* exercice = registry.CreateTestInstance(testName);
	if (!exercice)
	{
		std::cerr << "Test not found: " << testName << std::endl;
		return 1;
	}

	exercice->EvalInternal(inputStr, expectedOutputStr);
	delete exercice;

	return 0;
}
