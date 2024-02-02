#include "grid.h"

namespace core
{
    const grid::vector2 grid::_directions[8] = {
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
    };

    std::list<grid::cell> grid::getNeighbours(vector2 position, int size)
    {
        std::list<cell> list;

        for (vector2 direction : _directions)
        {
            for (int i = 1; i <= size; ++i)
            {
                vector2 finalPosition = position + (direction * i);
                if (finalPosition.x < 0 || finalPosition.x >= _size.x ||
                    finalPosition.y < 0 || finalPosition.y >= _size.y)
                {
                    continue;
                }

                list.push_back(_grid[finalPosition.x][finalPosition.y]);
            }
        }

        return list;
    }

    void grid::setLineValues(const std::string valueArray, int lineIndex)
    {
        if (valueArray.length() != _size.x || lineIndex >= _size.y)
        {
            throw new _exception;
        }

        for (int i = 0, n = _grid.size(); i < n; ++i)
        {
            _grid[i][lineIndex].value = valueArray[i];
        }
    }
}
