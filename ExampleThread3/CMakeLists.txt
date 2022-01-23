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


if (MSVC)
   install(TARGETS ExampleThread3 DESTINATION "C:/aaa_prime/Example")
elseif (MYMODE STREQUAL ubuntu OR MYMODE STREQUAL wsl) 
   install(TARGETS ExampleThread3 DESTINATION "/opt/prime/bin")
elseif (MYMODE STREQUAL beagle)
   install(CODE "execute_process(COMMAND_ECHO STDOUT
      COMMAND scp ${CMAKE_CURRENT_BINARY_DIR}/ExampleThread3 pi@rpx:/opt/prime/bin)")
endif()
