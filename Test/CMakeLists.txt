cmake_minimum_required (VERSION 3.8)

project (Test CXX)
my_find_src_files (src_files Test)
add_executable (Test ${src_files})
my_add_compile_options (Test)
my_add_pch (Test)

set (CMAKE_FRAMEWORK_PATH "C:\\MyTools\\MyLib\\lib\\cmake")
message(STATUS "CMAKE_PREFIX_PATH***********************************" ${CMAKE_PREFIX_PATH})
message(STATUS "CMAKE_FRAMEWORK_PATH********************************" ${CMAKE_FRAMEWORK_PATH})
message(STATUS "CMAKE_APPBUNDLE_PATH********************************" ${CMAKE_APPBUNDLE_PATH})


find_package(RisLib CONFIG REQUIRED)
#find_package(RisLib CONFIG REQUIRED PATHS "C:\\MyTools\\MyLib\\lib\\cmake")

target_include_directories(Test PRIVATE RisLib)
target_link_libraries(Test RisLib)


return()

