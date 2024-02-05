#pragma once
#include "gtest/gtest.h"
#include "src/Trebuchet/calibration.h"
#include "src/reader.h"

TEST(Trebuchet, FirstEnd)
{
    std::string test_value = "1abc2";
    EXPECT_EQ(12, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, Middle)
{
    std::string test_value = "pqr3stu8vwx";
    EXPECT_EQ(38, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, Multiple)
{
    std::string test_value = "a1b2c3d4e5f";
    EXPECT_EQ(15, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, Same)
{
    std::string test_value = "treb7uchet";
    EXPECT_EQ(77, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, Spelled)
{
    std::string test_value = "two1nine";
    EXPECT_EQ(29, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, SpelledOnly)
{
    std::string test_value = "eightwothree";
    EXPECT_EQ(83, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, SpelledWithOutDigits)
{
    std::string test_value = "4nineeightseven2";
    EXPECT_EQ(42, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, SpelledAndDigitAtTheEnd)
{
    std::string test_value = "zoneight234";
    EXPECT_EQ(14, core::calibration::filterData(&test_value));
}

TEST(Trebuchet, FullData)
{
    auto read = core::reader{"Data/1_trebuchet_input.txt"};

    std::string line;
    int sum = 0;
    while (read.getNextLine(line))
    {
        sum += core::calibration::filterDataOnlyDecimals(&line);
    }
    std::cout << "\n" << sum << "\n";
    EXPECT_EQ(55123,sum);
}

TEST(Trebuchet, FullDataWithSpelling)
{
    auto read = core::reader{"Data/1_trebuchet_input.txt"};

    std::string line;
    int sum = 0;
    while (read.getNextLine(line))
    {
        sum += core::calibration::filterData(&line);
    }
    std::cout << "\n" << sum << "\n";
    EXPECT_EQ(55260,sum);
}
