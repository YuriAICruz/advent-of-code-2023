#include "gtest/gtest.h"
#include "calibration.h"
#include "reader.h"

TEST(Calibration, FirstEnd)
{
    std::string test_value = "1abc2";
    EXPECT_EQ(12, core::calibration::filterData(&test_value));
}

TEST(Calibration, Middle)
{
    std::string test_value = "pqr3stu8vwx";
    EXPECT_EQ(38, core::calibration::filterData(&test_value));
}

TEST(Calibration, Multiple)
{
    std::string test_value = "a1b2c3d4e5f";
    EXPECT_EQ(15, core::calibration::filterData(&test_value));
}

TEST(Calibration, Same)
{
    std::string test_value = "treb7uchet";
    EXPECT_EQ(77, core::calibration::filterData(&test_value));
}

TEST(Calibration, Spelled)
{
    std::string test_value = "two1nine";
    EXPECT_EQ(29, core::calibration::filterData(&test_value));
}

TEST(Calibration, SpelledOnly)
{
    std::string test_value = "eightwothree";
    EXPECT_EQ(83, core::calibration::filterData(&test_value));
}

TEST(Calibration, SpelledWithOutDigits)
{
    std::string test_value = "4nineeightseven2";
    EXPECT_EQ(42, core::calibration::filterData(&test_value));
}

TEST(Calibration, SpelledAndDigitAtTheEnd)
{
    std::string test_value = "zoneight234";
    EXPECT_EQ(14, core::calibration::filterData(&test_value));
}

TEST(Calibration, FullData)
{
    auto read = core::reader{"Data/calibration_input.txt"};

    std::string line;
    int sum = 0;
    while (read.getNextLine(line))
    {
        sum += core::calibration::filterDataOnlyDecimals(&line);
    }
    std::cout << "\n" << sum << "\n";
    EXPECT_EQ(55123,sum);
}

TEST(Calibration, FullDataWithSpelling)
{
    auto read = core::reader{"Data/calibration_input.txt"};

    std::string line;
    int sum = 0;
    while (read.getNextLine(line))
    {
        sum += core::calibration::filterData(&line);
    }
    std::cout << "\n" << sum << "\n";
    EXPECT_EQ(55260,sum);
}
