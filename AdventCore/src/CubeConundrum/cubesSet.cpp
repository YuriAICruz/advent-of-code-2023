#include "cubesSet.h"
#include "../stringUtils.h"

namespace core
{
    cubesSet::cubesSet(std::string rawData)
    {
        stringUtils::stringSplitter iterator = stringUtils::split(rawData, ",");
        for (auto value : iterator)
        {
            cubes.emplace_back(value.substr(1, value.length()));
        }
    }
}
