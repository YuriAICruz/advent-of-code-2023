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
            grid::vector2 size = {0, 0};

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

            grid::vector2 size = {0, 0};

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

    private:
        grid _grid;
        bool moveNext(grid::vector2& position);
        void moveBack(grid::vector2& position);
        void moveNextSkipNumber(grid::vector2& position);
    };
}
