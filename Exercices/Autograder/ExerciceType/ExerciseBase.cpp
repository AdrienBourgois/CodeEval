#include "ExerciseBase.h"

void ExerciseBase::EvalInternal(const std::string& input, const std::string& expectedOutput)
{
	if (GetRequirement() == InputOutputRequirement::None)
	{
		ExecuteInternal();
	}
	else if (GetRequirement() == InputOutputRequirement::Input)
	{
		ExecuteInternalInput(input);
	}
	else if (GetRequirement() == (InputOutputRequirement::Input & InputOutputRequirement::Output))
	{
		ExecuteInternalInputOutput(input, expectedOutput);
	}
}

bool ExerciseBase::ExecuteInternal()
{
	return false;
}

bool ExerciseBase::ExecuteInternalInput(const std::string& input)
{
	return false;
}

bool ExerciseBase::ExecuteInternalInputOutput(const std::string& input, const std::string& expectedOutput)
{
	return false;
}

ExerciseBase::InputOutputRequirement operator&(ExerciseBase::InputOutputRequirement _lhs, ExerciseBase::InputOutputRequirement _rhs)
{
	return static_cast<ExerciseBase::InputOutputRequirement>(static_cast<int>(_lhs) & static_cast<int>(_rhs));
}
