cmake_minimum_required (VERSION 3.8)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)
set(MY_MACRO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/zzzMacros")
set(CMAKE_USER_MAKE_RULES_OVERRIDE "${MY_MACRO_DIR}/MyOverrides.cmake")
include("${MY_MACRO_DIR}/MyCodeMacros.cmake")
include("${MY_MACRO_DIR}/MyGlobalImports.cmake")
include("${MY_MACRO_DIR}/MyLocalImports.cmake")
include("${MY_MACRO_DIR}/MyPrecompiledHeader.cmake")
include("${MY_MACRO_DIR}/MySpecial.cmake")

project ("Dev_Example")
my_print_cmake_vars()


add_subdirectory ("Pointer")
return()

add_subdirectory ("CommonLib")
add_subdirectory ("ExampleThread1")
add_subdirectory ("ExampleThread2")
add_subdirectory ("ExampleThread3")
return()

add_subdirectory ("CommonLib")
add_subdirectory ("ExampleThread1")
add_subdirectory ("ExampleThread2")
add_subdirectory ("ExampleThread3")
add_subdirectory ("ProtoTcpClient")
add_subdirectory ("ProtoTcpServer")
add_subdirectory ("ProtoUdp")
add_subdirectory ("Test")
return()


add_subdirectory ("Test")
return()

