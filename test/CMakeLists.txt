add_executable(main_test test.cpp)

target_link_libraries(main_test gtest_main)

include(GoogleTest)
gtest_discover_tests(main_test)