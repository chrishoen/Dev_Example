cmake_minimum_required (VERSION 3.8)

project (ExamThread3 CXX)
my_find_src_files (src_files ExamThread3)
add_executable (ExamThread3 ${src_files})
my_add_compile_options (ExamThread3)
my_add_pch (ExamThread3)

my_inc_import_CommonLib(ExamThread3)
my_inc_import_RisLib(ExamThread3)

my_lib_import_RisLib(ExamThread3)
my_lib_import_CommonLib(ExamThread3)

add_custom_command(
   TARGET  ExamThread3
   POST_BUILD
   COMMAND rsync -azv --chmod=ugo=rwx ExamThread3 rsync://debian@devtgt/prime/bin
   WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_NP_TTA_CProc/ExamThread3)
