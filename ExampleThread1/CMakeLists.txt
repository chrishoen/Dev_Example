cmake_minimum_required (VERSION 3.8)

project (ExampleThread1 CXX)
my_find_src_files (src_files ExampleThread1)
add_executable (ExampleThread1 ${src_files})
my_add_compile_options (ExampleThread1)
my_add_pch (ExampleThread1)

my_inc_import_CommonLib(ExampleThread1)
my_inc_import_RisLib(ExampleThread1)

my_lib_import_RisLib(ExampleThread1)
my_lib_import_CommonLib(ExampleThread1)



if (MSVC)
   install(TARGETS ExampleThread1 DESTINATION "C:/aaa_prime/Example")
elseif (MYMODE STREQUAL ubuntu OR MYMODE STREQUAL wsl) 
   install(TARGETS ExampleThread1 DESTINATION "/opt/prime/bin")
elseif (MYMODE STREQUAL beagle)
   install(CODE "execute_process(COMMAND_ECHO STDOUT
      COMMAND scp ${CMAKE_CURRENT_BINARY_DIR}/ExampleThread1 pi@rpx:/opt/prime/bin)")
endif()
