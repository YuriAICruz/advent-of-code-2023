#pragma once
#include <list>
#include "cube.h"

namespace core
{
    class cubesSet
    {
    public:
        cubesSet(std::string rawData);
        std::list<cube> cubes;
    };
}
