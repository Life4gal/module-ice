project(
		module-ice
		LANGUAGES CXX
)

file(
	GLOB_RECURSE  
	${PROJECT_NAME}_SOURCE 
	CONFIGURE_DEPENDS 

	${PROJECT_SOURCE_DIR}/include/*.ixx
)

add_library(
	${PROJECT_NAME}
	# todo
	STATIC

	${${PROJECT_NAME}_SOURCE}
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC 
	
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(
	my::project
	ALIAS
	${PROJECT_NAME}
)

set(CMAKE_CXX_STANDARD 23)
set_compile_options_private(${PROJECT_NAME})
turn_off_warning(${PROJECT_NAME})

include(${CMAKE_3RDPARTY_PATH}/spdlog.cmake)
#include(${CMAKE_3RDPARTY_PATH}/fmtlib.cmake)

#target_compile_definitions(
#	${PROJECT_NAME}
#	PUBLIC
#
#	SPDLOG_FMT_EXTERNAL
#)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC

	#fmt::fmt
	# spdlog
	spdlog_header_only
)
