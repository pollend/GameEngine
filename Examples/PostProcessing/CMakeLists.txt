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
# Find Eigen
#########################################################
find_package( Eigen3 REQUIRED )
IF( NOT EIGEN3_INCLUDE_DIR )
    MESSAGE( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
ENDIF()
include_directories ( "${EIGEN3_INCLUDE_DIR}" )

#########################################################
# Include Files
#########################################################

include_directories(${Boost_INCLUDE_DIR})
include_directories(./)
include_directories (./../../src/include/ )
LINK_DIRECTORIES(./../../bin)

file(COPY assets DESTINATION bin)
add_executable(Demo ./PostProcessingDemo.cpp ./ExampleSceneOne.h ./ExampleSceneOne.cpp JulianSet.h JulianSet.cpp)
target_link_libraries (Demo SmokeEngine ${Boost_LOG_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})