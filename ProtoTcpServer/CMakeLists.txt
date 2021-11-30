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
   my_post_build_bin(ProtoTcpServer)
endif()
