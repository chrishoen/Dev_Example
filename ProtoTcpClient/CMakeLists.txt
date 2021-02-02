cmake_minimum_required (VERSION 3.8)

project (ProtoTcpClient CXX)

my_find_src_files (src_files ProtoTcpClient)
add_executable (ProtoTcpClient ${src_files})
my_add_compile_options (ProtoTcpClient)
my_add_pch (ProtoTcpClient)


my_inc_import_RisLib(ProtoTcpClient)
my_inc_import_CommonLib(ProtoTcpClient)

my_lib_import_CommonLib(ProtoTcpClient)
my_lib_import_RisLib(ProtoTcpClient)


if(MSVC)
   install(TARGETS ProtoTcpClient DESTINATION "C:/aaa_prime/Example")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS ProtoTcpClient DESTINATION "/opt/prime/bin")
else()
   add_custom_command(
      TARGET  ProtoTcpClient
      POST_BUILD
      COMMAND rsync -azv --chmod=ugo=rwx ProtoTcpClient rsync://debian@devtgt/prime/bin
      WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_Example/ProtoTcpClient)
endif()
