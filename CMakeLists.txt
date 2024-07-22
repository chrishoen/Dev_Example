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
my_append_compile_flags()
my_show_cmake_vars()



add_subdirectory ("CommonLib")
add_subdirectory ("CmdLine")
add_subdirectory ("QCallThread")
add_subdirectory ("TwoThread")
add_subdirectory ("ProtoUdpMsg")
return()

add_subdirectory ("CommonLib")
return()

add_subdirectory ("HelloWorld")
return()

add_subdirectory ("ProtoUdpMsg")
return()


add_subdirectory ("CmdLine")
return()


add_subdirectory ("CommonLib")
return()

add_subdirectory ("Test")
return()





