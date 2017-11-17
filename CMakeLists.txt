cmake_minimum_required(VERSION 2.6)

# Enable debug symbols by default
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)
option(Debug "Enable debug mode" ON)

set(DungeonCrawler_DEBUG_MODE 0)
if (Debug)
	set(DungeonCrawler_DEBUG_MODE 1)
	message ("-- Debug mode activated")
endif ()

project(DungeonCrawler)
# Set srcs and includes directory
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/srcs)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/includes)
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "DungeonCrawler")
add_executable(${EXECUTABLE_NAME}
	${PROJECT_SOURCE_DIR}/main.cpp
	${PROJECT_SOURCE_DIR}/Game.cpp
	${PROJECT_SOURCE_DIR}/Map.cpp
	${PROJECT_SOURCE_DIR}/MapGenerator.cpp
	${PROJECT_SOURCE_DIR}/Block.cpp
	${PROJECT_SOURCE_DIR}/Character.cpp
	${PROJECT_SOURCE_DIR}/Display.cpp
)

# Set version information in a config.h file
set(DungeonCrawler_VERSION_MAJOR 1)
set(DungeonCrawler_VERSION_MINOR 0)
configure_file(
	"${PROJECT_INCLUDE_DIR}/config.h.in"
	"${PROJECT_INCLUDE_DIR}/config.h"
)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
# Find any version 2.X of SFML
# See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Set compilation flags
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${DungeonCrawler_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${DungeonCrawler_VERSION_MINOR}")
include(CPack)
