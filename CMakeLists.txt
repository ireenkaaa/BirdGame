cmake_minimum_required(VERSION 3.15)
project(BirdGame)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -static")
if (UNIX)

    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

endif(UNIX)

if (WIN32)

    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/cpp/SFML-2.5.1/lib/cmake/SFML/")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -static -mwindows")
endif(WIN32)

find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(BirdGame main.cpp BirdLogic/Board.h BirdLogic/Board.cpp)

target_link_libraries(BirdGame sfml-graphics sfml-audio)
