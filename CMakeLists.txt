cmake_minimum_required(VERSION 3.4)
project(SmokeEngine)
set(SMOKE_ENGINE_VERSION "0.0.1")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CMakePackageConfigHelpers)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall ")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")


# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib/SmokeEngine CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin/SmokeEngine CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include/SmokeEngine CACHE PATH "Installation directory for header files")
if(WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
else()
    set(DEF_INSTALL_CMAKE_DIR lib/cmake/SmokeEngine)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")
add_subdirectory(src)

export(PACKAGE SmokeEngine)

export(TARGETS SmokeEngine FILE "${PROJECT_BINARY_DIR}/SmokeEngineTargets.cmake")

# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(cmake/SmokeEngineConfig.cmake.in
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/SmokeEngineConfig.cmake" @ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(cmake/SmokeEngineConfig.cmake.in
        "${PROJECT_BINARY_DIR}/SmokeEngineConfig.cmake" @ONLY)

# ... for both
configure_file(cmake/SmokeEngineConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/SmokeEngineConfigVersion.cmake" @ONLY)


# Install the FooBarConfig.cmake and FooBarConfigVersion.cmake
install(FILES
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/SmokeEngineConfig.cmake"
        "${PROJECT_BINARY_DIR}/SmokeEngineConfigVersion.cmake"
        DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(EXPORT SmokeEngineTargets DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)