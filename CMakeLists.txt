cmake_minimum_required(VERSION 2.8)
project(wfg)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

add_definitions("-Wextra -Wall -Wpedantic -Wfloat-equal -Wshadow -Wpointer-arith")
add_definitions("-Wcast-align -Wcast-qual -Wswitch-enum -Wconversion -Wformat=2 -std=c++11")

#region Targets

set(SRCS
src/main.cpp
src/timers.cpp
src/waveforms/SquareWave.cpp
)
add_executable(wfg ${SRCS})

#
# Install the binaries to the $PREFIX/bin directory
#
install(
    TARGETS
    wfg
    RUNTIME DESTINATION bin
)

#endregion Targets
