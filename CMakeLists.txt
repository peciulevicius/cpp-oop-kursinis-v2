cmake_minimum_required(VERSION 3.30)
project(cpp_oop_kursinis_v2)

set(CMAKE_CXX_STANDARD 26)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(cpp_oop_kursinis_v2
        main.cpp
        paraiska.h
        paraiska.cpp
        sistema.h
        sistema.cpp
        ukininkas.h
        ukininkas.cpp
        vertintojas.h
        vertintojas.cpp
)
target_link_libraries(cpp_oop_kursinis_v2 sfml-graphics sfml-window sfml-system)
