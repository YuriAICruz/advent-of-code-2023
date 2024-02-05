#pragma once
#include <cmath>

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
