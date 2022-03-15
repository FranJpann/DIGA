cmake_minimum_required(VERSION 3.5) # Version à adapter si besoin

project(tp1interface LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11) # C++ 11, peut-être 14 ou 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED) # QWidget
add_executable(HelloWorld main.cpp calculatrice.cpp calculatrice.h)
target_link_libraries(HelloWorld PRIVATE Qt5::Widgets)
