cmake_minimum_required(VERSION 3.4)

project(assigment_3)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#########################################################
# FIND BOOST
#########################################################
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS} )
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
link_libraries(${GLEW_LIBRARIES})
include_directories(${GLEW_INCLUDE_DIRS})
if (NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif()
#########################################################
# Find Threads
#########################################################

find_package (Threads)
if (NOT Threads_FOUND)
    message(ERROR " GLEW not found!")
endif()
#########################################################
# Include Files
#########################################################

include_directories(${Boost_INCLUDE_DIR})
include_directories(src)
# include_directories(lib/qvm/include)
# include_directories(lib/lodepng)
# include_directories(lib/tinyobjloader)

file(COPY assets DESTINATION bin)

FILE(GLOB SRC "src/**/*.h" "src/**/*.cpp")
FILE(GLOB LODEPNG "lib/lodepng/lodepng.h" "lib/lodepng/lodepng.cpp")
# FILE(GLOB TINY_OBJ_LOADER "lib/tinyobjloader/tiny_obj_loader.h" "lib/tinyobjloader/tiny_obj_loader.cc")

MESSAGE(source files: "${SRC} ${HEADER}")


add_executable(app ./app/app.cpp ${SRC} ${LODEPNG} )
target_link_libraries (app ${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})