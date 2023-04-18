//
// Created by Michal Lewandowski on 4/8/2023.
//

#include "Time.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

// function timeStart() - sets the initialTime variable to the current time.
void Time::timeStart() {
    initialTime = high_resolution_clock::now();
}
// function timeStop() - sets the value of the endTime variable to the current time.
void Time::timeStop() {
    endTime = high_resolution_clock::now();
}
// function elapsedTime() - returns the time in nanoseconds between initialTime and endTime.
long Time::elapsedTime() const {

    return duration_cast<nanoseconds>(endTime - initialTime).count();

}