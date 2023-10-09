cmake_minimum_required(VERSION 3.20)
project(New_Daemon VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

# add_executable(...)

add_subdirectory(src)
#add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
