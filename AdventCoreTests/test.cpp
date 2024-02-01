#include "gtest/gtest.h"
#include "calibration.h"

TEST(Calibration, FirstEnd)
{
  std::string test_value = "1abc2";
  EXPECT_EQ(12,calibration::filterData(&test_value));
}

TEST(Calibration, Middle)
{
  std::string test_value = "pqr3stu8vwx";
  EXPECT_EQ(38,calibration::filterData(&test_value));
}

TEST(Calibration, Multiple)
{
  std::string test_value = "a1b2c3d4e5f";
  EXPECT_EQ(15,calibration::filterData(&test_value));
}

TEST(Calibration, Same)
{
  std::string test_value = "treb7uchet";
  EXPECT_EQ(77,calibration::filterData(&test_value));
}
