//
// Created by Lenovo on 13.07.2024.
//

#ifndef DDD_PHARMACY_H
#define DDD_PHARMACY_H

#include <string>
#include "unordered_map"

class pharmacy {
private:
    std::unordered_map<int , std::string> medicines;
public:
    pharmacy();

    void add_medicine(int number, std::string name);

    void erase_medicine(int number);

    std::string return_prespections(int number);

    std::unordered_map<int, std::string> return_prespectionslist();
};


#endif //DDD_PHARMACY_H
