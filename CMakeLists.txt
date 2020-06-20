cmake_minimum_required(VERSION 2.8.8)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#set(HEADERS Controlador.h Decoder.h Interfaz.h List.h Terminal.h)
#set(SOURCES Controlador.cpp Decoder.cpp Interfaz.cpp List.h Terminal.cpp)
enable_testing()
add_subdirectory(Dependencies)

# add_library(
#     ListManager
#     ${HEADERS} ${SOURCES}
# )
add_library(
    ListManager
    Controlador.h Decoder.h Interfaz.h List.h Terminal.h
    Controlador.cpp Decoder.cpp Interfaz.cpp List.h Terminal.cpp
)
add_subdirectory(test)#search for a child CMakeLists.txt


