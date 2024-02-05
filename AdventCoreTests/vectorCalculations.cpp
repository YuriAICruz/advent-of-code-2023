#pragma once
#include <gtest/gtest.h>

#include "src/Math/vector2Int.h"
#include "src/Math/vector3Int.h"

TEST(VectorCalculations, length3)
{
    vector3Int a = {0, 0, 1};
    EXPECT_EQ(1, a.length());
    
    a = {0, 2, 0};
    EXPECT_EQ(2, a.length());
    
    a = {3, 0, 0};
    EXPECT_EQ(3, a.length());
    
    a = {1, 1, 1};
    EXPECT_GT(a.length(), 1.5);
}

TEST(VectorCalculations, length)
{
    vector2Int a = {0, 1};
    EXPECT_EQ(1, a.length());
    
    a = {0, 2};
    EXPECT_EQ(2, a.length());
    
    a = {3, 0};
    EXPECT_EQ(3, a.length());
    
    a = {1, 1};
    EXPECT_GT(a.length(), 1);
}

TEST(VectorCalculations, sum3)
{
    vector3Int a = {1, 1, 1};
    vector3Int b = {1, 1, 1};

    vector3Int result = {2, 2, 2};

    EXPECT_EQ(result, a+b);

    a = {1, 2, 3};
    b = {4, 5, 6};
    result = {5, 7, 9};

    EXPECT_EQ(result, a+b);
}

TEST(VectorCalculations, sum)
{
    vector2Int a = {1, 1};
    vector2Int b = {1, 1};

    vector2Int result = {2, 2};

    EXPECT_EQ(result, a+b);

    a = {1, 2};
    b = {4, 5};
    result = {5, 7};

    EXPECT_EQ(result, a+b);
}

TEST(VectorCalculations, subtract3)
{
    vector3Int a = {1, 1, 1};
    vector3Int b = {1, 1, 1};

    vector3Int result = {0, 0, 0};

    EXPECT_EQ(result, a-b);

    a = {1, 2, 3};
    b = {4, 5, 6};
    result = {-3, -3, -3};

    EXPECT_EQ(result, a-b);
    result = {3, 3, 3};

    EXPECT_EQ(result, b-a);
}

TEST(VectorCalculations, subtract)
{
    vector2Int a = {1, 1};
    vector2Int b = {1, 1};

    vector2Int result = {0, 0};

    EXPECT_EQ(result, a-b);

    a = {1, 2};
    b = {4, 5};
    result = {-3, -3};

    EXPECT_EQ(result, a-b);
    
    result = {3, 3};
    EXPECT_EQ(result, b-a);
}

TEST(VectorCalculations, mul3)
{
    vector3Int a = {1, 1, 1};

    vector3Int result = {2, 2, 2};

    EXPECT_EQ(result, a*2);

    a = {1, 2, 3};
    result = {2, 4, 6};

    EXPECT_EQ(result, a*2);
}

TEST(VectorCalculations, mul)
{
    vector2Int a = {1, 1};

    vector2Int result = {2, 2};

    EXPECT_EQ(result, a*2);

    a = {1, 2};
    result = {2, 4};

    EXPECT_EQ(result, a*2);
}

TEST(VectorCalculations, div3)
{
    vector3Int a = {2, 2, 2};

    vector3Int result = {1, 1, 1};

    EXPECT_EQ(result, a/2);

    a = {4, 6, 9};
    result = {2, 3, 4};

    EXPECT_EQ(result, a/2);
}

TEST(VectorCalculations, div)
{
    vector2Int a = {2, 2};

    vector2Int result = {1, 1};

    EXPECT_EQ(result, a/2);

    a = {4, 6};
    result = {2, 3};

    EXPECT_EQ(result, a/2);
}

TEST(VectorCalculations, scale3)
{
    vector3Int a = {2, 2, 2};
    vector3Int b = {2, 2, 2};

    vector3Int result = {4, 4, 4};

    EXPECT_EQ(result, a*b);

    a = {1, 2, 3};
    b = {2, 3, 4};
    result = {2, 6, 12};

    EXPECT_EQ(result, a*b);
}

TEST(VectorCalculations, scale)
{
    vector2Int a = {2, 2};
    vector2Int b = {2, 2};

    vector2Int result = {4, 4};

    EXPECT_EQ(result, a*b);

    a = {1, 2};
    b = {2, 3};
    result = {2, 6};

    EXPECT_EQ(result, a*b);
}
