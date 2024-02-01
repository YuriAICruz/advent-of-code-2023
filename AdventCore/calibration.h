#pragma once
#include "config.h"
#include <list>
#include <string>


class CORE_API Calibration
{
public:
    static int filterData(std::string data);
    static std::list<int> filterData(std::list<std::string> data);
};
