#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <time.h>

using namespace std;


void terminateFiles(char *targetLocation) {
    struct stat info;
    stat(targetLocation, &info);
    long fileSize = info.st_size;
    cout << "File Size: " << fileSize << " Byte" << endl;
    char *fillContent;
    fillContent = (char *) malloc(static_cast<size_t>(fileSize));
    for (int fillCounter = 0; fillCounter < 7; ++fillCounter) {
        ofstream output(targetLocation);
        for (int contentPtr = 0; contentPtr < fileSize; ++contentPtr) {
            fillContent[contentPtr] = (char) rand();
        }
        output.write(fillContent, fileSize);
        output.close();
    }
}


int main() {
    char filePath[1000];
    memset(filePath, 0, 1000);
    strcpy(filePath, "/Users/lixin/Downloads/agonyTarget/agony.txt");
    clock_t start, finish;
    start = clock();
    terminateFiles(filePath);
    finish = clock();
    struct stat info;
    stat(filePath, &info);
    long fileSize = info.st_size;
    double fillingTime = (double) (finish - start) / CLOCKS_PER_SEC;
    cout << "Total time: " << fillingTime << " s" << endl
         << "Speed: " << (fileSize / fillingTime) / (1042 * 1024) << " MB/s" << endl;
    return 0;
}