//
// Created by Lenovo on 15.07.2024.
//

#include <iostream>
#include "hazard_unit.h"
hazard_unit::hazard_unit() {
}
hazard_unit::~hazard_unit() {}
bool hazard_unit::error1(Patient *patient){
    if(patient == nullptr){
        std::cout<<"Error: Patient can't found"<<std::endl;
        return true;
    }
    return false;
}
bool hazard_unit::error2(Patient *patient){
    if(patient!= nullptr){
        std::cout<<"Error: Date is full"<<std::endl;
        return true;
    }
    return false;
}
bool hazard_unit::error3(int number){
    if(number!=0){
        std::cout<<"Error: Patient already complete appointment"<<std::endl;
        return true;
    }
    return false;
}
void hazard_unit::error4(){
    std::cout<<"Error: Date can't found"<<std::endl;
}
bool hazard_unit::error5(Patient *patient){
    if(patient->get_diagnosis()==""){
        std::cout<<"Error: Before set treatment you must set diagnosis"<<std::endl;
        return true;
    }
    return false;
}
bool hazard_unit::error6(beds *beds1,std::string policlinic){
    if(beds1->get_empty_beds()[policlinic].empty()){
        std::cout<<"Error: There isn't empty bed in "+policlinic<<std::endl;
        return true;
    }
    return false;
}

bool hazard_unit::control1(int number){
    if(number!=0){
        return true;
    }
    return false;
}