#pragma once

#include <iostream>
#include <string>

#define Test(TestName) \
class TestName : public Exercise<void, void> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	void ExecuteExercise() override; \
	bool EvalInternal() override; \
}

#define TestInput(TestName, InputType) \
class TestName : public Exercise<InputType, void> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	void ExecuteExercise(const InputType& _input) override; \
	bool EvalInternal(const InputType& _input) override; \
}

#define TestInputOutput(TestName, InputType, OutputType) \
class TestName : public Exercise<InputType, OutputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
	TestName() { exerciseName = #TestName; } \
protected: \
	OutputType ExecuteExercise(const InputType& _input) override; \
	bool EvalInternal(const InputType& _input, const OutputType& _expected_output) override; \
}

class ExerciseBase
{
public:
	virtual ~ExerciseBase() = default;

	virtual bool PrepareEval(const std::string& _input, const std::string& _expected_output) = 0;

protected:
	const std::string& GetExerciseName() const
	{
		return exerciseName;
	}

	std::string exerciseName;

	void LogSuccess(const std::string& _input, const std::string& _expected, const std::string& _result, const std::string& _message = "") const
	{
		std::cout << "[SUCCESS] Exercise: \"" << exerciseName << "\"";
		if (!_input.empty())
		{
			std::cout << " | Input: \"" << _input << "\"";
		}
		if (!_expected.empty())
		{
			std::cout << " | Expected: \"" << _expected << "\"";
		}
		if (!_result.empty())
		{
			std::cout << " | Result: \"" << _result << "\"";
		}
		if (!_message.empty())
		{
			std::cout << " | Message: \"" << _message << "\"";
		}
		std::cout << std::endl;
	}

	void LogFailure(const std::string& _input, const std::string& _expected, const std::string& _result, const std::string& _message = "") const
	{
		std::cerr << "[FAILURE] Exercise: \"" << exerciseName << "\"";
		if (!_input.empty())
		{
			std::cerr << " | Input: \"" << _input << "\"";
		}
		if (!_expected.empty())
		{
			std::cerr << " | Expected: \"" << _expected << "\"";
		}
		if (!_result.empty())
		{
			std::cerr << " | Result: \"" << _result << "\"";
		}
		if (!_message.empty())
		{
			std::cerr << " | Message: \"" << _message << "\"";
		}
		std::cerr << std::endl;
	}
};
