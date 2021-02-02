cmake_minimum_required (VERSION 3.8)

project (ProtoTcpServer CXX)

my_find_src_files (src_files ProtoTcpServer)
add_executable (ProtoTcpServer ${src_files})
my_add_compile_options (ProtoTcpServer)
my_add_pch (ProtoTcpServer)


my_inc_import_RisLib(ProtoTcpServer)
my_inc_import_CommonLib(ProtoTcpServer)

my_lib_import_CommonLib(ProtoTcpServer)
my_lib_import_RisLib(ProtoTcpServer)


if(MSVC)
   install(TARGETS ProtoTcpServer DESTINATION "C:/aaa_prime/Example")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS ProtoTcpServer DESTINATION "/opt/prime/bin")
else()
   add_custom_command(
      TARGET  ProtoTcpServer
      POST_BUILD
      COMMAND rsync -azv --chmod=ugo=rwx ProtoTcpServer rsync://debian@devtgt/prime/bin
      WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_Example/ProtoTcpServer)
endif()
