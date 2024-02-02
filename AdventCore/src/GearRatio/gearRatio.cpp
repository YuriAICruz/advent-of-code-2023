#include "gearRatio.h"

namespace core
{
    int gearRatio::sumPartNumbers()
    {
        grid::vector2 position = {0, 0};

        int sum = 0;
        while (position.x >= 0 && position.y >= 0)
        {
            if (_grid.isDigit(position))
            {
                std::list<grid::cell> neighbours = _grid.getNeighbours(position);
                bool isValid = false;

                for (auto neighbour : neighbours)
                {
                    if (!std::isdigit(neighbour.value) && neighbour.value != '.')
                    {
                        isValid = true;
                        break;
                    }
                }

                if (isValid)
                {
                    sum += _grid.getNumber(position);
                    moveNextSkipNumber(position);
                    moveBack(position);
                }
            }

            moveNext(position);
        }

        return sum;
    }

    int gearRatio::sumAll()
    {
        grid::vector2 position = {0, 0};

        int sum = 0;
        while (position.x >= 0 && position.y >= 0)
        {
            if (_grid.isDigit(position))
            {
                sum += _grid.getNumber(position);
                moveNextSkipNumber(position);
                moveBack(position);
            }

            moveNext(position);
        }

        return sum;
    }

    bool gearRatio::moveNext(grid::vector2& position)
    {
        position.x++;

        if (position.x >= _grid.size().x)
        {
            position.x = 0;
            position.y++;

            if (position.y >= _grid.size().y)
            {
                position = {-1, -1};
            }
            return true;
        }

        return false;
    }

    void gearRatio::moveBack(grid::vector2& position)
    {
        if (position.x < 0)
        {
            return;
        }

        position.x--;

        if (position.x < 0)
        {
            position.x = 0;
        }
    }

    void gearRatio::moveNextSkipNumber(grid::vector2& position)
    {
        if (moveNext(position))
        {
            return;
        }

        if (position.x >= 0 && position.y >= 0 && _grid.isDigit(position))
        {
            moveNextSkipNumber(position);
        }
    }
}
