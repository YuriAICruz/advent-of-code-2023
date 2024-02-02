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

    auto n = grid.getNeighbours({1,1},1);

    EXPECT_EQ(8, n.size());

    for (auto cell : n)
    {
        EXPECT_NE('.', cell.value);
    }
}
