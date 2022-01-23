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


if (MSVC)
   install(TARGETS ProtoTcpClient DESTINATION "C:/aaa_prime/Example")
elseif (MYMODE STREQUAL ubuntu OR MYMODE STREQUAL wsl) 
   install(TARGETS ProtoTcpClient DESTINATION "/opt/prime/bin")
elseif (MYMODE STREQUAL beagle)
   install(CODE "execute_process(COMMAND_ECHO STDOUT
      COMMAND scp ${CMAKE_CURRENT_BINARY_DIR}/ProtoTcpClient pi@rpx:/opt/prime/bin)")
endif()
