#include "output.h"

Output::Output() {
    videosInCaches.resize(nCaches);
}

int getScore() {
    return 0;
}

bool Output::addVideoToCache(int videoId, int cacheId) {
    assert (videoId <= nVideos && videoId >= 0);
    assert (cacheId <= nCaches && cacheId >= 0);
    if (videosInCaches[cacheId].count(videoId)) {
        cerr << "Adding videi " << videoId << " to cache " << cacheId << " again\n";
        return true;
    }
	int usedCapacity = 0;
	for (auto i : videosInCaches[cacheId])
        usedCapacity += videoSizes[i];
    usedCapacity += videoSizes[videoId];
    if (usedCapacity <= nCacheCapacity) {
        videosInCaches[cacheId].insert(videoId);
        return true;
    }
    return false;

}

bool Output::removeVideoFromCache(int videoId, int cacheId) {
    assert (videoId <= nVideos && videoId >= 0);
    assert (cacheId <= nCaches && cacheId >= 0);
    if (!videosInCaches[cacheId].count(videoId)) {
        cerr << "Removing not present video " << videoId << " to cache " << cacheId << endl;
        return false;
    }
    videosInCaches[cacheId].erase(videoId);
    return true;
}

string Output::createOutput() {
    ostringstream buff;
    int n = 0;
    for (auto &i : videosInCaches)
        if (!i.empty())
            n++;
    buff << n << endl;
    for (int i = 0; i < videosInCaches.size(); i++) {
        if (videosInCaches[i].empty()) continue;
        buff << i << " ";
        for (auto j : videosInCaches[i])
            buff << j << " ";
        buff << endl;
    }
    return buff.str();
}

void Output::printOutput() {
	cout << this->createOutput();
}
