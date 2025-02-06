cmake_minimum_required(VERSION 3.16)

project(t9-predictioner
    LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Tool used for T9 prediction of Polish words according to typed digits. "
    HOMEPAGE_URL "https://github.com/przemek83/t9-predictioner")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CODE_COVERAGE "Collect coverage" OFF)

if(CODE_COVERAGE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 --coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 --coverage")
endif()

find_package(Qt6 REQUIRED COMPONENTS Widgets Core)
qt_standard_project_setup()

# file(COPY <TODO: file> DESTINATION ${CMAKE_BINARY_DIR})

set(${PROJECT_NAME}_SOURCES
    mainwindow.h
    mainwindow.cpp
)

set(UI
    mainwindow.ui
)
source_group("UI Files" FILES ${UI})

add_library (${PROJECT_NAME}-lib STATIC ${${PROJECT_NAME}_SOURCES} ${UI})
target_link_libraries(${PROJECT_NAME}-lib PRIVATE Qt6::Core Qt6::Widgets)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib Qt6::Widgets)

# enable_testing()
# include(Tests.cmake)
# add_subdirectory(test)
