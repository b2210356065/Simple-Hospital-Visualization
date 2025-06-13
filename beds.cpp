//
// Created by Lenovo on 11.07.2024.
//

#include <iostream>
#include "beds.h"
beds::beds(const std::unordered_map<std::string, int> bed_inputs) {
    for (auto &pair:bed_inputs) {
        this->number_of_bed+=pair.second;
        std::queue<int> queue;
        for (int i = 0; i < pair.second; ++i) {
            queue.push(i);
        }
        this->empty_beds[pair.first]=queue;
    }
}
std::unordered_map<std::string ,std::queue<int>> beds::get_empty_beds() const{
    return empty_beds;
}
int beds::get_number_of_beds() const{
    return number_of_bed;
}
void beds::pop_from_emptylist(const std::string key){
    this->empty_beds[key].pop();
}
void beds::enqueue_for_emptylist(const int number,const std::string key){
    this->empty_beds[key].push(number);
}