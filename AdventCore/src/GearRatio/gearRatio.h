#pragma once
#include <string>

#include "../grid.h"
#include "../stringUtils.h"
#include "../reader.h"

namespace core
{
    class CORE_API gearRatio
    {
    public:
        gearRatio(): _grid({0, 0})
        {
        }

        void generateGridFromText(std::string rawData)
        {
            vector2 size = {0, 0};

            for (auto lineData : stringUtils::split(rawData, "\n"))
            {
                size.x = max(size.x, lineData.length());
                size.y++;
            }

            _grid = grid(size);

            int i = 0;
            for (auto lineData : stringUtils::split(rawData, "\n"))
            {
                _grid.setLineValues(lineData, i);
                i++;
            }
        }

        void generateGridFromFile(const char* path)
        {
            auto read = reader{path};

            vector2 size = {0, 0};

            std::string lineData;
            while(read.getNextLine(lineData))
            {
                size.x = max(size.x, lineData.length());
                size.y++;
            }

            _grid = grid(size);

            int i = 0;
            read.reset();
            while(read.getNextLine(lineData))
            {
                _grid.setLineValues(lineData, i);
                i++;
            }
        }

        int sumPartNumbers();
        int sumAll();
        int sumGearRatio();

    private:
        grid _grid;
        bool moveNext(vector2& position);
        void moveBack(vector2& position);
        void moveNextSkipNumber(vector2& position);
    };
}
