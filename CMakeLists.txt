cmake_minimum_required(VERSION 3.26)
project(ddd)

set(CMAKE_CXX_STANDARD 23)

add_executable(ddd main.cpp
        patient.cpp
        patient.h
        doctor.cpp
        doctor.h
        beds.cpp
        beds.h
        doctors_process.cpp
        doctors_process.h
        save_patient.cpp
        save_patient.h
        doctor_list.cpp
        doctor_list.h
        readfiile.cpp
        readfiile.h
        pharmacy.cpp
        pharmacy.h
        hazard_unit.cpp
        hazard_unit.h
)
