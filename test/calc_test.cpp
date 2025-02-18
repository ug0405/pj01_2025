#include <gtest/gtest.h>
#include "calc.h"

TEST(CalcTest, AddFunc)
{
    Calc c;
    ASSERT_EQ(c.Add(2, 3), 5);
    ASSERT_EQ(c.Add(-1, 1), 0);
}

TEST(CalcTest, Add2Func)
{
    Calc c;
    c.x_ = 5;
    c.y_ = 6;
    ASSERT_EQ(c.Add2(), 11);
}

TEST(CalcTest, SubFunc)
{
    Calc c;
    ASSERT_EQ(c.Sub(2, 3), -1);
    ASSERT_EQ(c.Sub(10, 5), 5);
}

TEST(CalcTest, MultiplyFunc)
{
    Calc c;
    ASSERT_EQ(c.Multiply(2, 3), 6);
    ASSERT_EQ(c.Multiply(10, 0), 0);
}

TEST(CalcTest, DivideFunc)
{
    Calc c;
    ASSERT_EQ(c.Divide(10, 2), 5);
    ASSERT_EQ(c.Divide(0, 5), 0);
}

// Google Test を初期化してテストを実行するための main 関数を追加
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // すべてのテストを実行
}