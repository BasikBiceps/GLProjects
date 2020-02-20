#pragma once
#include <memory>

#include "Calculator.h"
#include "StringValidator.h"

class CalculatorApp
{
public:
	explicit CalculatorApp(std::unique_ptr<Calculator> calculator);

	void start();
	void stop() noexcept;
private:
	void printReferences() const noexcept;
	void printRules() const noexcept;

private:
	std::unique_ptr<Calculator> _calculator;
	bool _isActive = true;
};