#pragma once

#include <iostream>
#include <string>

#define Test(TestName) \
class TestName : public Exercice { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	void ExecuteExercice() override; \
}

#define TestInput(TestName, InputType) \
class TestName : public ExerciceInput<InputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	void ExecuteExercice(const InputType& input) override; \
}

#define TestInputOutput(TestName, InputType, OutputType) \
class TestName : public ExerciceInputOutput<InputType, OutputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	OutputType ExecuteExercice(const InputType& input) override; \
}

class ExerciceBase
{
public:
	enum class InputOutputRequirement : int
	{
		None = 0,
		Input = 1,
		Output = 2
	};

	virtual ~ExerciceBase() = default;

	void EvalInternal(const std::string& input = "", const std::string& expectedOutput = "");

protected:
	virtual InputOutputRequirement GetRequirement() = 0;

	virtual bool ExecuteInternal();
	virtual bool ExecuteInternalInput(const std::string& input);
	virtual bool ExecuteInternalInputOutput(const std::string& input, const std::string& expectedOutput);
};

ExerciceBase::InputOutputRequirement operator&(ExerciceBase::InputOutputRequirement _lhs, ExerciceBase::InputOutputRequirement _rhs);
