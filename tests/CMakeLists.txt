SET(PROJECT_TESTS ${PROJECT_NAME}-tests)

include_directories(${CMAKE_SOURCE_DIR})

set(${PROJECT_TESTS}_SOURCES
    Tests.cpp
    ConvertTest.h
    ConvertTest.cpp
    DataLoaderTest.h
    DataLoaderTest.cpp
    MainWindowTest.h
    MainWindowTest.cpp
    MappingTest.h
    MappingTest.cpp
)

file(GLOB DICTIONARY_FILES "${CMAKE_SOURCE_DIR}/*.dic")
file(COPY ${DICTIONARY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_TESTS} ${${PROJECT_TESTS}_SOURCES})

target_link_libraries(${PROJECT_TESTS} PRIVATE ${PROJECT_NAME}-lib Qt6::Core Qt6::Widgets Qt6::Test)

add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})
set_property(TEST ${PROJECT_TESTS} PROPERTY FAIL_REGULAR_EXPRESSION "FAIL!")
