#pragma once

#include <iostream>
#include <string>

#define Test(TestName) \
class TestName : public Exercise { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	void ExecuteExercise() override; \
}

#define TestInput(TestName, InputType) \
class TestName : public ExerciseInput<InputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	void ExecuteExercise(const InputType& input) override; \
}

#define TestInputOutput(TestName, InputType, OutputType) \
class TestName : public ExerciseInputOutput<InputType, OutputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	OutputType ExecuteExercise(const InputType& input) override; \
}

class ExerciseBase
{
public:
	enum class InputOutputRequirement : char
	{
		None = 0,
		Input = 1,
		Output = 2
	};

	virtual ~ExerciseBase() = default;

	void EvalInternal(const std::string& input = "", const std::string& expectedOutput = "");

protected:
	virtual InputOutputRequirement GetRequirement() = 0;

	virtual bool ExecuteInternal();
	virtual bool ExecuteInternalInput(const std::string& input);
	virtual bool ExecuteInternalInputOutput(const std::string& input, const std::string& expectedOutput);
};

ExerciseBase::InputOutputRequirement operator&(ExerciseBase::InputOutputRequirement _lhs, ExerciseBase::InputOutputRequirement _rhs);
