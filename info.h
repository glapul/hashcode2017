#ifndef INFO_H
#define INFO_H
#include<bits/stdc++.h>
#define int int64_t
using namespace std;
int nVideos;
int nEndpoints;
int nRequestsDescriptions;
int nCaches;
int nCacheCapacity;

vector<int> videoSizes;

struct Endpoint {
	int latencyToBase;
	vector<pair<int,int>> cachesConnectedToThisEndpoint; // id, latency
};

vector<Endpoint> endpoints;
struct RequestDescription {
	int videoId;
	int endpointId;
	int numberOfRequests;
};

vector<RequestDescription> requestDescriptions;
#endif
