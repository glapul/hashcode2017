#ifndef OUTPUT_H
#define OUTPUT_H
#include "info.h"

struct Output {
    Output();
    vector<unordered_set<int>> videosInCaches;
    vector<int> capacitiesTaken;
    int getScore();
    bool addVideoToCache(int videoId, int cacheId);
    bool removeVideoFromCache(int videoId, int cacheId);
    string createOutput();
    void printOutput();
};
#endif
