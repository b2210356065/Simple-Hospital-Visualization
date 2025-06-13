//
// Created by Lenovo on 11.07.2024.
//

#include <iostream>
#include "doctors_process.h"
#include "pharmacy.h"
#include "doctor.h"
doctors_process::doctors_process(beds *beds) : beds1(beds){
}
doctors_process::~doctors_process() {
}

void doctors_process::set_hazard(hazard_unit *hazardUnit1){
    hazardUnit=hazardUnit1;
}
void doctors_process::set_treatment(const std::string& treatment, Patient* patient,pharmacy *pharmacy,doctor *doc) {
    if(hazardUnit->control1(patient->get_patient_number()))discharge(patient,doc);
    patient->set_treatment(treatment);
    int k=0;
    k+=patient->get_patient_number()*100000000;
    k+=doc->get_timeline()->date.tm_mday*1000000;
    k+=doc->get_timeline()->date.tm_mon*10000;
    k+=doc->get_timeline()->date.tm_year;
    patient->set_prescriptions_no(k);
    pharmacy->add_medicine(patient->get_prescriptions_no(),patient->get_treatment());
}
void doctors_process::set_diagnosis(const std::string diagnose, Patient *patient,doctor *doctor){
    patient->set_diagnosis(diagnose);
}
void doctors_process::lay_the_patient_down(Patient *patient,doctor *doctor){
    std::string policlinic=patient->get_policlinic();
    if(hazardUnit->error6(beds1,policlinic))return;
    int i=0;
    for (auto &pair: beds1->get_empty_beds()) {
        i++;
        if(pair.first==patient->get_policlinic()){
            break;
        }
    }
    if(hazardUnit->control1(patient->get_patient_number()))return;
    int patient_no=beds1->get_empty_beds()[policlinic].front()+i*1000;
    patient->set_patient_number(patient_no);
    beds1->pop_from_emptylist(policlinic);
    doctor->add_patient(patient);

}

void doctors_process::discharge(Patient *patient,doctor *doctor){
    std::string  policlinic=patient->get_policlinic();
    beds1->enqueue_for_emptylist(patient->get_patient_number()%1000,patient->get_policlinic());
    doctor->erase_patient(patient->get_patient_number());
}
