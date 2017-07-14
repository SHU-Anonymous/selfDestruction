//
// Created by 李欣 on 2017/7/12.
//

#include "executioner.h"

executioner::executioner() {
    memset(_targetLocation, 0, sizeof(_targetLocation));
    setTarget(const_cast<char *>("/Users/lixin/GitHub/selfDestruction/agonyTarget"));
}

void executioner::setTarget(char *targetLocation) {
    strcpy(_targetLocation, targetLocation);
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

void executioner::terminadeThread(char *targetLocation) {

}

void executioner::terminateFiles(char *targetLocation) {
    ifstream input(targetLocation);
    ofstream output(targetLocation);
    input.seekg(0, ios_base::end);
    streampos fileSize = input.tellg();
    char content[fileSize];
    memset(content, 0, fileSize);
    output.write(content, fileSize);
}

void executioner::executionTrigger() {
    /// DebugFlag!!! To be annotated
    cout << "\033[33;41m" << "========== START EXECUTION ==========" << "\033[0m" << endl;
    /// DebugFlag!!! To be annotated
    listFiles(_targetLocation);
    cout << "\033[33;41m" << "======== EXECUTION COMPLETED ========" << "\033[0m" << endl;
    exit(0);
}