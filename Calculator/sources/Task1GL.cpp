#include "CalculatorApp.h"

int main()
{
	std::unique_ptr<Calculator> upCalculator(new Calculator());
	CalculatorApp application(std::move(upCalculator));

	application.start();

	return 0;
}
