cmake_minimum_required(VERSION 3.17)

project(homework5)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(OpenGL)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)

#======================= INCLUSION OF VTK ======================#
set(VTK_DIR $ENV{VTK_DIR}/bin)
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#======================= INCLUSION OF Our Code ======================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

# Add the executable
if (WIN32) 
    add_executable( homework5 WIN32 ${SOURCES})
elseif(UNIX)
    add_executable( homework5 ${SOURCES})
endif()

# Add the target includes
target_include_directories(homework5 PRIVATE ${FORMS_DIR})
target_include_directories(homework5 PRIVATE ${INCLUDE_DIR})
target_include_directories(homework5 PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries( homework5 Qt5::OpenGL)
target_link_libraries( homework5 Qt5::Xml)
target_link_libraries( homework5 Qt5::Widgets)
target_link_libraries( homework5 ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries( homework5 ${VTK_LIBRARIES})

# vtk_module_autoinit is needed ( 8.90 VTK )
vtk_module_autoinit(
  TARGETS homework5
  MODULES ${VTK_LIBRARIES}
)
