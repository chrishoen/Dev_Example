cmake_minimum_required (VERSION 3.8)

project (ProtoUdp CXX)

my_find_src_files (src_files ProtoUdp)
add_executable (ProtoUdp ${src_files})
my_add_compile_options (ProtoUdp)
my_add_pch (ProtoUdp)

my_inc_import_RisLib(ProtoUdp)
my_inc_import_CommonLib(ProtoUdp)

my_lib_import_CommonLib(ProtoUdp)
my_lib_import_RisLib(ProtoUdp)

if(MSVC)
   install(TARGETS ProtoUdp DESTINATION "C:/aaa_prime/Example")
elseif(NOT CMAKE_SYSTEM_VERSION EQUAL 101)
   install(TARGETS ProtoUdp DESTINATION "/opt/prime/bin")
else()
   my_post_build_bin(ProtoUdp)
endif()
