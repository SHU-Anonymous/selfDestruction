//
// Created by 李欣 on 2017/7/12.
//

#include "executioner.h"

executioner::executioner() {
    memset(_targetLocation, 0, sizeof(_targetLocation));
    setTarget(const_cast<char *>("/Users/lixin/Downloads/agonyTarget"));
    setFillTimes(7);
}

void executioner::setTarget(char *targetLocation) {
    strcpy(_targetLocation, targetLocation);
}

void executioner::setFillTimes(int fillTimes) {
    _fillTimes = fillTimes;
}

void executioner::listFiles(char *targetLocation) {
    DIR *directory;
    struct dirent *dirPointer;
    char subTargetLocation[1000];
    if ((directory = opendir(targetLocation)) == nullptr) {
        perror("Open DIR Error");
        exit(4);
        // 4 stands for Open DIR Error
    }
    while ((dirPointer = readdir(directory)) != nullptr) {
        memset(subTargetLocation, 0, sizeof(subTargetLocation));
        strcpy(subTargetLocation, targetLocation);
        strcat(subTargetLocation, "/");
        strcat(subTargetLocation, dirPointer->d_name);
        if (strcmp(dirPointer->d_name, ".") == 0 || strcmp(dirPointer->d_name, "..") == 0) {
            // Current dir OR Parent dir
            continue;
        }
        switch (dirPointer->d_type) {
            case 4:
                // d_type -- directory
                listFiles(subTargetLocation);
                break;
            case 8:
                // d_type -- file
                try {
                    terminadeThread(dirPointer->d_name);
                }
                catch (...) {
                    //
                }
                terminateFiles(subTargetLocation);
                break;
            case 10:
                // d_type -- linkFile
                terminateFiles(subTargetLocation);
                break;
            default:
                break;
        }
    }
    closedir(directory);
}

void executioner::terminadeThread(char *targetThreadName) {
    char instruction[1000];
    memset(instruction, 0, 1000);
    strcpy(instruction, "killall");
    strcat(instruction, targetThreadName);
    system(instruction);
}

void executioner::terminateFiles(char *targetLocation) {
    struct stat info;
    stat(targetLocation, &info);
    long fileSize = info.st_size;
    char *fillContent;
    fillContent = (char *) malloc(static_cast<size_t>(fileSize));
    for (int fillCounter = 0; fillCounter < _fillTimes; ++fillCounter) {
        ofstream output(targetLocation);
        for (int contentPtr = 0; contentPtr < fileSize; ++contentPtr) {
            fillContent[contentPtr] = (char) rand();
        }
        output.write(fillContent, fileSize);
        output.close();
    }
}

void executioner::executionTrigger() {
    /// DebugFlag!!! To be annotated
    cout << "\033[33;41m" << "========== START EXECUTION ==========" << "\033[0m" << endl;
    /// DebugFlag!!! To be annotated
    listFiles(_targetLocation);
    /// DebugFlag!!! To be annotated
    cout << "\033[33;41m" << "======== EXECUTION COMPLETED ========" << "\033[0m" << endl;
    /// DebugFlag!!! To be annotated
    char instruction[1000];
    memset(instruction, 0, 1000);
    strcpy(instruction, "rm -r");
    strcat(instruction, _targetLocation);
    system(instruction);
    exit(0);
}