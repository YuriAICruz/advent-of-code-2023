#pragma once
#include <list>
#include "CubeGame/cubeGame.h"

namespace core
{
    class CORE_API listUtils
    {
    public:
        static int sum(std::list<core::cubeGame> list, int (*func)(core::cubeGame))
        {
            int sum = 0;
            for (core::cubeGame element : list)
            {
                sum += func(element);
            }
            return sum;
        }
    };
}