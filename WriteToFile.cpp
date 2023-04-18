//
// Created by 1312 on 4/16/2023.
//

#include <string>
#include <fstream>
#include "WriteToFile.h"

void WriteToFile::writeOperationToFileTXT(std::string fileName, std::string operationName) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::app);
    if (myFile.is_open()) {
        myFile << "\n" << operationName << " :\n";
    }
    myFile.close();
}

void WriteToFile::appendToFileTXT(std::string fileName, int time) {
    std::fstream myFile;
    myFile.open(fileName, std::ios::app); {
        if (myFile.is_open()) {
            myFile <<" " << time;
        }
        myFile.close();
    }
}