#pragma once
#include "ExerciseBase.h"

class Exercise : public ExerciseBase
{
protected:
	InputOutputRequirement GetRequirement() override
	{
		return InputOutputRequirement::None;
	}

	bool ExecuteInternal() override
	{
		return false;
	}

	virtual void ExecuteExercise() = 0;
};
