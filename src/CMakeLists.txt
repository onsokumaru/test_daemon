add_executable(test_daemon main.c daemon.c)

target_include_directories(test_daemon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
