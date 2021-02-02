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
   add_custom_command(
      TARGET  ExampleThread2
      POST_BUILD
      COMMAND rsync -azv --chmod=ugo=rwx ExampleThread2 rsync://debian@devtgt/prime/bin
      WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_Example/ExampleThread2)
endif()
