cmake_minimum_required(VERSION 3.0)

project(
	langtons_ant_sfml
	LANGUAGES CXX
)

# Dependecies {{{

list(APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_LIST_DIR}/cmake/modules"
)

# SFML
find_package(
	SFML 2 REQUIRED
	graphics window system
)

find_package(CAVIS 1.3.0 CONFIG REQUIRED)
find_package(flat_matrix 1.2 CONFIG REQUIRED)

# }}}

# Definitions {{{

set(
	${PROJECT_NAME}_src
	./src/main.cpp
	./src/langtons_ant.cpp
)

add_executable(
	${PROJECT_NAME}
	${${PROJECT_NAME}_src}
)

target_link_libraries(
	${PROJECT_NAME}
	PRIVATE
		${SFML_LIBRARIES}
		${SFML_DEPENDENCIES}
		CAVIS::CAVIS
		flat_matrix::flat_matrix
)

# }}}

# Installation {{{

install(
	TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin COMPONENT Runtime
)

# }}}
