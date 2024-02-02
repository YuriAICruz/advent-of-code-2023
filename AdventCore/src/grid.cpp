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

    bool grid::isOutOfBounds(grid::vector2 finalPosition)
    {
        if (finalPosition.x < 0 || finalPosition.x >= _size.x ||
            finalPosition.y < 0 || finalPosition.y >= _size.y)
        {
            return true;
        }
        return false;
    }

    std::list<grid::cell> grid::getNeighbours(vector2 position, int size)
    {
        std::list<cell> list;

        for (vector2 direction : _directions)
        {
            for (int i = 1; i <= size; ++i)
            {
                vector2 finalPosition = position + (direction * i);
                if (isOutOfBounds(finalPosition)) continue;

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

    int grid::getNumber(vector2 position)
    {
        char v = _grid[position.x][position.y].value;

        int result = v - '0';

        if (!std::isdigit(v))
        {
            return 0;
        }

        vector2 currentPosition = position;
        while (getNextDigit(result, currentPosition, -1))
        {
        }
        currentPosition = position;
        while (getNextDigit(result, currentPosition, 1))
        {
        }
        return result;
    }

    bool grid::getNextDigit(int& result, vector2& position, int direction)
    {
        position = position + vector2{direction, 0};

        if (isOutOfBounds(position))
        {
            return false;
        }

        char v = _grid[position.x][position.y].value;
        int digit = v - '0';

        if (!std::isdigit(v))
        {
            return false;
        }

        int elevation = max(1, pow(10, -direction));
        int elevationInv = max(1, pow(10, direction));
        int zeros = elevationInv > 1 ? 1 : pow(10, int(log10(max(1, result))));
        result = (result * elevationInv) + (digit * elevation*zeros);
        return true;
    }
}
