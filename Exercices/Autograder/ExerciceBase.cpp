#include "ExerciceBase.h"

void ExerciceBase::EvalInternal(const std::string& input, const std::string& expectedOutput)
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

bool ExerciceBase::ExecuteInternal()
{
	return false;
}

bool ExerciceBase::ExecuteInternalInput(const std::string& input)
{
	return false;
}

bool ExerciceBase::ExecuteInternalInputOutput(const std::string& input, const std::string& expectedOutput)
{
	return false;
}

ExerciceBase::InputOutputRequirement operator&(ExerciceBase::InputOutputRequirement _lhs, ExerciceBase::InputOutputRequirement _rhs)
{
	return static_cast<ExerciceBase::InputOutputRequirement>(static_cast<int>(_lhs) & static_cast<int>(_rhs));
}
