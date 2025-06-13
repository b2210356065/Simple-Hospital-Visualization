//
// Created by Lenovo on 11.07.2024.
//

#ifndef DDD_DOCTOR_LIST_H
#define DDD_DOCTOR_LIST_H
#include <unordered_map>
#include <vector>
#include "doctor.h"
class doctor_list {
private:

    std::unordered_map<std::string ,std::unordered_map<std::string, doctor*>> doctorlist;
    hazard_unit *hazardUnit= nullptr;
public:
    doctor_list(const std::vector<doctor *> &vector1);

    ~doctor_list();

     std::unordered_map<std::string, std::unordered_map<std::string, doctor *>> &return_doclist();

    doctor *return_doctor(std::string policlinic, std::string name);

    void next_day();

    void set_hazard(hazard_unit *hazardUnit1);

};


#endif //DDD_DOCTOR_LIST_H
