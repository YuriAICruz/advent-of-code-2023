#pragma once
#include <string>
#include "../stringUtils.h"

namespace core
{
    struct cube
    {
        cube(std::string rawData)
        {
            stringUtils::stringSplitter iterator = stringUtils::split(rawData, " ");

            auto i = iterator.begin();
            auto value = i.operator*();
            quantity = atoi(i.operator*().c_str());
            value = i.iterate().operator*();
            color = value;
            colorHash = std::hash<std::string>{}(color);
        }

        int quantity;
        std::string color;
        size_t colorHash;
    };
}
