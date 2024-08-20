cmake_minimum_required(VERSION 3.3)
project(csv_io_util)

set (CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Debug)

## Find ament macros and libraries
find_package(ament_cmake REQUIRED)

# add cmake functions
list (APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include (add_doxygen_compile)
include (add_gtest_compile)

# add compile options
option(BUILD_TEST "Build tests" OFF)
option(BUILD_DOC "Build documentation" OFF)
option(BUILD_ALL "Build all" OFF)

if(BUILD_ALL)
  set(BUILD_TEST ON)
  set(BUILD_DOC ON)
endif()


###########
## Build ##
###########

set(HEADERS
    include/${PROJECT_NAME}/csv_exporter.h
    include/${PROJECT_NAME}/csv_importer.h
    include/${PROJECT_NAME}/file_system_util.h
)

set(SOURCES
  src/csv_exporter.cpp
  src/csv_importer.cpp
  src/file_system_util.cpp
)

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${PROJECT_NAME}
PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:include>"
PRIVATE
  SYSTEM
)
#############
## Install ##
#############


install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_libraries(${PROJECT_NAME})
ament_export_include_directories(include)
ament_export_dependencies(yaml-cpp)

#############
## Testing ##
#############

set(TEST_SOURCES
    test/src/csv_exporter_test.cpp
    test/src/csv_importer_test.cpp
    test/src/file_system_util_test.cpp
)

add_gtest_compile()

##########
## DOCS ##
##########

add_doxygen_compile()

ament_package()