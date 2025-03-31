cmake_minimum_required(VERSION 3.29)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        service.cpp
        service.h
        teste.cpp
        teste.h
        ui.cpp
        ui.h
        validatori.cpp
        validatori.h
        filerepo.cpp
        filerepo.h
        exceptii.cpp
        exceptii.h
        entitate.cpp
        entitate.h
        repo.cpp
        repo.h
)
