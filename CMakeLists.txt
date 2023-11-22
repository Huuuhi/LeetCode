cmake_minimum_required(VERSION 3.23)
project(LeetCode_Clion)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} "307. 区域和检索 - 数组可修改.cpp" "1334. 阈值距离内邻居最少的城市.cpp" 2304.网格中最小路径的代价.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})
