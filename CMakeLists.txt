cmake_minimum_required(VERSION 3.16)
project(TP_Final_Dune_Grupo_1)
#////////////////////////////// YAML //////////////
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIRS})
# ////////////////////////////////////////////////
# Find the QtWidgets library
find_package(Qt5Widgets)

message("[INFO] La raiz del proyecto es ${PROJECT_SOURCE_DIR}")

# Agrego src a la lista de directorios de includes
include_directories(${PROJECT_SOURCE_DIR}/game)

# Esta macro toma cada uno los parámetros y ejecuta *uic* sobre ellos
# La aplicacion uic genera headers con la definición de los widgets
# a partir de un archivo .ui
# Los nombres de los headers generados se guardan en la variable pasada
# como primer parámetro.
qt5_wrap_ui(UIS_HEADERS_EDITOR
        game/editor/newmap.ui
        game/editor/mainwindow.ui
)
qt5_wrap_ui(UIS_HEADERS_CLIENT
        game/client/clientmainwindow.ui
        game/client/pickmatchwindow.ui
        game/client/enterportwindow.ui
)

# Habilito el automoc para poder hacer autoconnect de señales
set(CMAKE_AUTOMOC on)
# Habilito autorcc para manejar automaticamente los QResources
set(CMAKE_AUTORCC ON)
# Agrego la carpeta con los headers autogenerados a los includes
message("Agregando '${PROJECT_BINARY_DIR}' como directorio de includes")
include_directories(${PROJECT_BINARY_DIR})

message("Headers generados: ${UIS_HEADERS_EDITOR} ${UIS_HEADERS_CLIENT}")

# ////////////////////////////////////////////////

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -g) #hack, reemplazar por configs Debug y Release

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_TTF ON)
add_subdirectory(extern/libSDL2pp)
ADD_DEFINITIONS(-DDATA_PATH="${PROJECT_SOURCE_DIR}/game/assets/")
ADD_DEFINITIONS(-DMAPS_PATH="${PROJECT_SOURCE_DIR}/game/server/maps/")
include_directories(extern)
include_directories(${SDL2PP_INCLUDE_DIRS})

FILE(GLOB HEADER_SERVER_FILES
        ${PROJECT_SOURCE_DIR}/game/server/headers/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/events/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/units/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/buildings/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/model/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/map/*.h
        ${PROJECT_SOURCE_DIR}/game/server/headers/vehicles/*.h)
FILE(GLOB SRC_SERVER_FILES
        ${PROJECT_SOURCE_DIR}/game/server/sources/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/events/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/units/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/buildings/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/model/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/map/*.cpp
        ${PROJECT_SOURCE_DIR}/game/server/sources/vehicles/*.cpp)

FILE(GLOB HEADER_COMMON_FILES ${PROJECT_SOURCE_DIR}/game/common/headers/*.h)
FILE(GLOB SRC_COMMON_FILES ${PROJECT_SOURCE_DIR}/game/common/sources/*.cpp)

FILE(GLOB HEADER_EDITOR_FILES ${PROJECT_SOURCE_DIR}/game/editor/headers/*.h)
FILE(GLOB SRC_EDITOR_FILES ${PROJECT_SOURCE_DIR}/game/editor/sources/*.cpp)

FILE(GLOB HEADER_CLIENT_FILES 
        ${PROJECT_SOURCE_DIR}/game/client/headers/*.h 
        ${PROJECT_SOURCE_DIR}/game/client/headers/gui/*.h)
FILE(GLOB SRC_CLIENT_FILES 
        ${PROJECT_SOURCE_DIR}/game/client/sources/*.cpp
        ${PROJECT_SOURCE_DIR}/game/client/sources/gui/*.cpp)
find_package (Threads)

add_executable(Server ${HEADER_COMMON_FILES} ${SRC_COMMON_FILES} ${HEADER_SERVER_FILES} ${SRC_SERVER_FILES})
add_executable(Editor ${HEADER_EDITOR_FILES} ${SRC_EDITOR_FILES} ${UIS_HEADERS_EDITOR} game/assets/resources.qrc)
add_executable(Client ${HEADER_COMMON_FILES} ${SRC_COMMON_FILES}  ${UIS_HEADERS_CLIENT} ${HEADER_CLIENT_FILES} ${SRC_CLIENT_FILES})

target_link_libraries (Server Threads::Threads)
target_link_libraries (Client Threads::Threads)

target_link_libraries (Server ${YAML_CPP_LIBRARIES})
target_link_libraries (Editor ${SDL2PP_LIBRARIES} Qt5::Widgets Qt5::Core ${YAML_CPP_LIBRARIES})
target_link_libraries (Client ${SDL2PP_LIBRARIES} Qt5::Widgets Qt5::Core)
