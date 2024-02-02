#pragma once
#include "gtest/gtest.h"

#include "src/reader.h"
#include "src/GearRatio/gearRatio.h"

TEST(GearRatio, neighboursSum)
{
    auto s =
        "467..114..\n...*......\n..35..633.\n......#...\n617*......\n.....+.58.\n..592.....\n......755.\n...$.*....\n.664.598..";
    auto ratio = core::gearRatio();
    ratio.generateGridFromText(s);
    int sum = ratio.sumRatio();
    EXPECT_EQ(4361, sum);
}

TEST(GearRatio, fullData)
{
    auto ratio = core::gearRatio();
    ratio.generateGridFromFile("3_gear_ratio_input.txt");
    core::gearRatio(s);
    int sum = ratio.sumRatio();
    EXPECT_EQ(1, sum);
}