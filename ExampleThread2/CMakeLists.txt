cmake_minimum_required (VERSION 3.8)

project (ExampleThread2 CXX)
my_find_src_files (src_files ExampleThread2)
add_executable (ExampleThread2 ${src_files})
my_add_compile_options (ExampleThread2)
my_add_pch (ExampleThread2)

my_inc_import_CommonLib(ExampleThread2)
my_inc_import_RisLib(ExampleThread2)

my_lib_import_RisLib(ExampleThread2)
my_lib_import_CommonLib(ExampleThread2)

if(MSVC)
   install(TARGETS ExampleThread2 DESTINATION "C:/aaa_prime/Example")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS ExampleThread2 DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(ExampleThread2)
endif()
