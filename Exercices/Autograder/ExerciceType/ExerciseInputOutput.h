#pragma once

#include "ExerciseBase.h"

#include "Autograder/Helpers.h"

template<typename Input, typename Output>
class ExerciseInputOutput : public ExerciseBase
{
protected:
	InputOutputRequirement GetRequirement() override
	{
		return InputOutputRequirement::Input & InputOutputRequirement::Output;
	}

	bool ExecuteInternalInputOutput(const std::string& inputStr, const std::string& expectedOutputStr) override
	{
		Input input = ConvertFromString<Input>(inputStr);
		Output expectedOutput = ConvertFromString<Output>(expectedOutputStr);
		Output result = ExecuteExercice(input);
		std::cout << (result == expectedOutput ? "Test passed!" : "Test failed.") << std::endl;

		return false;
	}

	virtual Output ExecuteExercise(const Input& input) { return Output(); }
};
