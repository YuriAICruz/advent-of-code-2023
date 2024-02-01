#pragma once
#include "config.h"
#include <list> 
#include "string"


class CORE_API calibration
{
private:
    static void addNumber(int* value, int* decimal, int digit);
public:
    static int filterData(std::string* data);
    static std::list<int> filterData(std::list<std::string*>* data);
};
