cmake_minimum_required(VERSION 3.8)
project(polygon_plugins)

find_package(ament_cmake REQUIRED)
find_package(pluginlib REQUIRED)
find_package(polygon_base REQUIRED)

add_library(polygon_plugins SHARED src/polygon_plugins.cpp)
target_compile_features(polygon_plugins PUBLIC cxx_std_17)
target_include_directories(polygon_plugins PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
ament_target_dependencies(polygon_plugins pluginlib polygon_base)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  TARGETS polygon_plugins
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(
  FILES plugins.xml
  DESTINATION share/${PROJECT_NAME}
)

ament_export_include_directories(include)
ament_export_libraries(polygon_plugins)
ament_export_targets(export_${PROJECT_NAME})

ament_package()

