cmake_minimum_required(VERSION 3.14)

project(05CallMatAddTest LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

include_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include"
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\include\\win64"
  "F:\\MatlabTest\\matAdd3_vc19\\matAdd3\\for_redistribution_files_only"
  "C:\\Eigen\\eigen3_4_0"
  "C:\\Eigen\\Spectra")

link_directories(
  "D:\\Program Files\\MATLAB\\R2022b\\extern\\lib\\win64\\microsoft"
  "F:\\MatlabTest\\matAdd3_vc19\\matAdd3\\for_redistribution_files_only")

add_executable(05CallMatAddTest main.cpp)

set(LIB_PROJ
    "libmex.lib"
    "libmx.lib"
    "libmat.lib"
    "libeng.lib"
    "mclmcr.lib"
    "mclmcrrt.lib"
    "matAdd3.lib")

target_link_libraries(05CallMatAddTest Qt${QT_VERSION_MAJOR}::Core ${LIB_PROJ})

install(
  TARGETS 05CallMatAddTest
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
