#include "cubeGame.h"

#include "../stringUtils.h"

void core::cubeGame::extractId(std::string& rawData)
{
    std::string delimiter = ":";
    auto iterator = stringUtils::split(rawData, delimiter).begin();
    
    std::string s = iterator.operator*();
    std::string id = s.substr(s.find(' '), s.length());
    this->id = atoi(id.c_str());

    rawData.erase(0, rawData.find(delimiter) + delimiter.length());
}

void core::cubeGame::extractSets(std::string& rawData)
{
    stringUtils::stringSplitter iterator = stringUtils::split(rawData, ";");
    for (auto value : iterator)
    {
        sets.emplace_back(value);
    }
}

core::cubeGame::cubeGame(std::string rawData)
{
    extractId(rawData);
    extractSets(rawData);
}

int core::cubeGame::sum(std::string color)
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
