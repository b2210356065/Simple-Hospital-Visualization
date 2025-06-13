//
// Created by Lenovo on 10.07.2024.
//



#ifndef DDD_PATIENT_H
#define DDD_PATIENT_H

#include <string>

class Patient {
private:
    std::string doctor_name;
    std::string policlinic;
    std::string diagnosis;
    int patient_number;
    int time;
    struct tm date;
    struct information_of_patient {
        int age;
        std::string name;
        std::string blood_group;
        std::string complaint;
    };

    information_of_patient *info=new information_of_patient;
    std::string treatment = "none";
    int prescriptions_no;

public:
    Patient(const std::string &doctor, const std::string &policlinic, int age, const std::string &name,
            const std::string &blood_group, const std::string &complaint,const struct tm &dt, int time);
    ~Patient();
    std::string get_doctor() const;
    std::string get_policlinic() const;
    std::string get_diagnosis() const;
    int get_patient_number() const;
    information_of_patient* get_info_of_patient() const;
    std::string get_treatment() const;
    int get_prescriptions_no() const;
    void display() const;
    void set_diagnosis(const std::string &diagnose);

    void set_treatment(const std::string &treatment);

    void set_prescriptions_no(const int number);

    void set_patient_number(const int k);

    void set_number_of_day_for_lay(const int k);

    int get_time() const;

    tm get_date() const;
};

#endif // DDD_PATIENT_H
