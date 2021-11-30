cmake_minimum_required (VERSION 3.8)

project (ExampleThread3 CXX)
my_find_src_files (src_files ExampleThread3)
add_executable (ExampleThread3 ${src_files})
my_add_compile_options (ExampleThread3)
my_add_pch (ExampleThread3)

my_inc_import_CommonLib(ExampleThread3)
my_inc_import_RisLib(ExampleThread3)

my_lib_import_RisLib(ExampleThread3)
my_lib_import_CommonLib(ExampleThread3)

if(MSVC)
   install(TARGETS ExampleThread3 DESTINATION "C:/aaa_prime/Example")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS ExampleThread3 DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(ExampleThread3)
endif()
