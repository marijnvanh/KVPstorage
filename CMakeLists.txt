# Works with 3.14 and tested through 3.16
cmake_minimum_required(VERSION 3.14...3.16 FATAL_ERROR)

# Project name and a few useful settings. 
project(KVPStorage
	VERSION 1.1
	DESCRIPTION "A basic key value pair storage application")

# C flags
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_STANDARD 17)



list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/extern)

enable_testing() # Must be in main file
    add_subdirectory(tests)

	include(AddGoogleTest) 


# The executable code
add_subdirectory(src)

#option(PACKAGE_TESTS "Build the tests" ON)
#if(PACKAGE_TESTS)
#    enable_testing()
#    include(GoogleTest)
#    add_subdirectory(tests)
#endif()

# Test directory

# For test
#add_subdirectory(test)