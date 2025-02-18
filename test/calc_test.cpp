#include <gtest/gtest.h>
#include "calc.h"

TEST(CalcTest, AddFunc)
{
    Calc c;

    int actSum = c.Add(1, 2);
    int exSum = 3;

    ASSERT_EQ(actSum, exSum);
    ASSERT_EQ(c.Add(2, 3), 5);  // 2 + 3 が 5 であることを確認
    ASSERT_EQ(c.Add(-1, 1), 0); // -1 + 1 が 0 であることを確認
}

// Google Test を初期化してテストを実行するための main 関数を追加
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // すべてのテストを実行
}