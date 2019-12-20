# Set binary name
set(BIN_NAME KVPStorage_tests)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest" "extern/googletest")

# Glob source files
file(GLOB_RECURSE APP_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Include test folder
include_directories(${PROJECT_SOURCE_DIR}/tests)

# Add executable
add_executable(${BIN_NAME} ${APP_SOURCES} KVPtest.cpp)

# Output directory for binary
#set_target_properties( ${BIN_NAME}
#    PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Include directory
target_include_directories(${BIN_NAME}
	PUBLIC
	${PROJECT_SOURCE_DIR}/include/)

	file(GLOB_RECURSE APP_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")



include(AddGoogleTest) # Could be in /tests/CMakeLists.txt
add_executable(SimpleTest KVPtest.cpp ${APP_SOURCES})
add_gtest(SimpleTest)


#include_directories(${PROJECT_SOURCE_DIR}/src)
#
#macro(add_test TEST_NAME)
#	add_executable(${TEST_NAME} ${ARGN})
#	target_link_libraries(${TEST_NAME} gtest gmock gtest_main)
#	gtest_discover_tests(${TEST_NAME}
#		WORKING_DIRECTORY ${PROJECT_DIR}
#		PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
#	)
#endmacro()
#
#add_test(test_all KVPtest.cpp
#	${APP_SOURCES}
#)
