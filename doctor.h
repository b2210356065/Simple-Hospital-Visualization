//
// Created by Lenovo on 10.07.2024.
//

#ifndef DDD_DOCTOR_H
#define DDD_DOCTOR_H

#include <string>
#include <unordered_map>
#include <vector>
#include "patient.h"
#include "doctors_process.h"
#include "hazard_unit.h"
class doctor {
private:
    hazard_unit *hazardUnit= nullptr;
    std::string doctor_name;
    std::string policlinic;
    struct timeline{
        struct tm date;
        int available=6;
        Patient *arr[6] = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
        timeline *next_day;
    };
    timeline *head= nullptr;
    timeline *rear= nullptr;
    std::unordered_map<int,Patient*> patientlist;
public:
    doctor(const std::string &doctorname,const std::string &policlinicname);
    ~doctor();
    void add_days(struct tm &date, int days);
    std::string get_doctor_name() const;
    std::string get_policlinic() const;
    timeline* get_timeline() const;
    bool is_equal(struct tm date1,struct tm date2);

    void next_day();

    void take_appointment(const int value, tm date,Patient *patient);

    void cancel_appointment(const int value, tm date);

    void add_patient(Patient *patient);

    void erase_patient(int number);

    void add_years(tm &date, int years);

    void add_months(tm &date, int months);

    void set_hazard(hazard_unit *hazardUnit1);
};


#endif //DDD_DOCTOR_H
