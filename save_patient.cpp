//
// Created by Lenovo on 11.07.2024.
//

#include <iostream>
#include "save_patient.h"
#include "doctor.h"
#include "patient.h"
save_patient::save_patient(doctor_list *doctorList1):doctorList(doctorList1) {

}
save_patient::~save_patient() {
    for (auto &pair:patient_list) {
        if(pair.second!= nullptr)delete pair.second;
    }
    delete doctorList;
}
void save_patient::save_to_system(const std::string name, const std:: string complaint,const std::string doctor_name, int age,
                                  const std::string blood_group,const std::string policlinic,const struct tm &date,int clock){
    if(patient_list[name]!= nullptr){
        std::cout<<"Error: Patient saved already"<<std::endl;
        return;
    }
    Patient *pat=new Patient(doctor_name,policlinic,age,name,blood_group,complaint,date,clock);
    doctor *doc= doctorList->return_doclist()[policlinic][doctor_name];
    doc->take_appointment(clock,date,pat);
    patient_list[name]=pat;
}
void save_patient::cancel_treatment(Patient *patient){
    if(hazardUnit->error1(patient))return;
    if(hazardUnit->error3(patient->get_patient_number()))return;
    doctor *doc=doctorList->return_doctor(patient->get_policlinic(),patient->get_doctor());
    doc->cancel_appointment(patient->get_time(),patient->get_date());
    patient_list.erase(patient->get_info_of_patient()->name);
    delete patient;
}
Patient* save_patient::return_patient(std::string name){
    return patient_list[name];
}
void save_patient::set_hazard(hazard_unit *hazardUnit1){
    hazardUnit=hazardUnit1;
    doctorList->set_hazard(hazardUnit1);
}
void save_patient::del_patient(doctors_process* doctorsProcess,Patient* patient,doctor *doc,pharmacy *pharmacy,const std::string treatment){
    if(hazardUnit->error5(patient))return;
    doctorsProcess->set_treatment(treatment,patient,pharmacy,doc);
    patient_list.erase(patient->get_info_of_patient()->name);
    delete patient;
}