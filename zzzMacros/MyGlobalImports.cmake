#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_RisLib _target)

   if (MSVC)
      set (MyRisLibImportPath  "C:/MyDev/lib/win/RisLib.lib")
   elseif (MYMODE STREQUAL "prime-beagle")
      set (MyRisLibImportPath  "C:/MyDev/lib/beagle/libRisLib.a")
   elseif (MYMODE STREQUAL "prime-ubu")
      set (MyRisLibImportPath  "/opt/toolchain/mylib/lib/ubu/libRisLib.a")
   elseif (MYMODE STREQUAL "prime-rpi-ubu")
      set (MyRisLibImportPath  "/opt/toolchain/mylib/lib/rpi/libRisLib.a")
   elseif (MYMODE STREQUAL "writer")
      set (MyRisLibImportPath  "/opt/toolchain/mylib/lib/mx93/libRisLib.a")
   endif()

   if (MSVC)
      add_library(RisLib STATIC IMPORTED)
      set_target_properties(RisLib PROPERTIES IMPORTED_LOCATION ${MyRisLibImportPath})
      target_link_libraries(RisLib INTERFACE ws2_32)
      target_link_libraries(RisLib INTERFACE winmm)
      target_link_libraries(${_target} RisLib)
   elseif (MYMODE STREQUAL "prime-beagle")
      add_library(RisLib STATIC IMPORTED)
      set_target_properties(RisLib PROPERTIES IMPORTED_LOCATION ${MyRisLibImportPath})
      target_link_libraries(${_target} RisLib)
      target_link_libraries(${_target} pthread)
      target_link_libraries(${_target} rt)
      target_link_libraries(${_target} readline)
      target_link_libraries(${_target} atomic)
   else()
      add_library(RisLib STATIC IMPORTED)
      set_target_properties(RisLib PROPERTIES IMPORTED_LOCATION ${MyRisLibImportPath})
      target_link_libraries(${_target} RisLib)
      target_link_libraries(${_target} pthread)
      target_link_libraries(${_target} rt)
      target_link_libraries(${_target} readline)
   endif()

endfunction()

function(my_inc_import_RisLib _target)

   if (MSVC OR MYMODE STREQUAL "prime-beagle")
      set (MyRisLibIncludePath "C:/MyDev/include/RisLib")
   else()
      set (MyRisLibIncludePath "/opt/toolchain/mylib/include/RisLib")
   endif()

   target_include_directories(${_target} PUBLIC ${MyRisLibIncludePath})

endfunction()


#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

function(my_lib_import_DspLib _target)

   if (MSVC)
      set (MyDspLibImportPath  "C:/MyTools/MyLib/lib/DspLib.lib")
   elseif (MYMODE STREQUAL "beagle")
      set (MyDspLibImportPath  "C:/MyTools/MyLib/lib/libDspLib.so")
   else()
      set (MyDspLibImportPath  "/opt/prime/lib/libDspLib.so")
   endif()

   add_library(DspLib SHARED IMPORTED)
   set_target_properties(DspLib PROPERTIES IMPORTED_LOCATION ${MyDspLibImportPath})

   target_link_libraries(${_target} DspLib)

endfunction()

function(my_inc_import_DspLib _target)

   if (MSVC OR MYMODE STREQUAL "beagle")
      set (MyDspLibIncludePath "C:/MyTools/MyLib/include/DspLib")
   else()
      set (MyDspLibIncludePath "/opt/prime/include/DspLib")
   endif()

   target_include_directories(${_target} PUBLIC ${MyDspLibIncludePath})

endfunction()

#*******************************************************************************
#*******************************************************************************
#*******************************************************************************

