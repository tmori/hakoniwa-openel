set(HAKO_CMAKE_VERSION 3.5.1)
cmake_minimum_required(VERSION ${HAKO_CMAKE_VERSION})

project(hakoniwa-openel
    VERSION 1.0.0
    DESCRIPTION "hakoniwa-openel project"
    LANGUAGES C CXX
)

set(OPENEL_SOURCE_DIR "${PROJECT_SOURCE_DIR}/openel-arduino/src")
set(STUBS_SOURCE_DIR "${PROJECT_SOURCE_DIR}/stubs")
set(MAIN_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

if (DEFINED HAKO_OPTION_FILEPATH)
    include(${HAKO_OPTION_FILEPATH})
else()
    include(default-cmake-options.cmake)
endif()

message(STATUS "BUILD_TYPE " ${BUILD_TYPE})
message(STATUS "GCOV " ${GCOV})

add_executable(
    hako-openel
    ${OPENEL_SOURCE_DIR}/Actuator.cpp
    ${OPENEL_SOURCE_DIR}/Sensor.cpp
    ${OPENEL_SOURCE_DIR}/HALComponent.cpp
    ${OPENEL_SOURCE_DIR}/EventTimer.cpp
    ${OPENEL_SOURCE_DIR}/openEL_linkedList.cpp
    ${OPENEL_SOURCE_DIR}/openEL.cpp
    ${STUBS_SOURCE_DIR}/src/M5Stack.cpp
    ${MAIN_SOURCE_DIR}/hako_openEL_registryConfig.cpp
    ${MAIN_SOURCE_DIR}/openEL_ActuatorHako.cpp
    ${MAIN_SOURCE_DIR}/main.cpp
)

target_include_directories(
    hako-openel
    PRIVATE /usr/local/include
    PRIVATE ${OPENEL_SOURCE_DIR}
    PRIVATE ${STUBS_SOURCE_DIR}/include
)

