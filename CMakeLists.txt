cmake_minimum_required(VERSION 3.22)
project(TP_Final_Dune_Grupo_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g) #hack, reemplazar por configs Debug y Release

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(extern/libSDL2pp)

include_directories(${PROJECT_SOURCE_DIR}/extern)
include_directories(${SDL2PP_INCLUDE_DIRS})

FILE(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/headers/*.h)
FILE(GLOB HEADER_EDITOR_FILES ${PROJECT_SOURCE_DIR}/headers/editor/*.h)
FILE(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/sources/editor/*.cpp)
FILE(GLOB SRC_EDITOR_FILES ${PROJECT_SOURCE_DIR}/sources/editor/*.cpp)

add_executable(Server ${HEADER_FILES} ${SRC_FILES})
add_executable(Editor ${HEADER_EDITOR_FILES} ${SRC_EDITOR_FILES})

target_link_libraries(Editor ${SDL2PP_LIBRARIES})