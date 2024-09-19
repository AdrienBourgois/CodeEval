#pragma once

#include "ExerciceBase.h"

#include "Helpers.h"

template<typename Input>
class ExerciceInput : public ExerciceBase
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

	virtual void ExecuteExercice(const Input& input) {}
};
