//
// Created by Lenovo on 11.07.2024.
//

#include "doctor_list.h"
doctor_list::doctor_list( const std::vector<doctor*>& doctorList){
    for (auto & doc: doctorList) {
        doctorlist[doc->get_policlinic()][doc->get_doctor_name()]=doc;
    }
}


doctor_list::~doctor_list() {
    for (auto& policlinic_pair : doctorlist) {
        for (auto& doctor_pair : policlinic_pair.second) {
            delete doctor_pair.second;
        }
    }
}
void doctor_list::set_hazard(hazard_unit *hazardUnit1){
    hazardUnit=hazardUnit1;
    for (auto& policlinic_pair : doctorlist) {
        for (auto& doctor_pair : policlinic_pair.second) {
            doctor_pair.second->set_hazard(hazardUnit);
        }
    }
}
std::unordered_map<std::string, std::unordered_map<std::string, doctor*>>& doctor_list::return_doclist() {
    return doctorlist;
}
doctor* doctor_list::return_doctor(std::string policlinic,std::string name){
    return doctorlist[policlinic][name];
}
void doctor_list::next_day(){
    for (auto& policlinic_pair : doctorlist) {
        for (auto& doctor_pair : policlinic_pair.second) {
            doctor_pair.second->next_day();
        }
    }
}

