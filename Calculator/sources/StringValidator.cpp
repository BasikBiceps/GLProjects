#include <string>
#include <algorithm>
#include <cstdlib>

#include "StringValidator.h"

using namespace std;

void StringValidator::removeSpaces(string& str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void StringValidator::referencesReplacement(string& str, vector<double>& references)
{
	for (auto iterator = str.begin(); iterator != str.end(); ++iterator)
	{
		if (*iterator == '$')
		{
			auto localIterator = ++iterator;
			string temp;

			while (localIterator != str.end() && !isOperator(*localIterator))
			{
				temp += *localIterator;
				++localIterator;
			}

			size_t refIndex = stoi(temp.c_str());

			if (references.size() <= refIndex)
			{
				throw runtime_error("Incorrect reference.");
			}

			--iterator;

			str.erase(iterator, localIterator);

			str.insert(iterator - str.begin(), to_string(references[refIndex]));
			iterator = str.begin();
		}
	}
}

bool StringValidator::stringIsValidForCalculate(string& str)
{
	if (str.size() < _kMinimalLength)
	{
		return false;
	}

	for (auto symbol : str)
	{
		if (!isdigit(symbol) && symbol != '.' && symbol != '$' && !isOperator(symbol))
		{
			return false;
		}
	}

	return operatorsValidator(str);
}

bool StringValidator::operatorsValidator(string& str)
{
	size_t operatorsCounter = 0;

	if ((isOperator(*str.begin()) && *str.begin() != '-') || isOperator(*(--str.end())))
	{
		return false;
	}

	for (size_t i = 1; i < str.size(); ++i)
	{
		if (isOperator(str[i]) && isOperator(str[i - 1]) && !str[i] == '-')
		{
			return false;
		}

		if (isOperator(str[i]))
		{
			++operatorsCounter;
		}
	}

	if (operatorsCounter == 0)
	{
		return false;
	}

	return true;
}

bool StringValidator::isOperator(char symbol) const noexcept
{
	return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

bool StringValidator::isPriorityOperation(char o) const noexcept
{
	return o == '*' || o == '/';
}
