#pragma once
#include "gtest/gtest.h"
#include "src/grid.h"

TEST(Grid, hasNeigbour)
{
    auto grid = core::grid{core::grid::vector2{4,4}};
    
    grid.setLineValues("212.", 0);
    grid.setLineValues("101.", 1);
    grid.setLineValues("2121", 2);
    grid.setLineValues("..12", 3);

    const std::list<core::grid::grid::cell> n = grid.getNeighbours({1, 1}, 1);

    EXPECT_EQ(8, n.size());

    for (auto cell : n)
    {
        EXPECT_NE('.', cell.value);
    }
}

TEST(Grid, getNumber)
{    
    auto grid = core::grid{core::grid::vector2{4,4}};
    
    grid.setLineValues("123.", 0);
    grid.setLineValues("456.", 1);
    grid.setLineValues("7891", 2);
    grid.setLineValues("..12", 3);

    EXPECT_EQ(123,grid.getNumber({0,0}));
    EXPECT_EQ(456,grid.getNumber({1,1}));
    EXPECT_EQ(123,grid.getNumber({2,0}));
    EXPECT_EQ(7891,grid.getNumber({2,2}));
    EXPECT_EQ(12,grid.getNumber({3,3}));
    EXPECT_EQ(0,grid.getNumber({0,3}));
}