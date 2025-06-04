cmake_minimum_required(VERSION 3.10)
project(dsa-library C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


find_package(PkgConfig REQUIRED)
pkg_check_modules(CUNIT REQUIRED cunit)

include_directories(libs)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    src/*.c
    libs/*.c
    tests/*.c
)

add_executable(out ${SRC_FILES})

target_link_libraries(out ${CUNIT_LIBRARIES})

target_include_directories(out SYSTEM PRIVATE libs)

target_compile_options(out PRIVATE ${CUNIT_CFLAGS_OTHER})
