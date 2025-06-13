//
// Created by Lenovo on 11.07.2024.
//

#ifndef DOCTORS_PROCESS_H
#define DOCTORS_PROCESS_H

#include <string>
#include "Patient.h"
#include "beds.h"
#include "pharmacy.h"
#include "hazard_unit.h"
class doctor;

class doctors_process {
private:
    beds *beds1;
    hazard_unit*hazardUnit= nullptr;
public:
    doctors_process(beds *beds);
    ~doctors_process();

    void lay_the_patient_down(Patient *patient, doctor *doctor);
    void set_diagnosis(const std::string diagnose, Patient *patient, doctor *doctor);
    void discharge(Patient *patient, doctor *doctor);
    void set_treatment(const std::string &treatment, Patient *patient, pharmacy *pharmacy, doctor *doc);

    void set_hazard(hazard_unit *hazardUnit1);
};

#endif // DOCTORS_PROCESS_H