#pragma once
#include <string>

#include "../grid.h"
#include "../stringUtils.h"

namespace core
{
    class CORE_API gearRatio
    {
    public:
        gearRatio(std::string rawData): _grid({0,0})
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
                _grid.setLineValues(lineData,i);
                i++;
            }
        }

        int sumRatio();

    private:
        grid _grid;
        void moveNext(grid::vector2& position);
        void moveBack(grid::vector2& position);
        void moveNextSkipNumber(grid::vector2& position);
    };
}
