//
// Created by 1312 on 4/16/2023.
//

#ifndef SDIZO_WRITETOFILE_H
#define SDIZO_WRITETOFILE_H


class WriteToFile {
public:

    static void writeOperationToFileTXT(std::string fileName, std::string operationName);

    static void appendToFileTXT(std::string fileName, int time);
};


#endif //SDIZO_WRITETOFILE_H
