#include <iostream>

using namespace std;
#include "readfiile.h"
#include "save_patient.h"
#include "doctor_list.h"
#include "doctors_process.h"
#include "pharmacy.h"


int main() {
    readfiile *readfiil=new readfiile();
    readfiil->read_beds("C:\\Users\\Lenovo\\Desktop\\ddd\\departmants.txt");//my computer referance
    readfiil->read_doctors("C:\\Users\\Lenovo\\Desktop\\ddd\\doctors.txt");//my computer referance
    readfiil->read_flow("C:\\Users\\Lenovo\\Desktop\\ddd\\flow.txt");//my computer referance

    delete readfiil;
    return 0;
}