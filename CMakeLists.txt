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

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Test)
qt_standard_project_setup()

file(GLOB DICTIONARY_FILES "${CMAKE_SOURCE_DIR}/*.dic")
file(COPY ${DICTIONARY_FILES} DESTINATION ${CMAKE_BINARY_DIR})

set(${PROJECT_NAME}_SOURCES
    src/MainWindow.h
    src/MainWindow.cpp
    src/Converter.h
    src/Converter.cpp
    src/DataLoader.h
    src/DataLoader.cpp
    src/Mapping.h
    src/Mapping.cpp
)

set(UI
    src/MainWindow.ui
)
source_group("UI Files" FILES ${UI})

add_library (${PROJECT_NAME}-lib STATIC ${${PROJECT_NAME}_SOURCES} ${UI})
target_link_libraries(${PROJECT_NAME}-lib PRIVATE Qt6::Core Qt6::Widgets)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib Qt6::Widgets)

enable_testing()
add_subdirectory(tests)
