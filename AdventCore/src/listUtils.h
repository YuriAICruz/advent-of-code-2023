#pragma once
#include <list>
#include "CubeConundrum/cubeGame.h"

namespace core
{
    class CORE_API listUtils
    {
    public:

        template <typename T>
        static int sum(std::list<T> list, int (*func)(T))
        {
            int sum = 0;
            for (T element : list)
            {
                sum += func(element);
            }
            return sum;
        }
    };
}