# this one is important
SET(CMAKE_SYSTEM_NAME Linux)

# specify the cross compiler
SET(CMAKE_C_COMPILER
C:/MyDev/toolchain-rpi/bin/aarch64-linux-gnu-gcc.exe)
SET(CMAKE_CXX_COMPILER
C:/MyDev/toolchain-rpi/bin/aarch64-linux-gnu-g++.exe)
# where is the target environment
SET(CMAKE_FIND_ROOT_PATH
C:/MyDev/toolchain-beagle)
# for cmake 3.8
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

include_directories (SYSTEM 
    "${CMAKE_SYSROOT}/usr/include/"
    )
link_directories(
    "${CMAKE_SYSROOT}/usr/lib"
    "${CMAKE_SYSROOT}/usr/lib/aarch64-fsl-linux/12.2.0"
    )

