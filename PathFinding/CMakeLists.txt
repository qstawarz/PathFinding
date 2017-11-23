cmake_minimum_required(VERSION 3.8)
project(PathFinding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        #Managers
        #includes
        includes/Managers/IManager.h
        includes/Managers/Game.h
        includes/Managers/DisplayManager.h
        includes/Managers/InputManager.h
        includes/Managers/GridManager.h
        #src
        src/Managers/Game.cpp
        src/Managers/DisplayManager.cpp
        src/Managers/InputManager.cpp
        src/Managers/GridManager.cpp

        #Utils
        #includes
        includes/Utils/Cell.h
        #src
        src/Utils/Cell.cpp)

add_executable(PathFinding ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PathFinding ${SFML_LIBRARIES})
endif()