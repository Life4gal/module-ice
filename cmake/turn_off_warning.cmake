set(
	MSVC_WARNINGS 

	/Wv:18
)

set(
	GNU_WARNINGS

)

set(
	CLANG_CL_WARNINGS

)

set(
	CLANG_WARNINGS

)

macro(turn_off_warning target_name)
	message("Turn off compile warning for project ${target_name}...")
	target_compile_options(
		${target_name}
		PRIVATE

		$<$<CXX_COMPILER_ID:MSVC>:${MSVC_WARNINGS}>
		$<$<CXX_COMPILER_ID:GNU>:${GNU_WARNINGS}>
		# clang-cl
		$<$<AND:$<CXX_COMPILER_ID:Clang>,$<STREQUAL:"${CMAKE_CXX_SIMULATE_ID}","MSVC">>:${CLANG_CL_WARNINGS}>
		# clang
		$<$<AND:$<CXX_COMPILER_ID:Clang>,$<NOT:$<STREQUAL:"${CMAKE_CXX_SIMULATE_ID}","MSVC">>>:${CLANG_WARNINGS}>
	)
endmacro()
