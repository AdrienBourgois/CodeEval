#pragma once

#include "ExerciseBase.h"

#include "Autograder/Helpers.h"

template<typename Input>
class ExerciseInput : public ExerciseBase
{
protected:
	InputOutputRequirement GetRequirement() override
	{
		return InputOutputRequirement::Input;
	}

	bool ExecuteInternalInput(const std::string& inputStr) override
	{
		Input input = ConvertFromString<Input>(inputStr);
		ExecuteExercice(input);

		return false;
	}

	virtual void ExecuteExercise(const Input& input) {}
};
