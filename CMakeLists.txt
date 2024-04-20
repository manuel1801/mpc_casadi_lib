cmake_minimum_required(VERSION 3.11...3.22)


project(mpc_casadi_lib VERSION 1.0.1 LANGUAGES CXX)




find_package(CASADI REQUIRED)
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${CASADI_INCLUDE_DIR}
)








include(GNUInstallDirs)

set(DEFAULT_BUILD_TYPE "Release")

set(src src/mpc_casadi_lib.cpp src/model_base.cpp)


add_library(${PROJECT_NAME} SHARED ${src})

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

target_link_libraries(${PROJECT_NAME} ${CASADI_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1)



# Install the Library
install(TARGETS ${PROJECT_NAME} EXPORT MPCCasadiLibConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
install(EXPORT MPCCasadiLibConfig DESTINATION share/MPCCasadiLib/cmake)
export(TARGETS ${PROJECT_NAME} FILE MPCCasadiLibConfig.cmake)


# Create Examples
add_subdirectory(examples)

