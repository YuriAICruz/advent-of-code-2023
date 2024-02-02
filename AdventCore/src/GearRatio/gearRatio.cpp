#include "gearRatio.h"

namespace core
{
    int gearRatio::sumRatio()
    {
        grid::vector2 position = {0, 0};

        int sum = 0;
        while (position.x >= 0 || position.y >= 0)
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

    void gearRatio::moveNext(grid::vector2& position)
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
        }
    }

    void gearRatio::moveBack(grid::vector2& position)
    {
        position.x--;

        if (position.x < 0)
        {
            position.x = 0;
        }
    }

    void gearRatio::moveNextSkipNumber(grid::vector2& position)
    {
        moveNext(position);

        if (_grid.isDigit(position))
        {
            moveNextSkipNumber(position);
        }
    }
}
