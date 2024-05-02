cmake_minimum_required(VERSION 3.27)
project(HospitalBinario)

set(CMAKE_CXX_STANDARD 17)

add_executable(HospitalBinario main.cpp
        medicament.cpp
        medicament.h
        medicamentfile.cpp
        medicamentfile.h
        medicamentmenu.cpp
        medicamentmenu.h
        tuple.h)
