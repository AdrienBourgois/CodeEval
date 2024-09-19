#pragma once
#include "Exercice.h"

class ExerciceWithoutIO : public Exercice
{
protected:
	bool RequiresInputOutput() override { return false; }

	void EvalWithoutIO() override
	{
		bool result = ExecuteExercice();
		std::cout << (result ? "Test passed!" : "Test failed.") << std::endl;
	}

	virtual bool ExecuteExercice() { return false; }
};
