#########################################################
# FIND BOOST
#########################################################
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
FIND_PACKAGE(Boost COMPONENTS log REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS} )
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
if (NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif()
link_libraries(${GLEW_LIBRARIES})
include_directories(${GLEW_INCLUDE_DIRS})
#########################################################
# FIND GLFW3
#########################################################
find_package(glfw3 3.2 REQUIRED)
link_libraries(${GLFW_LIBRARIES})
include_directories(${GLFW_INCLUDE_DIRS})

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
########################################################
