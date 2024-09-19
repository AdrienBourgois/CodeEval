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

template<typename T>
T ExerciceBase::ConvertFromString(const std::string& str)
{
	if constexpr (std::is_same_v<T, int>)
	{
		return std::stoi(str);
	}
	else if constexpr (std::is_same_v<T, float>)
	{
		return std::stof(str);
	}
	else if constexpr (std::is_same_v<T, std::string>)
	{
		return str;
	}
	return T();
}

ExerciceBase::InputOutputRequirement operator&(ExerciceBase::InputOutputRequirement _lhs, ExerciceBase::InputOutputRequirement _rhs)
{
	return static_cast<ExerciceBase::InputOutputRequirement>(static_cast<int>(_lhs) & static_cast<int>(_rhs));
}
