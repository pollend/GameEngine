cmake_minimum_required(VERSION 3.4)

project(assigment_3)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(../cmake/Dependencies.cmake)

find_package( SmokeEngine REQUIRED )
link_libraries(${SMOKE_ENGINE_LIBRARIES})
include_directories(${SMOKE_ENGINE_INCLUDE_DIRS})


#########################################################
# Include Files
#########################################################

include_directories(${Boost_INCLUDE_DIR})
include_directories(src/)
include_directories (../src/include)
LINK_DIRECTORIES(../bin)

FILE(GLOB_RECURSE SRC "src/*" )

file(COPY assets DESTINATION bin)
add_executable(Demo PostProcessingDemo.cpp ${SRC})
target_link_libraries (Demo SmokeEngine ${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} glfw)