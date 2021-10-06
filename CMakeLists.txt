cmake_minimum_required(VERSION 3.10)

project(mostactivecookie VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-lboost_program_options")

find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

configure_file(mostactivecookie.h.in mostactivecookie.h)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
    enable_testing()
    add_test(NAME TEST COMMAND test)
endif()
add_subdirectory(utils)

add_executable(most_active_cookie active_cookie.cxx)
target_include_directories(most_active_cookie PUBLIC
                           "${PROJECT_BINARY_DIR}"
                            )
target_link_libraries(most_active_cookie ProcessFiles)
target_link_libraries(most_active_cookie ${Boost_LIBRARIES})
