#pragma once
#include "ExerciceBase.h"

class Exercice : public ExerciceBase
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

	virtual void ExecuteExercice() = 0;
};
