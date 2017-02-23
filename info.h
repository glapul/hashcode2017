#ifndef INFO_H
#define INFO_H
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
extern int nVideos;
extern int nEndpoints;
extern int nRequestsDescriptions;
extern int nCaches;
extern int nCacheCapacity;

extern vector<int> videoSizes;

struct Endpoint {
	int latencyToBase;
	vector<pair<int,int>> cachesConnectedToThisEndpoint; // id, latency
};
#define cacheId first
#define cacheLatency second

extern vector<Endpoint> endpoints;
struct RequestDescription {
	int videoId;
	int endpointId;
	int numberOfRequests;
};

extern vector<RequestDescription> requestDescriptions;

void readInput();
#endif
