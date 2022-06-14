cmake_minimum_required(VERSION 3.16)
project(TP_Final_Dune_Grupo_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g) #hack, reemplazar por configs Debug y Release

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(extern/libSDL2pp)
ADD_DEFINITIONS(-DDATA_PATH="${PROJECT_SOURCE_DIR}/game/assets/")
include_directories(extern)
include_directories(${SDL2PP_INCLUDE_DIRS})

FILE(GLOB HEADER_SERVER_FILES ${PROJECT_SOURCE_DIR}/game/server/headers/*.h ${PROJECT_SOURCE_DIR}/game/server/headers/events/*.h)
FILE(GLOB SRC_SERVER_FILES ${PROJECT_SOURCE_DIR}/game/server/sources/*.cpp ${PROJECT_SOURCE_DIR}/game/server/sources/events/*.cpp)

FILE(GLOB HEADER_COMMON_FILES ${PROJECT_SOURCE_DIR}/game/common/headers/*.h)
FILE(GLOB SRC_COMMON_FILES ${PROJECT_SOURCE_DIR}/game/common/sources/*.cpp)

FILE(GLOB HEADER_EDITOR_FILES ${PROJECT_SOURCE_DIR}/game/editor/headers/*.h)
FILE(GLOB SRC_EDITOR_FILES ${PROJECT_SOURCE_DIR}/game/editor/sources/*.cpp)

FILE(GLOB HEADER_CLIENT_FILES ${PROJECT_SOURCE_DIR}/game/client/headers/*.h)
FILE(GLOB SRC_CLIENT_FILES ${PROJECT_SOURCE_DIR}/game/client/sources/*.cpp)
find_package (Threads)

add_executable(Server ${HEADER_COMMON_FILES} ${SRC_COMMON_FILES} ${HEADER_SERVER_FILES} ${SRC_SERVER_FILES})
add_executable(Editor ${HEADER_EDITOR_FILES} ${SRC_EDITOR_FILES})
add_executable(Client ${HEADER_COMMON_FILES} ${SRC_COMMON_FILES} ${HEADER_CLIENT_FILES} ${SRC_CLIENT_FILES})

target_link_libraries (Server Threads::Threads)
target_link_libraries (Client Threads::Threads)

target_link_libraries(Editor ${SDL2PP_LIBRARIES})
target_link_libraries(Client ${SDL2PP_LIBRARIES})