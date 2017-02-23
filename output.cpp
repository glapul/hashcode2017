#include "output.h"
#include "info.h"
Output::Output() {
    videosInCaches.resize(nCaches);
    capacitiesTaken.resize(nCaches);
}

int Output::getScore() {
  int total = 0;
  int req_cnt = 0;
  for(const auto& rd : requestDescriptions) {
    int latency = endpoints[rd.endpointId].latencyToBase;
    for(auto cache : endpoints[rd.endpointId].cachesConnectedToThisEndpoint){
      if(videosInCaches[cache.cacheId].count(rd.videoId))
        latency = min(latency, cache.cacheLatency);
    }
    total += rd.numberOfRequests * (endpoints[rd.endpointId].latencyToBase - latency);
    req_cnt += rd.numberOfRequests;
  }
  return 1000 * total / req_cnt;
}

bool Output::addVideoToCache(int videoId, int cacheId) {
    assert (videoId <= nVideos && videoId >= 0);
    assert (cacheId <= nCaches && cacheId >= 0);
    if (videosInCaches[cacheId].count(videoId)) {
        cerr << "Adding videi " << videoId << " to cache " << cacheId << " again\n";
        return true;
    }
    if (capacitiesTaken[cacheId] + videoSizes[videoId] <= nCacheCapacity) {
        capacitiesTaken[cacheId] += videoSizes[videoId];
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
    capacitiesTaken[cacheId] -= videoSizes[videoId];
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
