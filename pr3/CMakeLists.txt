cmake_minimum_required (VERSION 2.8.11)

project (binaryTree.out)

set(SOURCES
    app/src/Entity/persona.cpp
    app/src/Generator/generarpersona.cpp
    app/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/app/include
)