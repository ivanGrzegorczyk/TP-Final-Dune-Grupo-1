cmake_minimum_required(VERSION 3.22)
project(TP_Final_Dune_Grupo_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g) #hack, reemplazar por configs Debug y Release

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(extern/libSDL2pp)
include_directories(${PROJECT_SOURCE_DIR}/extern)
include_directories(${SDL2PP_INCLUDE_DIRS})

add_executable(TP_Final_Dune_Grupo_1 sources/server_main.cpp sources/Celda.cpp headers/Celda.h sources/server_main.cpp sources/Mapa.cpp headers/Mapa.h sources/Navegador.cpp headers/Navegador.h)
add_executable(editor headers/editor/celda_editor.h headers/editor/mapa_editor.h sources/editor/editor.cpp sources/editor/celda_editor.cpp)
#include_directories(${SDL2PP_INCLUDE_DIRS})
target_link_libraries(editor ${SDL2PP_LIBRARIES})