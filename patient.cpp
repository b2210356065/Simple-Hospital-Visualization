//
// Created by Lenovo on 10.07.2024.
//
#include "patient.h"
#include "Patient.h"
#include <iostream>

Patient::Patient(const std::string& doctor, const std::string& policlinic, int age, const std::string& name, const std::string& blood_group, const std::string& complaint
,const struct tm &dt,int time)
        : doctor_name(doctor),date(dt), policlinic(policlinic), diagnosis(""), patient_number(0), treatment("")
        , prescriptions_no(0),time(time) {
    info->age = age;
    info->name = name;
    info->blood_group = blood_group;
    info->complaint = complaint;
}
Patient::~Patient() {
    delete info;
}
std::string Patient::get_doctor() const {
    return doctor_name;
}
int Patient::get_time()const{
    return time;
}
struct tm Patient::get_date()const{
    return date;
}
std::string Patient::get_policlinic() const {
    return policlinic;
}

std::string Patient::get_diagnosis() const {
    return diagnosis;
}

int Patient::get_patient_number() const {
    return patient_number;
}

Patient::information_of_patient* Patient::get_info_of_patient() const {
    return info;
}

std::string Patient::get_treatment() const {
    return treatment;
}

int Patient::get_prescriptions_no() const {
    return prescriptions_no;
}

void Patient::set_diagnosis(const std::string& diagnose) {
    this->diagnosis = diagnose;
}
void Patient::set_treatment(const std::string& treatment) {
    this->treatment = treatment;
}
void Patient::set_prescriptions_no(const int number){
    this->prescriptions_no=number;
}
void Patient::set_patient_number(const int k){
    this->patient_number=k;
}

void Patient::display() const {
    std::cout << "Doctor: " << doctor_name << "\n"
              << "Policlinic: " << policlinic << "\n"
              << "Diagnosis: " << diagnosis << "\n"
              << "Patient Number: " << patient_number << "\n"
              << "Patient Info - Age: " << info->age << ", Name: " << info->name << ", Blood Group: " << info->blood_group << ", Complaint: " << info->complaint << "\n"
              << "Treatment: " << treatment << "\n"
              << "Prescriptions No: " << prescriptions_no << std::endl;
}
