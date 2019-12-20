# Set binary name
set(BIN_NAME KVPStorage)

# Glob source files
file(GLOB_RECURSE APP_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Add executable
add_executable(${BIN_NAME} ${APP_SOURCES})

# Output directory for binary
set_target_properties( ${BIN_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Include directory
target_include_directories(${BIN_NAME}
	PUBLIC
	${PROJECT_SOURCE_DIR}/include/)
