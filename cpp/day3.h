//
// Created by daholland on 12/3/21.
//

#ifndef CPP_DAY3_H
#define CPP_DAY3_H


#include <vector>
#include <string>
#include <fstream>
#include <map>

class day3 {
public:
    std::vector<std::string> inputdata{};
    std::map<int, int> onesCount{};
    std::map<int, int> zerosCount{};

    void OpenDayThreeInput();
    int DayThreePartOne();
    int DayThreePartTwo();
};


#endif //CPP_DAY3_H
