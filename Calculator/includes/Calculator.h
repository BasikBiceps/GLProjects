#pragma once
#include <vector>
#include <string>
#include <memory>

#include "StringValidator.h"

class Calculator
{
public:
	Calculator();
	Calculator(const std::vector<double>& references, std::size_t referencesLimit);

	double calculate(std::string& expression);
	double toDoOperation(double left, double right, char o);
	void calculationFilterOfPriorityOperation(std::string& expression);

	std::vector<double>& getReferences() noexcept;
	std::size_t getReferencesLimit() const noexcept;

private:
    const std::size_t _kDefaultReferencesLimit = 10;
	std::vector<double> _references;
	std::size_t _referencesLimit;
	StringValidator _stringValidator;
};