cmake_minimum_required(VERSION 3.21)
project(micromouse LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON) # needed for reloading app config

include(FetchContent)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        TGUI
        GIT_REPOSITORY https://github.com/texus/TGUI.git
        GIT_TAG v1.8.0
)
set(TGUI_BACKEND "SFML_GRAPHICS" CACHE STRING "Backend for TGUI")
FetchContent_MakeAvailable(TGUI)


add_executable(main main.cpp
        src/core/Application.cpp
        src/core/Simulation.cpp
        src/core/Micromouse.cpp
        src/core/Maze.cpp
        src/gui/GUIManager.cpp
        src/gui/MazeRenderer.cpp
        src/gui/MouseRenderer.cpp
        src/logic/MouseSensor.cpp
        src/logic/MouseBrain.cpp
        src/model/SensorReading.cpp
        src/model/Cell.cpp
        src/utils/Randomizer.cpp
        )

target_link_libraries(main PRIVATE
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-network
        sfml-system
        tgui
        )

# Copy SFML and TGUI DLLs to the runtime directory
if (WIN32)
    add_custom_command(TARGET main POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE:sfml-audio>
            $<TARGET_FILE:sfml-network>
            $<TARGET_FILE:tgui>
            $<TARGET_FILE_DIR:main>
            COMMENT "Copying SFML and TGUI DLLs to output directory"
            )
endif ()