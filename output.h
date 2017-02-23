#ifndef OUTPUT_H
#define OUTPUT_H
#include "info.h"

bool addVideoToCache(int videoId, int cacheId);
bool removeVideoFromCache(int videoId, int cacheId);
void clearOutput();
string createOutput();
void printOutput();
#endif
