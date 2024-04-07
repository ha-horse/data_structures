#-------------------------------------------------------------------------------
# Project setup and globals
#-------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.0)

project(data-structures LANGUAGES CXX C)

# 定义全局变量和添加子目录
#增加-std=c++11
# set(CMAKE_CXX_STANDARD 11)
#增加-std=c++14
# set(CMAKE_CXX_STANDARD 14)
#增加-std=c++17
set(CMAKE_CXX_STANDARD 17)

# 静态库生成的路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
# 测试程序生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
# 头文件目录
# set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 静态库的名字
set(LINEAR_LIB linear)
set(NONLINEAR_LIB nonlinear)

# 可执行程序的名字
set(APP_NAME_1 linear-test)
set(APP_NAME_2 nonlinear-test)

# 添加子目录
add_subdirectory(linear_structure)
add_subdirectory(nonlinear_structure)
add_subdirectory(test)