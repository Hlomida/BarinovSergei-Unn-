#pragma once
#include "Stack.h"
#include <string>

class Calc {
	std::string infix;
	TStack<char> stop;
	std::string postfix;
	TStack<double> stnum;
	int GetPriority(char m);
public:
	void ToPostFix();
	void SetInfix(std::string inf);
	std::string GetPostfix();
	double CalcS();
};