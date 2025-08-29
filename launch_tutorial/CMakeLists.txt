cmake_minimum_required(VERSION 3.8)
project(launch_tutorial)

find_package(ament_cmake REQUIRED)

# instala a pasta launch
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()

