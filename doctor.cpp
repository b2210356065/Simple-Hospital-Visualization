//
// Created by Lenovo on 10.07.2024.
//

#include "doctor.h"
#include "patient.h"
#include <random>
#include <unordered_map>
#include <iostream>


doctor::doctor(const std::string &doctorname, const std::string &policlinicname):doctor_name(doctorname)
 ,policlinic(policlinicname) {
    struct tm date = {0, 0, 0, 1, 1, 2024-1900};
    head=new timeline;
    rear=head;
    for (int i = 0; i < 365; ++i) {
        add_days(date,1);
        rear->next_day=new timeline;
        rear=rear->next_day;
        rear->date=date;
        rear->next_day= nullptr;
    }
};
doctor::~doctor(){
    while (head!= nullptr) {
        rear=head;
        head=head->next_day;
        delete rear;
    }
}
void doctor::set_hazard(hazard_unit *hazardUnit1){
    hazardUnit=hazardUnit1;
}
std::string doctor::get_doctor_name()const {
    return doctor_name;
}
std::string doctor::get_policlinic()const{
    return policlinic;
}
doctor::timeline* doctor::get_timeline() const {
    return head;
}
void doctor::add_patient(Patient *patient) {
    this->patientlist[patient->get_patient_number()]=patient;
}
void doctor::erase_patient(int number){
    this->patientlist.erase(number);
}

void doctor::next_day(){
    timeline *temp=head;
    head=head->next_day;
    delete temp;

    struct tm date=rear->date;
    add_days(date,1);
    rear->next_day=new timeline;
    rear=rear->next_day;
    rear->date=date;
    rear->next_day= nullptr;
}

void doctor::take_appointment(const int value,struct tm date,Patient *patient){
    timeline *temp=head;
    while (temp != nullptr) {
        if (is_equal(temp->date,date)) {
            if(hazardUnit->error2(temp->arr[value]))return;
            temp->arr[value]= patient;
            temp->available--;
            return;
        }
        temp = temp->next_day;
    }
    hazardUnit->error4();
}
void doctor::cancel_appointment(const int value,struct tm date){
    timeline *temp=head;
    while (temp != nullptr) {
        if (is_equal(temp->date,date)) {
            temp->arr[value]= nullptr;
            temp->available++;
            return;
        }
        temp = temp->next_day;
    }
    hazardUnit->error4();
}
void doctor::add_days(struct tm &date, int days) {
    date.tm_mday += days;
    mktime(&date);

    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((date.tm_year + 1900) % 4 == 0 && ((date.tm_year + 1900) % 100 != 0 || (date.tm_year + 1900) % 400 == 0)) {
        days_in_month[1] = 29;
    }

    while (date.tm_mday > days_in_month[date.tm_mon]) {
        date.tm_mday -= days_in_month[date.tm_mon];
        add_months(date, 1);
    }
    if(date.tm_mon>12){
        add_years(date,1);
        date.tm_mon=1;
    }
    mktime(&date);
}

void doctor::add_months(struct tm &date, int months) {
    date.tm_mon += months;
    mktime(&date);
}

void doctor::add_years(struct tm &date, int years) {
    date.tm_year += years;
    mktime(&date);
}
bool doctor::is_equal(struct tm date1,struct tm date2){
    return (date1.tm_year==date2.tm_year&&date1.tm_mon==date2.tm_mon&&date1.tm_mday==date2.tm_mday);
}