# ----- src/CMakeLists.txt ----- #

include_directories(../include)
add_executable(new_daemon main.c daemon.c)
# target_include_directories(test_daemon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
