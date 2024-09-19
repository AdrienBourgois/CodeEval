#pragma once

#include "Autograder/CodeEvalCore.h"

TESTIO(Exo1, int, int);

inline int Exo1::ExecuteExercice(const int& input)
{
	return input * input;
}
