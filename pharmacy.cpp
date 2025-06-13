//
// Created by Lenovo on 13.07.2024.
//

#include "pharmacy.h"
pharmacy::pharmacy() {

}
void pharmacy::add_medicine(int number,std::string  medicine){
    medicines[number]=medicine;
}
void pharmacy::erase_medicine(int number){
    medicines.erase(number);
}
std::string pharmacy::return_prespections(int number){
    return medicines[number];
}

std::unordered_map<int , std::string> pharmacy::return_prespectionslist(){
    return medicines;
}