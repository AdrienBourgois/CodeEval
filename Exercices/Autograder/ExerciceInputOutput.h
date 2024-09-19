#pragma once
#include "ExerciceBase.h"

template<typename Input, typename Output>
class ExerciceInputOutput : public ExerciceBase
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

	virtual Output ExecuteExercice(const Input& input) { return Output(); }
};
