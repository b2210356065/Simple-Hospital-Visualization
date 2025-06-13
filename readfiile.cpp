//
// Created by Lenovo on 12.07.2024.
//

#include <iostream>
#include <fstream>
#include "readfiile.h"
#include "beds.h"
#include "doctor_list.h"
#include "doctors_process.h"
#include "save_patient.h"
#include "hazard_unit.h"

readfiile::readfiile() {
}
readfiile::~readfiile() {
    if(doctorsProcess!= nullptr)delete doctorsProcess;
    if(bed!= nullptr)delete bed;
    if(hazardUnit!= nullptr)delete hazardUnit;
    if(savePatient!= nullptr)delete savePatient;
    if(phar!= nullptr)delete phar;
}
void readfiile::read_doctors(const std::string &filename){
    std::ifstream file(filename);
    std::vector<doctor*>doc_l;

    if (!file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string split2="";
        std::string split1="";
        for (int i = 0; i < line.length(); ++i) {
            if(line[i]==':'){
                split1=split2;
                split2="";
                continue;
            }
            split2+=line[i];
        }
        doc_l.push_back(new doctor(split2, split1));
    }
    doctorList=new doctor_list(doc_l);
    savePatient=new save_patient(doctorList);
    savePatient->set_hazard(hazardUnit);
    doctorsProcess->set_hazard(hazardUnit);
    file.close();
}
doctor_list* readfiile::return_doclist(){
    return doctorList;
}
doctors_process* readfiile::return_docprocess(){
    return doctorsProcess;
}
beds* readfiile::return_beds() {
    return bed;
}
void readfiile::read_beds(const std::string  &filename){
    phar=new pharmacy();
    std::ifstream file(filename);
    std::unordered_map<std::string,int> b_list;
    if (!file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string split2="";
        std::string split1="";
        for (int i = 0; i < line.length(); ++i) {
            if(line[i]==':'){
                split1=split2;
                split2="";
                continue;
            }
            split2+=line[i];
        }
        b_list[split1]=std::stoi(split2);
    }
    this->bed=new beds(b_list);
    this->doctorsProcess=new doctors_process(bed);
    file.close();
}
void readfiile::read_flow(const std::string  &filename){
    std::ifstream file(filename);
    std::unordered_map<std::string,int> b_list;
    if (!file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> words;
        std::string word="";
        for (int i = 0; i < line.length(); ++i) {
            if(line[i]==' '){
                words.push_back(word);
                word="";
                continue;
            }
            word+=line[i];
            if(i==line.length()-1){
                words.push_back(word);
                word="";
                continue;
            }
        }
        if(line.starts_with("takeappointment")){
            savePatient->save_to_system(words[1],words[2],words[3],std::stoi(words[4])
                                        ,words[5],words[6], split_date(words[7]),std::stoi(words[8]));
        }else if(line.starts_with("cancelappointment")){
            Patient* pat=savePatient->return_patient(words[1]);
            savePatient->cancel_treatment(pat);
        }else if(line.starts_with("nextday")){
            doctorList->next_day();
        }else if (line.starts_with("setdiagnose")){
            Patient* pat=savePatient->return_patient(words[2]);
            if(hazardUnit->error1(pat))continue;
            doctorsProcess->set_diagnosis(words[1],pat
                                          ,doctorList->return_doctor(pat->get_policlinic(),pat->get_doctor()));
        }else if(line.starts_with("settraitment")){
            Patient* pat=savePatient->return_patient(words[2]);
            if(hazardUnit->error1(pat))continue;
            savePatient->del_patient(doctorsProcess,pat,doctorList->return_doctor(pat->get_policlinic(),pat->get_doctor()),phar,words[1]);
        }else if(line.starts_with("laydown")){
            Patient* pat=savePatient->return_patient(words[1]);
            doctorsProcess->lay_the_patient_down(pat,doctorList->return_doctor(pat->get_policlinic(),pat->get_doctor()));
        }
    }
}
struct tm readfiile::split_date(std::string &date){
    std::vector<std::string> d_m_y;
    std::string c="";
    for (int i = 0; i < date.length(); ++i) {
        if (date[i]==':'){
            d_m_y.push_back(c);
            c="";
            continue;
        }
        c+=date[i];
    }
    struct tm d={0,0,0,std::stoi(d_m_y[0]),std::stoi(d_m_y[1]),std::stoi(d_m_y[2])-1900};
    return d;
}