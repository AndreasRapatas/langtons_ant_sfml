cmake_minimum_required(VERSION 3.0)

project(langtons_ant_sfml)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
	${PROJECT_NAME}
	./src/main.cpp
	./src/langtons_ant.cpp
)

find_package(CAVIS 1.2 CONFIG REQUIRED)
find_package(flat_matrix 1.2 CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")
find_package(SFML 2 REQUIRED network audio graphics window system)

target_link_libraries(
	${PROJECT_NAME}
	${SFML_LIBRARIES}
	${SFML_DEPENDENCIES}
	CAVIS::CAVIS
	flat_matrix::flat_matrix
)

