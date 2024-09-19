#pragma once
#include "Exercice.h"

template<typename Input, typename Output>
class ExerciceWithIO : public Exercice
{
protected:
	bool RequiresInputOutput() override { return true; }

	void EvalWithIO(const std::string& inputStr, const std::string& expectedOutputStr) override
	{
		Input input = ConvertFromString<Input>(inputStr);
		Output expectedOutput = ConvertFromString<Output>(expectedOutputStr);
		Output result = ExecuteExercice(input);
		std::cout << (result == expectedOutput ? "Test passed!" : "Test failed.") << std::endl;
	}

	virtual Output ExecuteExercice(const Input& input) { return Output(); }
};
