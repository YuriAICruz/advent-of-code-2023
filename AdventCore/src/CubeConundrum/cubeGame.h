#pragma once
#include <list>
#include <string>
#include "cubesSet.h"
#include "../config.h"

namespace core
{
    class CORE_API cubeGame
    {
    private:
        void extractId(std::string& rawData);
        void extractSets(std::string& rawData);
    public:
        explicit cubeGame(std::string rawData);
        int id;
        std::list<cubesSet> sets;
        int sum(std::string color);
        int max_value(std::string color);
        int power();
    };
}
