#pragma once
#include <iostream>
#include <vector>

class StringValidator
{
public:
    void removeSpaces(std::string& str);
    void referencesReplacement(std::string& str, std::vector<double>& references);
    bool stringIsValidForCalculate(std::string& str);
    bool operatorsValidator(std::string& str);
    bool isOperator(char symbol) const noexcept;
    bool isPriorityOperation(char o) const noexcept ;
private:
    const std::size_t _kMinimalLength = 3;
};