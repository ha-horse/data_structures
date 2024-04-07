cmake_minimum_required(VERSION 3.0)
project(LINEAR)

aux_source_directory(./ SRC)

set(EXECUTABLE_OUTPUT_PATH ${LIB_PATH})
add_library(${LINEAR_LIB} STATIC ${SRC})