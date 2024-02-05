#pragma once
#include <list>
#include <string>
#include <vector>
#include "config.h"
#include "Math/vector2Int.h"

namespace core
{
    class CORE_API grid
    {
    public:
        struct cell
        {
            char value = ' ';
            vector2Int position = {0, 0};
        };

        explicit grid(vector2Int size): _size(size)
        {
            _grid = std::vector<std::vector<cell>>(size.x);
            for (int i = 0, n = _grid.size(); i < n; ++i)
            {
                _grid[i] = std::vector<cell>(size.y);
            }
        }


        bool isOutOfBounds(vector2Int finalPosition);
        std::list<cell> getNeighbours(vector2Int position, int size = 1);
        void setLineValues(const std::string valueArray, int lineIndex);
        int getNumber(vector2Int position);
        vector2Int getNumberOrigin(vector2Int position);
        bool isDigit(vector2Int position) const;
        bool isChar(vector2Int position, char value) const;
        vector2Int size() { return _size; }

    private:
        bool getNextDigit(std::string& number, vector2Int& vector2, int i, int& result);
        vector2Int _size;
        static const vector2Int _directions[8];
        std::vector<std::vector<cell>> _grid;
    };
}
