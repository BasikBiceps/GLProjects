#include <iostream>

#include "CalculatorApp.h"
#include <algorithm>

using namespace std;

CalculatorApp::CalculatorApp(unique_ptr<Calculator> calculator) : 
	_calculator(move(calculator))
{
}

void CalculatorApp::start()
{
	while (_isActive)
	{
		string input;

		printRules();
		printReferences();
		
		cout << "Enter your string: ";

	    getline(cin, input);

		if (tolower(input[0]) == 'q')
		{
		    stop();
                    continue;         
		}

		try {
		    auto result = _calculator->calculate(input);

		    cout << "Your result: " << result << endl;
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}

void CalculatorApp::stop() noexcept
{
	_isActive = false;
}

void CalculatorApp::printRules() const noexcept
{
	cout << "Enter 'q' to finish." << endl;
	cout << "Use '.' for double numbers." << endl;
	cout << "Expressions like '2-2/-2' or '2-2*-2' aren't correct, you should use this form: '2--2/-2 or 2--2*-2' etc." << std::endl;
}

void CalculatorApp::printReferences() const noexcept
{
	auto references = _calculator->getReferences();

	cout << "All available references: " << endl;

	for (size_t i = 0; i < references.size(); ++i)
	{
		cout << '$' << i << " = " << references[i] << endl;
	}
}
