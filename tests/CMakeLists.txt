# ----- tests/CMakeLists.txt ----- #

include_directories(../include)

add_executable(test_daemon test_daemon.c)
add_test(NAME jpswd_test COMMAND test_daemon)
set_tests_properties(jpswd_test PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})