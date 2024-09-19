#pragma once

#include <iostream>
#include <string>

#define TEST(TestName) \
class TestName : public ExerciceWithoutIO { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	bool ExecuteExercice() override; \
}

#define TESTIO(TestName, InputType, OutputType) \
class TestName : public ExerciceWithIO<InputType, OutputType> { \
public: \
	static void Register() { \
		TestRegistry::RegisterTest(#TestName, [] { return new TestName(); }); \
	} \
protected: \
	OutputType ExecuteExercice(const InputType& input) override; \
}

class Exercice
{
public:
	virtual ~Exercice() = default;

	void Eval(std::string input = "", std::string expectedOutput = "")
	{
		if (RequiresInputOutput())
		{
			EvalWithIO(input, expectedOutput);
		}
		else
		{
			EvalWithoutIO();
		}
	}

protected:
	virtual bool RequiresInputOutput() { return false; }

	virtual void EvalWithIO(const std::string& input, const std::string& expectedOutput) {}

	virtual void EvalWithoutIO() {}

	template<typename T>
	T ConvertFromString(const std::string& str)
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
};
