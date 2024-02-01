#include "calibration.h"

namespace core
{
    const std::string calibration::_numberDictionary[9] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    void calibration::addNumber(int* value, int* decimal, int digit)
    {
        *value *= max(1, (*decimal) * 10);
        *value += digit;
        *decimal += 1;
    }

    bool calibration::isNumber(std::string* data, int& index, int* result)
    {
        for (int position = 0, n = sizeof(_numberDictionary)/sizeof(std::string); position < n; ++position)
        {
            std::string numberText = _numberDictionary[position];
            int length = numberText.length();
            int dataLength = data->length();
            int count = 0;
            for (int i = 0; i < length; ++i)
            {
                if (numberText[i] != data->at(min(index + i, dataLength-1)))
                {
                    break;
                }
                count++;
            }
            if (count == length)
            {
                *result = position+1;
                return true;
            }
        }

        *result = -1;
        return false;
    }

    bool calibration::getDigit(std::string* data, int& value, int& decimal, const int& i)
    {
        const char e = data->at(i);
        
        if (std::isdigit(e))
        {
            addNumber(&value, &decimal, e - '0');
            return true;
        }
        return false;
    }

    bool calibration::getNumber(std::string* data, int& value, int& decimal, int& i)
    {
        if (getDigit(data, value, decimal, i))
        {
            return true;
        }

        int digit;
        if (isNumber(data, i, &digit))
        {
            addNumber(&value, &decimal, digit);
            return true;
        }

        return false;
    }

    int calibration::filterDataOnlyDecimals(std::string* data)
    {
        int value = 0;
        int decimal = 0;
        int length = data->length();

        for (int i = 0; i < length; ++i)
        {
            if (getDigit(data, value, decimal, i))
            {
                break;
            }
        }

        for (int i = length - 1; i >= 0; --i)
        {
            if (getDigit(data, value, decimal, i))
            {
                break;
            }
        }

        return value;
    }

    int calibration::filterData(std::string* data)
    {
        int value = 0;
        int decimal = 0;
        int length = data->length();

        char e;
        for (int i = 0; i < length; ++i)
        {
            if (getNumber(data, value, decimal, i)) break;
        }

        for (int i = length - 1; i >= 0; --i)
        {
            if (getNumber(data, value, decimal, i)) break;
        }

        return value;
    }

    std::list<int> calibration::filterData(std::list<std::string*>* data)
    {
        auto list = std::list<int>{};
        return list;
    }
}
