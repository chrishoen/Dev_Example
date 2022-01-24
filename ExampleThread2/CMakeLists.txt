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



if (MSVC)
   install(TARGETS ExampleThread2 DESTINATION "C:/aaa_prime/Example")
elseif (MYMODE STREQUAL ubuntu OR MYMODE STREQUAL wsl) 
   install(TARGETS ExampleThread2 DESTINATION "/opt/prime/bin")
elseif (MYMODE STREQUAL beagle)
   install(CODE "execute_process(COMMAND_ECHO STDOUT
      COMMAND c:/windows/system32/openssh/scp ${CMAKE_CURRENT_BINARY_DIR}/ExampleThread2 pi@rpx:/opt/prime/bin)")
endif()

