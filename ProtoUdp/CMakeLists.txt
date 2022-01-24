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



if (MSVC)
   install(TARGETS ProtoUdp DESTINATION "C:/aaa_prime/Example")
elseif (MYMODE STREQUAL ubuntu OR MYMODE STREQUAL wsl) 
   install(TARGETS ProtoUdp DESTINATION "/opt/prime/bin")
elseif (MYMODE STREQUAL beagle)
   install(CODE "execute_process(COMMAND_ECHO STDOUT
      COMMAND c:/windows/system32/openssh/scp ${CMAKE_CURRENT_BINARY_DIR}/ProtoUdp pi@rpx:/opt/prime/bin)")
endif()

