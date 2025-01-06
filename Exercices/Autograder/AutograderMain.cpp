#include <iostream>
#include <string>

#include "TestRegistry.h"

#include "ExerciceTest/ValidatorTest.h"

int main(const int _argc, char* _argv[])
{
	if (_argc < 2)
	{
		std::cerr << "Usage: <TestName> [Input] [ExpectedOutput]" << std::endl;
		return -1;
	}

	const std::string test_name = _argv[1];
	const std::string input_str = _argc > 2 ? _argv[2] : "";
	const std::string expected_output_str = _argc > 3 ? _argv[3] : "";

	ValidatorTest::Register();

	ExerciseBase* exercise = TestRegistry::CreateTestInstance(test_name);

	if (!exercise)
	{
		std::cerr << "Error: Test not found - \"" << test_name << "\"" << std::endl;
		return 1;
	}

	try
	{
		exercise->PrepareEval(input_str, expected_output_str);
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Exception caught during evaluation: " << exception.what() << std::endl;
	} catch (...)
	{
		std::cerr << "Unknown error occurred during evaluation." << std::endl;
	}

	delete exercise;

	return 0;
}
