set(HAKO_CMAKE_VERSION 3.5.1)
cmake_minimum_required(VERSION ${HAKO_CMAKE_VERSION})

project(hakoniwa-openel
    VERSION 1.0.0
    DESCRIPTION "hakoniwa-openel project"
    LANGUAGES C CXX
)

set(OPENEL_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../openel-arduino/src")
set(STUBS_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../stubs")
set(COMMON_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../src")
set(HAKO_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../../hako/hakoniwa-core-cpp-client")
set(HAKO_PDU_SOURCE_DIR "${PROJECT_SOURCE_DIR}/../hakoniwa-ros2pdu/pdu/types")
set(MAIN_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

if (DEFINED HAKO_OPTION_FILEPATH)
    include(${HAKO_OPTION_FILEPATH})
else()
    include(default-cmake-options.cmake)
endif()

message(STATUS "BUILD_TYPE " ${BUILD_TYPE})
message(STATUS "GCOV " ${GCOV})
message(STATUS "pdu dir: " ${HAKO_PDU_SOURCE_DIR})

add_executable(
    hako-openel
    ${OPENEL_SOURCE_DIR}/Actuator.cpp
    ${OPENEL_SOURCE_DIR}/Sensor.cpp
    ${OPENEL_SOURCE_DIR}/HALComponent.cpp
    ${OPENEL_SOURCE_DIR}/EventTimer.cpp
    ${OPENEL_SOURCE_DIR}/openEL_linkedList.cpp
    ${OPENEL_SOURCE_DIR}/openEL.cpp
    ${STUBS_SOURCE_DIR}/src/M5Stack.cpp
    ${COMMON_SOURCE_DIR}/main.cpp
    ${MAIN_SOURCE_DIR}/hako_openEL_registryConfig.cpp
    ${MAIN_SOURCE_DIR}/openEL_ActuatorHako.cpp
    ${MAIN_SOURCE_DIR}/openEL_SensorHako.cpp
    ${MAIN_SOURCE_DIR}/openel_impl.cpp
)
message(STATUS "hako lib path: " ${HAKO_SOURCE_DIR}/cmake-build/core/src)
target_link_directories(hako-openel
  PRIVATE
  ${HAKO_SOURCE_DIR}/cmake-build/core/src
)

target_link_libraries(hako-openel 
  hako
  pthread
)

target_include_directories(
    hako-openel
    PRIVATE /usr/local/include
    PRIVATE ${OPENEL_SOURCE_DIR}
    PRIVATE ${STUBS_SOURCE_DIR}/include
    PRIVATE ${COMMON_SOURCE_DIR}
    PRIVATE ${HAKO_SOURCE_DIR}/core/src/include
    PRIVATE ${HAKO_PDU_SOURCE_DIR}
)
