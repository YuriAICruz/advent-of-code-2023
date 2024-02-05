#pragma once
#include <cmath>

struct vector2Int
{
    int x;
    int y;

    vector2Int operator+(const vector2Int& other) const
    {
        return {x + other.x, y + other.y};
    }

    vector2Int operator-(const vector2Int& other) const
    {
        return {x - other.x, y - other.y};
    }

    vector2Int operator++() const
    {
        return {x + 1, y + 1};
    }

    vector2Int operator*(int mul) const
    {
        return {x * mul, y * mul};
    }

    vector2Int operator*(vector2Int mul) const
    {
        return {x * mul.x, y * mul.y};
    }

    vector2Int operator/(int value) const
    {
        return {x / value, y / value};
    }

    float length() const
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    bool operator<(const vector2Int& other) const
    {
        if (length() < other.length()) return true;
        return false;
    }

    bool operator>(const vector2Int& other) const
    {
        if (length() > other.length()) return true;
        return false;
    }

    bool operator<=(const vector2Int& other) const
    {
        if (length() <= other.length()) return true;
        return false;
    }

    bool operator>=(const vector2Int& other) const
    {
        if (length() >= other.length()) return true;
        return false;
    }

    bool operator==(const vector2Int& other) const
    {
        if (x == other.x && y == other.y) return true;
        return false;
    }

    bool operator!=(const vector2Int& other) const
    {
        if (x == other.x && y == other.y) return false;
        return true;
    }
};
