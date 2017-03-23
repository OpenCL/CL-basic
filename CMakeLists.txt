cmake_minimum_required(VERSION 2.8)

project(CL-basic)

if (CMAKE_VERSION VERSION_LESS "3.1.0")
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
endif()

# find OpenCL
find_package(OpenCL REQUIRED)

include_directories(SYSTEM ${OpenCL_INCLUDE_DIRS})

link_directories(${OpenCL_LIBRARIES}) 

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/cl_error_util.c ${CMAKE_CURRENT_SOURCE_DIR}/cl_util.c)
target_link_libraries(${PROJECT_NAME} ${OpenCL_LIBRARIES})

# If no build type specified, configure for Release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build" FORCE)
endif()

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Disable "no-unused-result" warning
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-unused-result")
endif()

# Custom post-build step: copy the file with the OpenCL kernels and
# all the input files from SOURCE_DIR to BINARY_DIR
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/OpenCLKernels.cl ${CMAKE_CURRENT_BINARY_DIR}/OpenCLKernels.cl)

