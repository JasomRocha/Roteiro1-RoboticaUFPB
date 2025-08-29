cmake_minimum_required(VERSION 3.8)
project(polygon_base)

find_package(ament_cmake REQUIRED)

add_executable(area_node src/area_node.cpp)

install(TARGETS
  area_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

