
cmake_minimum_required(VERSION 3.22)
project(TP_Final_Dune_Grupo_1)
# ////////////////////////////////////////////////
# Find the QtWidgets library
find_package(Qt5Widgets)

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

# Agrego src a la lista de directorios de includes
include_directories(${PROJECT_SOURCE_DIR}/sources)

# Esta macro toma cada uno los parámetros y ejecuta *uic* sobre ellos
# La aplicacion uic genera headers con la definición de los widgets
# a partir de un archivo .ui
# Los nombres de los headers generados se guardan en la variable pasada
# como primer parámetro.
qt5_wrap_ui(UIS_HEADERS
        sources/mainwindow.ui
)

# Habilito el automoc para poder hacer autoconnect de señales
set(CMAKE_AUTOMOC on)
# Habilito autorcc para manejar automaticamente los QResources
set(CMAKE_AUTORCC ON)
# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

message("Headers generados: ${UIS_HEADERS}")

# ////////////////////////////////////////////////

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g) #hack, reemplazar por configs Debug y Release

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(extern/libSDL2pp)
include_directories(${PROJECT_SOURCE_DIR}/extern)
include_directories(${SDL2PP_INCLUDE_DIRS})

FILE(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/headers/*.h ui_mainwindow.h)
FILE(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/sources/*.cpp)
FILE(GLOB HEADER_EDITOR_FILES ${PROJECT_SOURCE_DIR}/headers/editor/*.h)
FILE(GLOB SRC_EDITOR_FILES ${PROJECT_SOURCE_DIR}/sources/editor/*.cpp)

add_executable(Server ${HEADER_FILES} ${SRC_FILES})
add_executable(Editor ${HEADER_EDITOR_FILES} ${SRC_EDITOR_FILES} ${UIS_HEADERS})

target_link_libraries(Editor ${SDL2PP_LIBRARIES} Qt5::Widgets Qt5::Core)