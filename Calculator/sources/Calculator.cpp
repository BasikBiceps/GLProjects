#include "Calculator.h"

using namespace std;

Calculator::Calculator() : _referencesLimit(_kDefaultReferencesLimit)
{
}

Calculator::Calculator(const vector<double>& references, size_t referencesLimit) :
	_references(references), 
	_referencesLimit(referencesLimit)
{ 
}

double Calculator::calculate(string& expression)
{
	_stringValidator.removeSpaces(expression);
    _stringValidator.referencesReplacement(expression, _references);

	if (!_stringValidator.stringIsValidForCalculate(expression))
	{
		throw runtime_error("Incorrect string for calculate.");
	}

	calculationFilterOfPriorityOperation(expression);

	for (auto iterator = expression.begin(); iterator != expression.end(); ++iterator)
	{
		if (_stringValidator.isOperator(*iterator))
		{
			if (*iterator == '-' && iterator == expression.begin())
			{
				continue;
			}

			auto leftIterator = iterator - 1;
			auto rightIterator = iterator + 1;
			string leftNumber;
			string rightNumber;

			while (leftIterator != expression.begin() && !_stringValidator.isOperator(*leftIterator))
				--leftIterator;

			auto leftLimit = leftIterator;

			if (*leftIterator == '-')
			{
				leftNumber += '-';
				++leftIterator;
			} 
			else if (_stringValidator.isOperator(*leftIterator))
			{
				++leftIterator;
				++leftLimit;
			}

			while (!_stringValidator.isOperator(*leftIterator))
			{
				leftNumber += *leftIterator;
				++leftIterator;
			}

			if (*rightIterator == '-')
			{
				rightNumber += '-';
				++rightIterator;
			}

			while (rightIterator != expression.end() && !_stringValidator.isOperator(*rightIterator))
			{
				rightNumber += *rightIterator;
				++rightIterator;
			}

			auto result = toDoOperation(stod(leftNumber), stod(rightNumber), *iterator);

			expression.erase(leftLimit, rightIterator);
			expression.insert(leftLimit - expression.begin(), to_string(result));
			iterator = expression.begin();
		}
	}

	auto result = stod(expression);

	if (_references.size() >= _referencesLimit)
	{
		_references.pop_back();
	}
	_references.insert(_references.begin(), result);

	return result;
}

vector<double>& Calculator::getReferences() noexcept
{
	return _references;
}

size_t Calculator::getReferencesLimit() const noexcept
{
	return _referencesLimit;
}

double Calculator::toDoOperation(double left, double right, char o)
{
	switch (o)
	{
	case '+': return left + right;
	case '-': return left - right;
	case '/': return left / right;
	case '*': return left * right;
	default:
		throw runtime_error("Incorrect operation.");

	}
}

void Calculator::calculationFilterOfPriorityOperation(string& expression)
{
	for (auto iterator = expression.begin(); iterator != expression.end(); ++iterator)
	{
		if (_stringValidator.isPriorityOperation(*iterator))
		{
			if (*iterator == '-' && iterator == expression.begin())
			{
				continue;
			}

			auto leftIterator = iterator - 1;
			auto rightIterator = iterator + 1;
			string leftNumber;
			string rightNumber;

			while (leftIterator != expression.begin() && !_stringValidator.isOperator(*leftIterator))
				--leftIterator;

			auto leftLimit = leftIterator;

			if (*leftIterator == '-')
			{
				leftNumber += '-';
				++leftIterator;
			}
			else if (_stringValidator.isOperator(*leftIterator))
			{
				++leftIterator;
				++leftLimit;
			}

			while (!_stringValidator.isOperator(*leftIterator))
			{
				leftNumber += *leftIterator;
				++leftIterator;
			}

			if (*rightIterator == '-')
			{
				rightNumber += '-';
				++rightIterator;
			}

			while (rightIterator != expression.end() && !_stringValidator.isOperator(*rightIterator))
			{
				rightNumber += *rightIterator;
				++rightIterator;
			}

			auto result = toDoOperation(stod(leftNumber), stod(rightNumber), *iterator);

			expression.erase(leftLimit, rightIterator);
			expression.insert(leftLimit - expression.begin(), to_string(result));

			iterator = expression.begin();
		}
	}
}
