#include "calibration.h"

void calibration::addNumber(int* value, int* decimal, int digit)
{
    *value *= max(1, (*decimal) * 10);
    *value += digit;
    *decimal += 1;
}

int calibration::filterData(std::string* data)
{
    int value = 0;
    int decimal = 0;
    int length = data->length();

    char e;
    for (int i = 0; i < length; ++i)
    {
        e = data->at(i);

        if (!std::isdigit(e))
        {
            continue;
        }

        addNumber(&value, &decimal, e - '0');
        break;
    }

    for (int i = length - 1; i >= 0; --i)
    {
        e = data->at(i);

        if (!std::isdigit(e))
        {
            continue;
        }

        addNumber(&value, &decimal, e - '0');
        break;
    }

    return value;
}

std::list<int> calibration::filterData(std::list<std::string*>* data)
{
    auto list = std::list<int>{};
    return list;
}
