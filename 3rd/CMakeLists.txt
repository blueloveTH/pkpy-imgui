cmake_minimum_required(VERSION 3.10)

project(3rdparty)

set(CMAKE_C_STANDARD 11)

option(PK_ENABLE_OS "" ON)
add_subdirectory(pocketpy)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} /utf-8 /Ox")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2")

    # disable -Wshorten-64-to-32 for apple
    if(APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wno-shorten-64-to-32")
    endif()
endif()

add_library(${PROJECT_NAME} STATIC naett/src/naett.c)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "iOS")
    add_subdirectory(raylib)
    target_link_libraries(
        ${PROJECT_NAME}
        pocketpy
        raylib
    )
else()
    target_link_libraries(
        ${PROJECT_NAME}
        pocketpy
    )
endif()

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    naett/include
    pocketpy/include
)