#include "glapa.h"

namespace Glapa {
Output solve() {
    Output o;
    for (auto r : requestDescriptions) {
        for (auto cache : endpoints[r.endpointId].cachesConnectedToThisEndpoint) {
        if (o.addVideoToCache(r.videoId, cache.cacheId))
            break;
        }
    }
    return o;
}

const double D = 3;

double multiplier(int cacheId, Output & o) {
    double rt = (double)o.capacitiesTaken[cacheId]/(double)nCacheCapacity;
    return pow((1.0 / (1 + 1e-8 - rt)),3);
}

double calculateGain(int endpointId, Output& o) {
    double gain = 0;
    int lb = endpoints[endpointId].latencyToBase;
    for (auto cache : endpoints[endpointId].cachesConnectedToThisEndpoint) {
        gain = max(gain, lb - cache.cacheLatency * multiplier(cache.cacheId, o));
    }
    return gain;
}
bool eq(double a, double b) {
    return abs(a-b) < 1;
}

double calculateScore(int requestId, Output& o) {
    int vid = requestDescriptions[requestId].videoId;
    return requestDescriptions[requestId].numberOfRequests * calculateGain(requestDescriptions[requestId].endpointId, o)/(double)videoSizes[vid];
}

Output solve2() {
    Output o;
    priority_queue<pair<double, int>> q;
    for (int i = 0; i < nRequestsDescriptions; i++) {
        q.emplace(calculateScore(i, o), i);
    }
    while (!q.empty()) {
        double sc; int rid;
        tie(sc, rid) = q.top();
        q.pop();
        double nsc = calculateScore(rid, o);
        if (!eq(sc, nsc)) {
            q.emplace(nsc, rid);
            continue;
        }
        auto & r = requestDescriptions[rid];
        bool present = false;
        for (auto cache : endpoints[r.endpointId].cachesConnectedToThisEndpoint)
            if (o.videosInCaches[cache.cacheId].count(r.videoId))
                present = true;
        if (!present) {
            auto& caches = endpoints[r.endpointId].cachesConnectedToThisEndpoint;
            sort(caches.begin(), caches.end(), [&] (const pair<int,int>&a, const pair<int,int>& b){return a.cacheLatency*multiplier(a.cacheId,o) < b.cacheLatency*multiplier(b.cacheId, o);});
            for (auto cache : caches) {
            if (o.addVideoToCache(r.videoId, cache.cacheId))
                break;
            }
        }
    }
    cerr << o.getScore() << endl;
    return o;
}
}

