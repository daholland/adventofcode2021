//
// Created by daholland on 12/5/21.
//

#include <fstream>
#include <iostream>
#include <vector>
#include "day6.h"

std::vector<int> day6::OpenDaySixInput() {
    std::vector<int> returnvec{};
    std::ifstream in("../inputdata/day6input.txt");

    if (!in) {
        std::cerr << "Cannot open file: " << "inputdata/day6input.txt" << std::endl;
    }

    std::string line;

    while (std::getline(in, line, ',')) {
        returnvec.push_back(stoi(line));

    }

    return returnvec;
}

bool LanternFish::ageOneDay() {
    if (daysuntilnewfish == 0) {
        daysuntilnewfish = 6;
        return true;
    }

    daysuntilnewfish -= 1;
    //if birth return true
    return false;
}

LanternFish::LanternFish(int days) {
    daysuntilnewfish = days;
}

int day6::partone() {
    auto input = OpenDaySixInput();
    std::vector<LanternFish> fishes;


    for (auto i: input) {
        fishes.emplace_back(LanternFish(i));
    }
    auto ageFishes = [&fishes]() {
        int newbirths = 0;

        for (auto &f: fishes) {
            auto isbirth = f.ageOneDay();
            if (isbirth) {
                newbirths += 1;
            }
        }

        while (newbirths > 0) {
            fishes.emplace_back(LanternFish(8));
            newbirths--;
        }
    };
    int numberoffishes = fishes.size();
    for (int i = 0; i < 80; i++) {
        ageFishes();
        std::cout << "Day " << i << std::endl;
        numberoffishes = fishes.size();
    }

    std::cout << "Number of fish: " << fishes.size() << std::endl;


    return 0;
}

int day6::parttwo() {
    auto input = OpenDaySixInput();
    std::vector<LanternFish> fishes;

    auto countAges = [&input](int n) {
        int count = 0;
        for (auto &i: input) {
            if (i == n) {
                count++;
            }
        }

        return count;
    };

    uint64_t zeros = countAges(0);
    uint64_t ones = countAges(1);
    uint64_t twos = countAges(2);
    uint64_t threes = countAges(3);
    uint64_t fours = countAges(4);
    uint64_t fives = countAges(5);
    uint64_t sixes = countAges(6);
    uint64_t sevens = countAges(7);
    uint64_t eights = countAges(8);

    std::cout << "0s: " << zeros << std::endl
              << "1s: " << ones << std::endl
              << "2s: " << twos << std::endl
              << "3s: " << threes << std::endl
              << "4s: " << fours << std::endl
              << "5s: " << fives << std::endl
              << "6s: " << sixes << std::endl
              << "7s: " << sevens << std::endl
              << "8s: " << eights << std::endl;

    uint64_t tobirth = 0;
    for (int i = 0; i < 256; i++) {
        tobirth = zeros;
        zeros = ones;
        ones = twos;
        twos = threes;
        threes = fours;
        fours = fives;
        fives = sixes;
        sixes = sevens;
        sevens = eights;

        sixes = sixes + tobirth;
        eights = tobirth;
    }

    std::cout << "total fish: " << zeros + ones + twos + threes + fours + fives + sixes + sevens + eights << std::endl;



//    for (auto i : input) {
//        fishes.emplace_back(LanternFish(i));
//    }
//    auto ageFishes = [&fishes]() {
//        int newbirths = 0;
//
//        for (auto& f: fishes) {
//            auto isbirth = f.ageOneDay();
//            if (isbirth) {
//                newbirths += 1;
//            }
//        }
//
//        while (newbirths > 0) {
//            fishes.emplace_back(LanternFish(8));
//            newbirths--;
//        }
//    };
//    int numberoffishes = fishes.size();
//    for (int i = 0; i < 256; i++) {
//        ageFishes();
//        std::cout << "Day " << i << std::endl;
//        numberoffishes = fishes.size();
//    }
//
//    std::cout << "Number of fish: " << fishes.size() << std::endl;


    return 0;
}
