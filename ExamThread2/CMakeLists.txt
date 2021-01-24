cmake_minimum_required (VERSION 3.8)

project (ExamThread2 CXX)
my_find_src_files (src_files ExamThread2)
add_executable (ExamThread2 ${src_files})
my_add_compile_options (ExamThread2)
my_add_pch (ExamThread2)

my_inc_import_CommonLib(ExamThread2)
my_inc_import_RisLib(ExamThread2)

my_lib_import_RisLib(ExamThread2)
my_lib_import_CommonLib(ExamThread2)

add_custom_command(
   TARGET  ExamThread2
   POST_BUILD
   COMMAND rsync -azv --chmod=ugo=rwx ExamThread2 rsync://debian@devtgt/prime/bin
   WORKING_DIRECTORY C:/Users/$ENV{username}/CMakeBuilds/Dev_NP_TTA_CProc/ExamThread2)
