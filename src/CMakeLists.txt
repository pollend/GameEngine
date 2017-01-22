file(GLOB ROOT_SOURCE source/*.cpp)

file(GLOB ROOT_INCLUDE_HEADER include/*.h)

file(GLOB_RECURSE NODE_HEADER include/Node/*.h)
file(GLOB_RECURSE RENDERER_HEADER include/Render/*.cpp)
file(GLOB_RECURSE UTILITY_HEADER include/Utility/*.cpp)
file(GLOB_RECURSE VERTEX_OBJECT_HEADER include/VertexObject/*.cpp)

source_group("Sources Files" FILES ${ROOT_SOURCE})

source_group("Core Files" FILES ${ROOT_INCLUDE_HEADER})
source_group("Node Files" FILES ${NODE_HEADER})
source_group("Renderer Files" FILES ${RENDERER_HEADER})
source_group("Utility Files" FILES ${UTILITY_HEADER})
source_group("Vertex Files" FILES ${VERTEX_OBJECT_HEADER})

include(Dependencies)

include_directories(include)
include_directories(../lib/tinyobjloader)
include_directories(../lib/lodepng)

FILE(GLOB LODEPNG "${PROJECT_SOURCE_DIR}/lib/lodepng/lodepng.h" "${PROJECT_SOURCE_DIR}/lib/lodepng/lodepng.cpp")
FILE(GLOB TINY_OBJ_LOADER "${PROJECT_SOURCE_DIR}/lib/tinyobjloader/tiny_obj_loader.h" "${PROJECT_SOURCE_DIR}/lib/tinyobjloader/tiny_obj_loader.cc")


add_library(SmokeEngine SHARED
        ${ROOT_SOURCE}          ${NODE_HEADER}    ${RENDERER_HEADER} ${NODE_HEADER}
        ${VERTEX_OBJECT_HEADER} ${UTILITY_HEADER} ${LODEPNG}         ${TINY_OBJ_LOADER}
        ${ROOT_INCLUDE_HEADER} )

install(TARGETS SmokeEngine EXPORT SmokeEngineTargets LIBRARY DESTINATION ${INSTALL_LIB_DIR})

install(DIRECTORY include/ DESTINATION ${INSTALL_INCLUDE_DIR})

