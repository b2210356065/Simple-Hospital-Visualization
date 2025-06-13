//
// Created by Lenovo on 11.07.2024.
//

#ifndef DDD_SAVE_PATIENT_H
#define DDD_SAVE_PATIENT_H
#include "doctor_list.h"
#include "patient.h"
class save_patient {
private:
    doctor_list* doctorList;
    std::unordered_map<std::string , Patient*> patient_list;
    hazard_unit *hazardUnit= nullptr;
public:
    save_patient(doctor_list *doctorList1);
    ~save_patient();

    void save_to_system(const std::string name, const std::string complaint,const std::string doctor_name,const int age,
                        const std::string blood_group,
                        const std::string policlinic,const struct tm &date,int clock);

    Patient *return_patient(std::string name);

    void cancel_treatment(Patient *patient);

    void set_hazard(hazard_unit *hazardUnit1);

    void del_patient(doctors_process* doctorsProcess,Patient *patient, doctor *doc, pharmacy *pharmacy, const std::string treatment);
};


#endif //DDD_SAVE_PATIENT_H
