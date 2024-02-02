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
    int sum = ratio.sumPartNumbers();
    int sumAll = ratio.sumAll();
    EXPECT_EQ(4361, sum);
    EXPECT_EQ(4533, sumAll);
}

TEST(GearRatio, fullData)
{
    auto ratio = core::gearRatio();
    ratio.generateGridFromFile("Data\\3_gear_ratio_input.txt");
    core::gearRatio (s);
    int sum = ratio.sumPartNumbers();
    int sumA = ratio.sumAll();
    EXPECT_EQ(531932, sum);
    EXPECT_EQ(601653, sumA);
}

TEST(GearRatio, debugData)
{
    auto ratio = core::gearRatio();
    ratio.generateGridFromFile("Data\\3_gear_ratio_debug_input.txt");
    core::gearRatio (s);
    int sum = ratio.sumPartNumbers();
    int sumAll = ratio.sumAll();
    EXPECT_EQ(4761, sum);
    EXPECT_EQ(5068, sumAll);
}
