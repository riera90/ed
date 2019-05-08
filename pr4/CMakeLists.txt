cmake_minimum_required (VERSION 2.8.11)

project (graph.out)

set(SOURCES
    app/src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/app/include
)
