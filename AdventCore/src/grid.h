#pragma once
#include <list>
#include <string>
#include <vector>
#include "config.h"

namespace core
{
    class CORE_API grid
    {
    public:
        struct vector2
        {
            int x;
            int y;

            vector2 operator+(const vector2& other) const
            {
                return {x + other.x, y + other.y};
            }

            vector2 operator*(int mul) const
            {
                return {x * mul, y * mul};
            }
        };

        struct cell
        {
            char value = ' ';
        };

        explicit grid(vector2 size): _size(size)
        {
            _grid = std::vector<std::vector<cell>>(size.x);
            for (int i = 0, n = _grid.size(); i < n; ++i)
            {
                _grid[i] = std::vector<cell>(size.y);
            }
        }


        bool isOutOfBounds(vector2 finalPosition);
        std::list<grid::cell> getNeighbours(vector2 position, int size = 1);
        void setLineValues(const std::string valueArray, int lineIndex);
        int getNumber(vector2 position);

    private:
        bool getNextDigit(int& result, vector2& vector2, int i);
        vector2 _size;
        static const vector2 _directions[8];
        std::vector<std::vector<cell>> _grid;
    };
}
