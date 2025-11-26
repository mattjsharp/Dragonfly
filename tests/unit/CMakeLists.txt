file(GLOB UNIT_TESTS *.cpp)

add_executable(unit_tests ${UNIT_TESTS})
target_link_libraries(unit_tests PRIVATE dragonfly gtest gtest_main)

add_test(NAME unit_tests COMMAND unit_tests)
