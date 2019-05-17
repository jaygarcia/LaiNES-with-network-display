cmake_minimum_required(VERSION 3.14)
project(LaiNES)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-implicit-exception-spec-mismatch")


# external libraries
INCLUDE(FindPkgConfig)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

INCLUDE_DIRECTORIES(
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
)


FIND_PACKAGE(Boost REQUIRED)
FIND_PACKAGE(Threads REQUIRED)

INCLUDE_DIRECTORIES(
    ${Boost_INCLUDE_DIR}
)

add_compile_definitions(LAINES_DEBUG=true)

#    /**** LaiNES ****/
set(LAINES_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(LAINES_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(SIMPLEINI_SOURCE_DIR ${CMAKE_SOURCE_DIR}/simpleini)

INCLUDE_DIRECTORIES(
    ${SIMPLEINI_SOURCE_DIR}
    ${LAINES_LIB_DIR}/include
    ${LAINES_LIB_DIR}/include/boost
    ${LAINES_SOURCE_DIR}/
    ${LAINES_SOURCE_DIR}/include
    ${LAINES_SOURCE_DIR}/include/mappers
    ${LAINES_SOURCE_DIR}/NetworkDisplay
)

file(
    GLOB_RECURSE LAINES_SOURCE_FILES
    ${SIMPLEINI_SOURCE_DIR}/snippets.cpp
    ${LAINES_LIB_DIR}/*.hpp
    ${LAINES_LIB_DIR}/*.cpp
    ${LAINES_SOURCE_DIR}/*.hpp
    ${LAINES_SOURCE_DIR}/*.cpp
)

add_compile_definitions(__MODUS_TARGET_NETWORK_DISPLAY__=true)

add_custom_target(copy_data COMMENT "Copying data directories and files..." )

add_custom_command(TARGET copy_data POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/config)



add_executable(${PROJECT_NAME} ${LAINES_SOURCE_FILES})

message(SDL2TTF_LIBRARIES " " ${SDL2TTF_LIBRARIES})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
        ${Boost_System}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
