#pragma once
#include <gtest/gtest.h>

#include "src/GearRatio/gearRatio.h"

TEST(GearRatio, neighboursSum)
{
    auto s =
        "467..114..\n...*......\n..35..633.\n......#...\n617*......\n.....+.58.\n..592.....\n......755.\n...$.*....\n.664.598..";
    auto ratio = core::gearRatio(s);
    int sum = ratio.sumRatio();
    EXPECT_EQ(4361, sum);
}
