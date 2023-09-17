cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)

project(Repka)

link_directories(lib)
include_directories(include)

add_executable(${PROJECT_NAME} main.cpp Repka.hpp Puller.hpp)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-main)

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/bin/ $<TARGET_FILE_DIR:${PROJECT_NAME}>)
