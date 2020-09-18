cmake_minimum_required(VERSION 3.9)

project(gamepad_monitor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
  add_compile_options("-frelaxed-template-template-args")
endif()

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

set(SOURCES main.cpp gamepad_manager.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC ${EVDEV_LIBRARIES} ${UDEV_LIBRARIES} ${SDL2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${EVDEV_INCLUDE_DIRS} ${UDEV_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/gamecontrollerdb.txt
  $<TARGET_FILE_DIR:${PROJECT_NAME}>
  )

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  ${CMAKE_CURRENT_SOURCE_DIR}/run.sh
  $<TARGET_FILE_DIR:${PROJECT_NAME}>
  )
