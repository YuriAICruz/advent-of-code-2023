#include "cubeGame.h"

#include <map>

#include "../stringUtils.h"

namespace core
{
    void cubeGame::extractId(std::string& rawData)
    {
        std::string delimiter = ":";
        auto iterator = stringUtils::split(rawData, delimiter).begin();

        std::string s = iterator.operator*();
        std::string id = s.substr(s.find(' '), s.length());
        this->id = atoi(id.c_str());

        rawData.erase(0, rawData.find(delimiter) + delimiter.length());
    }

    void cubeGame::extractSets(std::string& rawData)
    {
        stringUtils::stringSplitter iterator = stringUtils::split(rawData, ";");
        for (auto value : iterator)
        {
            sets.emplace_back(value);
        }
    }

    cubeGame::cubeGame(std::string rawData)
    {
        extractId(rawData);
        extractSets(rawData);
    }

    int cubeGame::sum(std::string color)
    {
        int sum = 0;
        auto colorHash = std::hash<std::string>{}(color);

        for (cubesSet set : sets)
        {
            for (cube cube : set.cubes)
            {
                if (cube.colorHash == colorHash)
                {
                    sum += cube.quantity;
                }
            }
        }

        return sum;
    }

    int cubeGame::max_value(std::string color)
    {
        int max = 0;
        size_t colorHash = std::hash<std::string>{}(color);

        for (cubesSet set : sets)
        {
            for (cube cube : set.cubes)
            {
                if (cube.colorHash == colorHash && cube.quantity > max)
                {
                    max = cube.quantity;
                }
            }
        }

        return max;
    }

    struct hash_min
    {
        int min;
        size_t hash;
    };

    int cubeGame::power()
    {
        std::map<size_t, int> values;
        for (cubesSet set : sets)
        {
            for (cube cube : set.cubes)
            {
                if (cube.quantity > values[cube.colorHash])
                {
                    values[cube.colorHash] = cube.quantity;
                }
            }
        }

        int power = 1;
        for (auto value : values)
        {
            power *= value.second;
        }

        return power;
    }
}
