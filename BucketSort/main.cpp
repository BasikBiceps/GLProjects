#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::size_t bucketSort(std::vector<double>& inputArray)
{
    std::vector<std::vector<double>> b(*std::max_element(inputArray.begin(), inputArray.end()) + 1);

    for (std::size_t i = 0; i < inputArray.size(); ++i)
    {
        b[static_cast<int>(inputArray[i])].push_back(inputArray[i]);
    }

    for (std::size_t i=0; i < inputArray.size(); ++i)
    {
        std::sort(b[i].begin(), b[i].end());
    }

    inputArray.clear();

    std::size_t collisionCounter = 0;

    for(auto& bucket : b)
    {
        collisionCounter = bucket.size() > collisionCounter ? bucket.size() : collisionCounter;
        for(auto& el : bucket)
        {
            inputArray.push_back(el);
        }
    }

    return collisionCounter;
}

int main() {
    std::cout << "Enter your numbers: ";

    std::vector<double> inputVector;
    double inputValue;

    while (std::cin >> inputValue)
    {
        if (inputValue == 0)
        {
            break;
        } else
        {
            inputVector.push_back(inputValue);
        }
    }

    auto collisionCounter = bucketSort(inputVector);

    std::cout << "Sort result: ";
    std::copy(inputVector.begin(), inputVector.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl <<"Collision counter: " << collisionCounter;

    return 0;
}
