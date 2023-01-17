# the name of the target operating system
#set(CMAKE_SYSTEM_NAME Linux)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   mipsel-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER mipsel-linux-gnu-g++)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH /usr/mipsel-linux-gnu /home/s/hiby-firmware-tools/firmware-1.7-custom)

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers and libraries in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
