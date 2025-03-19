#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <stdlib.h>

char *readFileToBuffer(const char *filePath);

int writeBufferToFile(const char *buffer, size_t bufferSize);

#endif // FILE_UTILS_H
