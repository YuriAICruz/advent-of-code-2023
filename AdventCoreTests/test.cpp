#include "gtest/gtest.h"
#include "calibration.h"

TEST(TestCaseName, TestName)
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);

  EXPECT_EQ(12,Calibration::filterData("1asdf2"));
}
