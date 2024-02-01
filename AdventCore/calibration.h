#pragma once
#include <list>
#include <string>

#pragma once
#define CORE_EXPORTS

#ifdef CORE_EXPORTS
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

class CORE_API Calibration
{
public:
    static int filterData(std::string data);
    static std::list<int> filterData(std::list<std::string> data);
};
