#pragma once
#include <cmath>

struct vector3Int
{
    int x;
    int y;
    int z;

    vector3Int operator+(const vector3Int& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    vector3Int operator-(const vector3Int& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    vector3Int operator++() const
    {
        return {x + 1, y + 1, z + 1};
    }

    vector3Int operator*(int mul) const
    {
        return {x * mul, y * mul, z * mul};
    }

    vector3Int operator*(vector3Int mul) const
    {
        return {x * mul.x, y * mul.y, z * mul.z};
    }

    vector3Int operator/(int value) const
    {
        return {x / value, y / value, z / value};
    }

    float length() const
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    bool operator<(const vector3Int& other) const
    {
        if (length() < other.length()) return true;
        return false;
    }

    bool operator>(const vector3Int& other) const
    {
        if (length() > other.length()) return true;
        return false;
    }

    bool operator<=(const vector3Int& other) const
    {
        if (length() <= other.length()) return true;
        return false;
    }

    bool operator>=(const vector3Int& other) const
    {
        if (length() >= other.length()) return true;
        return false;
    }

    bool operator==(const vector3Int& other) const
    {
        if (x == other.x && y == other.y && z == other.z) return true;
        return false;
    }

    bool operator!=(const vector3Int& other) const
    {
        if (x == other.x && y == other.y && z == other.z) return false;
        return true;
    }
};
