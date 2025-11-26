file(GLOB INTEGRATION_TESTS *.cpp)

add_executable(integration_tests ${INTEGRATION_TESTS})
target_link_libraries(integration_tests PRIVATE dragonfly gtest gtest_main)

add_test(NAME integration_tests COMMAND integration_tests)
