cmake_minimum_required (VERSION 3.8)

project (ExamThread1 CXX)
my_find_src_files (src_files ExamThread1)
add_executable (ExamThread1 ${src_files})
my_add_compile_options (ExamThread1)
my_add_pch (ExamThread1)

my_inc_import_CommonLib(ExamThread1)
my_inc_import_RisLib(ExamThread1)

my_lib_import_RisLib(ExamThread1)
my_lib_import_CommonLib(ExamThread1)

add_custom_command(
   TARGET  ExamThread1
   POST_BUILD
   COMMAND rsync -azv --chmod=ugo=rwx ExamThread1 rsync://debian@devtgt/prime/bin
   WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_NP_TTA_CProc/ExamThread1)
