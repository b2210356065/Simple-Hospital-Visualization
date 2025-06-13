//
// Created by Lenovo on 11.07.2024.
//

#ifndef DDD_BEDS_H
#define DDD_BEDS_H
#include <unordered_map>
#include <string>
#include <queue>

class beds {
private:
    std::unordered_map<std::string,std::queue<int>> empty_beds;
    int number_of_bed=0;
public:
    beds(const std::unordered_map<std::string,int> bed_inputs);

    int get_number_of_beds() const;

    std::unordered_map<std::string, std::queue<int>> get_empty_beds() const;

    void pop_from_emptylist(const std::string key);

    void enqueue_for_emptylist(const int number, const std::string key);
};


#endif //DDD_BEDS_H
