cmake_minimum_required(VERSION 3.5) # Version à adapter si besoin

project(interfacetp2 LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11) # C++ 11, peut-être 14 ou 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED) # QWidget
add_executable(${PROJECT_NAME} "main.cpp" "buttoncouleur.cpp" "buttoncouleur.h" "zonedessin.cpp" "zonedessin.h" "fenetre.cpp" "fenetre.h")
target_link_libraries(interfacetp2 PRIVATE Qt5::Widgets)
