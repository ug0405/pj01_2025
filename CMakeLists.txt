cmake_minimum_required(VERSION 3.10)
project(SampleProject)

set(CMAKE_CXX_STANDARD 14)

# GoogleTest をインクルード
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # ヘッダーファイルのパス

# ソースコード
set(SOURCE_FILES
    src/sample.cpp
)

# テストコード
set(TEST_FILES
    test/sample_test.cpp
)

# 実行可能ファイルを生成
add_executable(MyTest ${SOURCE_FILES} ${TEST_FILES})

# 実行ファイルの出力先を test ディレクトリに設定
set_target_properties(MyTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/exe
)

# gtest と pthread をリンク
target_link_libraries(MyTest ${GTEST_LIBRARIES} pthread)
