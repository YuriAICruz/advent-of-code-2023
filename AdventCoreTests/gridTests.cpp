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

    std::list<core::grid::grid::cell> n = grid.getNeighbours({1, 1}, 1);

    EXPECT_EQ(8, n.size());

    for (auto cell : n)
    {
        EXPECT_NE('.', cell.value);
    }
    
    n = grid.getNeighbours({0, 0}, 1);
    EXPECT_EQ(3, n.size());
    
    n = grid.getNeighbours({3, 3}, 1);
    EXPECT_EQ(3, n.size());
    
    n = grid.getNeighbours({1, 0}, 1);
    EXPECT_EQ(5, n.size());
    
    n = grid.getNeighbours({3, 1}, 1);
    EXPECT_EQ(5, n.size());
    
    n = grid.getNeighbours({0, 1}, 1);
    EXPECT_EQ(5, n.size());
    
    n = grid.getNeighbours({1, 3}, 1);
    EXPECT_EQ(5, n.size());
}

TEST(Grid, getNumber)
{    
    auto grid = core::grid{core::grid::vector2{6,6}};
    
    grid.setLineValues("123.12", 0);
    grid.setLineValues("45.562", 1);
    grid.setLineValues("1000..", 2);
    grid.setLineValues("..125.", 3);

    EXPECT_EQ(123,grid.getNumber({0,0}));
    EXPECT_EQ(45,grid.getNumber({1,1}));
    EXPECT_EQ(123,grid.getNumber({2,0}));
    EXPECT_EQ(562,grid.getNumber({3,1}));
    EXPECT_EQ(1000,grid.getNumber({0,2}));
    EXPECT_EQ(1000,grid.getNumber({1,2}));
    EXPECT_EQ(1000,grid.getNumber({2,2}));
    EXPECT_EQ(1000,grid.getNumber({3,2}));
    EXPECT_EQ(125,grid.getNumber({3,3}));
    EXPECT_EQ(0,grid.getNumber({0,3}));
}