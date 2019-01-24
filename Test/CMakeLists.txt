cmake_minimum_required (VERSION 3.8)

project (Test CXX)
my_find_src_files (src_files Test)
add_executable (Test ${src_files})
my_add_compile_options (Test)
my_add_pch (Test)

find_package(RisLib CONFIG REQUIRED PATHS "C:\\MyTools\\MyLib\\lib\\cmake\\RisLib" NO_DEFAULT_PATH)
#find_package(RisLib CONFIG REQUIRED)

target_include_directories(Test PRIVATE RisLib)
target_link_libraries(Test RisLib)


return()
message(STATUS "CMAKE_MODULE_PATH***********************************" ${CMAKE_MODULE_PATH})

