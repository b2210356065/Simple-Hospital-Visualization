//
// Created by Lenovo on 15.07.2024.
//

#ifndef DDD_HAZARD_UNIT_H
#define DDD_HAZARD_UNIT_H
#include "patient.h"
#include "beds.h"
class hazard_unit {
public:
    hazard_unit();
    ~hazard_unit();

    bool error1(Patient *patient);

    bool error2(Patient *patient);

    bool error3(int number);

    void error4();

    bool error5(Patient *patient);

    bool error6(beds *beds1,std::string policlinic);

    bool control1(int number);
};


#endif //DDD_HAZARD_UNIT_H
