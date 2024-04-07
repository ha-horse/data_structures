cmake_minimum_required(VERSION 3.0)
project(NONLINEAR)

aux_source_directory(./ SRC)

set(EXECUTABLE_OUTPUT_PATH ${LIB_PATH})
add_library(${NONLINEAR_LIB} STATIC ${SRC})
