#include "info.h"
int nVideos;
int nEndpoints;
int nRequestsDescriptions;
int nCaches;
int nCacheCapacity;
vector<int> videoSizes;
vector<Endpoint> endpoints;
vector<RequestDescription> requestDescriptions;

void readInput() {
    cin >> nVideos >> nEndpoints >> nRequestsDescriptions >> nCaches >> nCacheCapacity;
    videoSizes.resize(nVideos);
    for (int i = 0; i < nVideos; i++) {
        cin >>  videoSizes[i];
    }
    endpoints.resize(nEndpoints);
    for (int  i = 0 ; i < nEndpoints; i++) {
        cin  >> endpoints[i].latencyToBase;
        int k;
        cin >> k;
        
        endpoints[i].cachesConnectedToThisEndpoint.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> endpoints[i].cachesConnectedToThisEndpoint[j].cacheId;
            cin >> endpoints[i].cachesConnectedToThisEndpoint[j].cacheLatency;
        }
    }
}
