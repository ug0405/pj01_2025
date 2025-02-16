cmake_minimum_required(VERSION 3.10)
project(SampleProject)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # ヘッダーファイルのパス

# ソースコード
set(SOURCE_FILES src/sample.cpp)

# テストコード
set(TEST_FILES test/sample_test.cpp)

set(SERVER src/server.cpp)
set(CLIENT src/client.cpp)

# 実行可能ファイルを生成
add_executable(MyTest ${SOURCE_FILES} ${TEST_FILES})

add_executable(server ${SERVER})
add_executable(client ${CLIENT})

# 実行ファイルの出力先を test/exe に設定
set_target_properties(MyTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/exe
)

set_target_properties(server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/exe
)
set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/exe
)

# gtest と pthread をリンク
target_link_libraries(MyTest ${GTEST_LIBRARIES} pthread)

# CTest を使わず GoogleTest のオプションでテストを管理
