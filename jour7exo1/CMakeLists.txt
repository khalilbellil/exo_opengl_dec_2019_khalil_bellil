cmake_minimum_required(VERSION 3.13)


set(
        PROJECT_NAME_VALUE
        jour7exo1
)

project(${PROJECT_NAME_VALUE})

file(
        GLOB_RECURSE
        source_files
        src/*
)

#file(
#        COPY
#        assets
#        DESTINATION
#        ${CMAKE_BINARY_DIR}
#)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        ${PROJECT_NAME_VALUE}
        ${source_files}
        src/entities/Utils.h src/entities/Includes.h src/entities/Game.h src/entities/Game.cpp)

if (WIN32)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lmingw32
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lopengl32
            -lglu32
    )
endif ()

if (UNIX)
    TARGET_LINK_LIBRARIES(
            ${PROJECT_NAME_VALUE}
            -lSDL2main
            -lSDL2
            -lSDL2_image
            -lGL
            -lGLU
    )
endif ()