// test/sample_test.cpp
#include <gtest/gtest.h>
#include "sample.h"

// add 関数のテスト
TEST(SampleTest, AddFunction)
{
    Sample sample;
    ASSERT_EQ(sample.add(2, 3), 5);  // 2 + 3 が 5 であることを確認
    ASSERT_EQ(sample.add(-1, 1), 0); // -1 + 1 が 0 であることを確認
}

// concatenate 関数のテスト
TEST(SampleTest, ConcatenateFunction)
{
    Sample sample;
    ASSERT_EQ(sample.concatenate("Hello, ", "World!"), "Hello, World!"); // "Hello, " と "World!" の結合
    ASSERT_EQ(sample.concatenate("foo", "bar"), "foobar");               // "foo" と "bar" の結合
}

// Google Test を初期化してテストを実行するための main 関数を追加
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // すべてのテストを実行
}
