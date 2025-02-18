cmake_minimum_required(VERSION 3.10)
project(SampleProject)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)  # ヘッダーファイルのパス

# ソースコード
# set(SOURCE_FILES src/calc.cpp)
file(GLOB SOURCE_FILES src/*.cpp)

# 除外するファイル
list(REMOVE_ITEM SOURCE_FILES 
    ${PROJECT_SOURCE_DIR}/src/sample.cpp 
    ${PROJECT_SOURCE_DIR}/src/server.cpp 
    ${PROJECT_SOURCE_DIR}/src/client.cpp
)

# 実行ファイルを定義
set(SERVER src/server.cpp)
set(CLIENT src/client.cpp)

add_executable(server ${SERVER})
add_executable(client ${CLIENT})

# 実行ファイルの出力先を設定
set_target_properties(server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/exe
)
set_target_properties(client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src/exe
)

# gtest をリンクするためのライブラリリスト
set(TEST_LIBRARIES ${GTEST_LIBRARIES} pthread)

# test/ディレクトリ内の全テストファイルを取得
file(GLOB TEST_FILES test/calc_test.cpp)
list(REMOVE_ITEM TEST_FILES test/sample_test.cpp)

# 各テストファイルごとに実行ファイルを作成
foreach(TEST_FILE ${TEST_FILES})
    # ファイル名から拡張子を除いた名前を取得
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    
    # テスト用実行ファイルを作成
    add_executable(${TEST_NAME} ${TEST_FILE} ${SOURCE_FILES})

    # gtest と pthread をリンク
    target_link_libraries(${TEST_NAME} ${TEST_LIBRARIES})

    # 実行ファイルの出力先を設定
    set_target_properties(${TEST_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/exe
    )
endforeach()
