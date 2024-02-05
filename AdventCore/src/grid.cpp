#include "grid.h"

namespace core
{
    const vector2 grid::_directions[8] = {
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0},
    };

    bool grid::isOutOfBounds(vector2 finalPosition)
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
            _grid[i][lineIndex].position = {i, lineIndex};
        }
    }

    int grid::getNumber(vector2 position)
    {
        if (!isDigit(position))
        {
            return 0;
        }

        char v = _grid[position.x][position.y].value;

        int result = v - '0';

        std::string number;
        number.push_back(v);
        vector2 currentPosition = position;
        while (getNextDigit(number, currentPosition, -1, result))
        {
        }
        currentPosition = position;
        while (getNextDigit(number, currentPosition, 1, result))
        {
        }
        return result;
    }

    vector2 grid::getNumberOrigin(vector2 position)
    {
        if (!isDigit(position))
        {
            return position;
        }
        int result = 0;

        std::string number;
        vector2 currentPosition = position;
        while (getNextDigit(number, currentPosition, -1, result))
        {
        }
        return currentPosition + vector2{1, 0};
    }

    bool grid::isDigit(vector2 position) const
    {
        return std::isdigit(_grid[position.x][position.y].value);
    }

    bool grid::isChar(vector2 position, char value) const
    {
        return _grid[position.x][position.y].value == value;
    }

    bool grid::getNextDigit(std::string& number, vector2& position, int direction, int& result)
    {
        position = position + vector2{direction, 0};

        if (isOutOfBounds(position))
        {
            return false;
        }

        if (!isDigit(position))
        {
            return false;
        }

        char v = _grid[position.x][position.y].value;

        if (direction < 0)
        {
            number = v + number;
        }
        else
        {
            number.push_back(v);
        }

        result = atoi(number.c_str());
        return true;
    }
}
