//
// Created by Michal Lewandowski on 4/8/2023.
//

#ifndef SDIZO_TIME_H
#define SDIZO_TIME_H

#include <iostream>
#include <chrono>

class Time {
public:
    std::chrono::high_resolution_clock::time_point initialTime;
    std::chrono::high_resolution_clock::time_point endTime;

    void timeStart();

    void timeStop();

    long int elapsedTime() const;
};


#endif //SDIZO_TIME_H
