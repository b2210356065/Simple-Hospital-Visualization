//
// Created by Lenovo on 12.07.2024.
//

#ifndef DDD_READFIILE_H
#define DDD_READFIILE_H

#include "doctor.h"
#include "beds.h"
#include "doctor_list.h"
#include "doctors_process.h"
#include "save_patient.h"
#include "pharmacy.h"
#include "hazard_unit.h"
class readfiile {
private:
    std::vector<doctor*>doc_l;
    doctor_list *doctorList= nullptr;
    doctors_process *doctorsProcess= nullptr;
    beds *bed= nullptr;
    save_patient *savePatient= nullptr;
    pharmacy *phar= nullptr;
    hazard_unit *hazardUnit=new hazard_unit();
public:
    readfiile();
    ~readfiile();

    void read_doctors(const std::string &filename);

    void read_beds(const std::string &filename);

    doctor_list *return_doclist();

    doctors_process *return_docprocess();

    beds *return_beds();

    save_patient *return_patients();

    void read_flow(const std::string &filename);

    tm split_date(std::string &date);
};


#endif //DDD_READFIILE_H
