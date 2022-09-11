cmake_minimum_required(VERSION 3.20)

project(
		module-ice
		LANGUAGES CXX
)

set(GLOBAL_SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CONFIG_PATH ${GLOBAL_SOURCE_PATH}/config)
set(CMAKE_MODULE_PATH ${GLOBAL_SOURCE_PATH}/cmake)
set(CMAKE_3RDPARTY_PATH ${GLOBAL_SOURCE_PATH}/3rd-party)

include(${CMAKE_MODULE_PATH}/compile_options_setter.cmake)
include(${CMAKE_MODULE_PATH}/turn_off_warning.cmake)

add_subdirectory(project)
add_subdirectory(standalone_test)
