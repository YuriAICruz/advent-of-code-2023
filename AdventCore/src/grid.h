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

            vector2 operator++() const
            {
                return {x + 1, y + 1};
            }

            vector2 operator*(int mul) const
            {
                return {x * mul, y * mul};
            }

            float length() const
            {
                return sqrt(pow(x, 2) + pow(y, 2));
            }

            bool operator<(const vector2& other) const
            {
                if (length() < other.length()) return true;
                return false;
            }

            bool operator>(const vector2& other) const
            {
                if (length() > other.length()) return true;
                return false;
            }

            bool operator<=(const vector2& other) const
            {
                if (length() <= other.length()) return true;
                return false;
            }

            bool operator>=(const vector2& other) const
            {
                if (length() >= other.length()) return true;
                return false;
            }

            bool operator==(const vector2& other) const
            {
                if (x == other.x && y == other.y) return true;
                return false;
            }

            bool operator!=(const vector2& other) const
            {
                if (x == other.x && y == other.y) return false;
                return true;
            }
        };

        struct cell
        {
            char value = ' ';
            vector2 position = {0, 0};
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
        std::list<cell> getNeighbours(vector2 position, int size = 1);
        void setLineValues(const std::string valueArray, int lineIndex);
        int getNumber(vector2 position);
        vector2 getNumberOrigin(vector2 position);
        bool isDigit(vector2 position) const;
        bool isChar(vector2 position, char value) const;
        vector2 size() { return _size; }

    private:
        bool getNextDigit(std::string& number, vector2& vector2, int i, int& result);
        vector2 _size;
        static const vector2 _directions[8];
        std::vector<std::vector<cell>> _grid;
    };
}
