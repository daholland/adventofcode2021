//
// Created by daholland on 12/3/21.
//

#include <iostream>
#include "day3.h"

int day3::DayThreePartOne() {

    OpenDayThreeInput();
    int foobar = inputdata.size();
    for (auto i = 0; i < 12; i++) {
        onesCount.insert({i, 0});
        zerosCount.insert({i, 0});
    }


    for (auto s: inputdata) {
        for (auto i = 0; i < 12; i++) {
            if (s[i] == '1') {
                onesCount[i] = onesCount[i] + 1;
            } else {
                zerosCount[i] = zerosCount[i] + 1;
            }
        }
    }

    auto buildGamma = [&]() {
        int gamma = 0;
        for (auto i = 0; i < 12; i++) {
            if (onesCount[i] > zerosCount[i]) {
                gamma |= 1 << (11-i);
            }
        }

        return gamma;
    };

    int gamma = buildGamma();
    int epsilon = gamma ^ 0b111111111111;

    std::cout << gamma << " g|e " << epsilon << std::endl;
    std::cout << " g*e : " << gamma * epsilon << std::endl;

    return 0;
}

int day3::DayThreePartTwo() {
    OpenDayThreeInput();
    int foobar = inputdata.size();
    for (auto i = 0; i < 12; i++) {
        onesCount.insert({i,0});
        zerosCount.insert({i,0});
    }

    auto countOnes = [this](std::vector<std::string>& coll, int n) {
        auto sum = 0;

        for (auto s: inputdata) {
            if (s[n] == '1') {
                sum += 1;
            }
        }

        return sum;
    };

    auto filterO2FromIndex = [this, countOnes](std::vector<std::string>& coll, int n) {
        auto onesCount = countOnes(coll, n);
        auto zeroCount = coll.size() - onesCount;

        char bitcritera = (onesCount >= zeroCount) ? '1' : '0';

        std::vector<std::string> newcoll {};

        for (auto s : inputdata) {
            if (s[n] == bitcritera) {
                newcoll.push_back(s);
            }
        }

        return newcoll;
    };

    int oxygengenerator = 0;

    for (int i = 0; i < 12; i++) {
        int inputdatasize = inputdata.size();
        auto filtered = filterO2FromIndex(inputdata, i);
        inputdata = filtered;
        if (inputdata.size() == 1) {
            oxygengenerator = (inputdata[0][0] - '0') << 11
                             | (inputdata[0][1] - '0') << 10
                             | (inputdata[0][2] - '0') << 9
                             | (inputdata[0][3] - '0') << 8
                             | (inputdata[0][4] - '0') << 7
                             | (inputdata[0][5] - '0') << 6
                             | (inputdata[0][6] - '0') << 5
                             | (inputdata[0][7] - '0') << 4
                             | (inputdata[0][8] - '0') << 3
                             | (inputdata[0][9] - '0') << 2
                             | (inputdata[0][10] - '0') << 1
                             | (inputdata[0][11] - '0') << 0;
            break;
        }
    }

    std::cout << "oxygengenerator: " << oxygengenerator << std::endl;

    OpenDayThreeInput();
    auto filterCO2FromIndex = [this, countOnes](std::vector<std::string>& coll, int n) {
        auto onesCount = countOnes(coll, n);
        auto zeroCount = coll.size() - onesCount;

        char bitcritera = (zeroCount <= onesCount) ? '0' : '1';

        std::vector<std::string> newcoll {};

        for (auto s : inputdata) {
            if (s[n] == bitcritera) {
                newcoll.push_back(s);
            }
        }

        return newcoll;
    };
    int co2scrubber = 0;

    for (int i = 0; i < 12; i++) {
        int inputdatasize = inputdata.size();
        inputdata = filterCO2FromIndex(inputdata, i);

        if (inputdata.size() == 1) {
            co2scrubber = (inputdata[0][0] - '0') << 11
                          | (inputdata[0][1] - '0') << 10
                          | (inputdata[0][2] - '0') << 9
                          | (inputdata[0][3] - '0') << 8
                          | (inputdata[0][4] - '0') << 7
                          | (inputdata[0][5] - '0') << 6
                          | (inputdata[0][6] - '0') << 5
                          | (inputdata[0][7] - '0') << 4
                          | (inputdata[0][8] - '0') << 3
                          | (inputdata[0][9] - '0') << 2
                          | (inputdata[0][10] - '0') << 1
                          | (inputdata[0][11] - '0') << 0;
            break;
        }
    }

    std::cout << "co2scrubber: " << co2scrubber << std::endl;
    std::cout << "o2 * co2: " << oxygengenerator * co2scrubber << std::endl;

    return 0;
}

void day3::OpenDayThreeInput() {
    std::ifstream in("../inputdata/daythreeinput.txt");

    if (!in) {
        std::cerr << "Cannot open file: " << "inputdata/daythreeinput.txt" << std::endl;
    }

    std::string line;
    inputdata.clear();
    while (std::getline(in, line)) {
        inputdata.push_back(line);

    }
}
