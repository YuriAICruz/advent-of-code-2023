#pragma once
#include "../config.h"
#include <list>
#include "string"

namespace core
{
    class CORE_API calibration
    {
    private:
        static void addNumber(int* value, int* decimal, int digit);
        static bool isNumber(std::string* data, int& i, int* result);

    public:
        static bool getDigit(std::string* data, int& value, int& decimal, const int& i);
        static bool getNumber(std::string* data, int& value, int& decimal, int& i);
        static int filterDataOnlyDecimals(std::string* data);
        static int filterData(std::string* data);
        static std::list<int> filterData(std::list<std::string*>* data);

    private:
        static const std::string _numberDictionary[9];
    };
}
