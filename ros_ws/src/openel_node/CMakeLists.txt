cmake_minimum_required(VERSION 3.5)
project(openel_node)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(OPENEL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../openel-arduino/src")
set(STUBS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../stubs")
set(OPENEL_TB3_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../src")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

add_executable(openel_node 
  ${OPENEL_SOURCE_DIR}/Actuator.cpp
  ${OPENEL_SOURCE_DIR}/Sensor.cpp
  ${OPENEL_SOURCE_DIR}/HALComponent.cpp
  ${OPENEL_SOURCE_DIR}/EventTimer.cpp
  ${OPENEL_SOURCE_DIR}/openEL_linkedList.cpp
  ${OPENEL_SOURCE_DIR}/openEL.cpp
  ${STUBS_SOURCE_DIR}/src/M5Stack.cpp
  src/hako_openEL_registryConfig.cpp
  src/openEL_ActuatorHako.cpp
  src/openEL_SensorHako.cpp
  src/openel_impl.cpp
  ${OPENEL_TB3_SOURCE_DIR}/main.cpp
)
ament_target_dependencies(openel_node 
  rclcpp 
  std_msgs 
  geometry_msgs 
  sensor_msgs
)
target_link_directories(openel_node
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../../../build
)

#target_link_libraries(openel_node 
#  hako-openel
#)

target_include_directories(openel_node
  PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../openel-arduino/src>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../stubs/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../src>
)

install(TARGETS
  openel_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
