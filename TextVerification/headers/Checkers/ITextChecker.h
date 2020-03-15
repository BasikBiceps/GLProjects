#ifndef TEXTVERIFICATION_ITEXTCHECKER_H
#define TEXTVERIFICATION_ITEXTCHECKER_H

struct CheckerResult
{
    std::size_t allWordsCounter = 0;
    std::size_t incorrectWordsCounter = 0;
    std::chrono::duration<double , std::milli> checkAllTextTime;

    CheckerResult& operator+= (const CheckerResult& other)
    {
        this->allWordsCounter += other.allWordsCounter;
        this->incorrectWordsCounter += other.incorrectWordsCounter;
        this->checkAllTextTime += other.checkAllTextTime;

        return *this;
    }
};

class ITextChecker
{
public:
    ITextChecker() = default;
    virtual ~ITextChecker() = default;

    virtual CheckerResult checkText(
            std::unique_ptr<IReader> reader,
            IDictionary& dictionary,
            std::unique_ptr<std::ofstream> outputStream) = 0;
};

#endif //TEXTVERIFICATION_ITEXTCHECKER_H