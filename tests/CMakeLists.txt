SET(PROJECT_TESTS ${PROJECT_NAME}-tests)

set(${PROJECT_TESTS}_SOURCES
    Tests.cpp
    ConvertTest.h
    ConvertTest.cpp
)

add_executable(${PROJECT_TESTS} ${${PROJECT_TESTS}_SOURCES})

target_link_libraries(${PROJECT_TESTS} PRIVATE ${PROJECT_NAME}-lib Qt6::Core Qt6::Widgets Qt6::Test)

add_test(NAME ${PROJECT_TESTS} COMMAND ${PROJECT_TESTS})
set_property(TEST ${PROJECT_TESTS} PROPERTY FAIL_REGULAR_EXPRESSION "FAIL!")
