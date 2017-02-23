#include "info.h"
#include "output.h"

struct item {
	int video, endpoint, cache, latency, amount;

	double calculateCost() const {
		return (endpoints[endpoint].latencyToBase - latency) * amount / (double)videoSizes[video];
	}
};

bool cmp(const item& a, const item& b) {
	return a.calculateCost() > b.calculateCost();
}

int32_t main() {
	readInput();
	Output o;
	vector<item> a;

	int all = (int)requestDescriptions.size();
	int now = 0;

	for (auto& desc : requestDescriptions) {
		
		++now;

		cerr << now << " / " << all << endl;

		int cnt = 0;
		for (auto& cache : endpoints[desc.endpointId].cachesConnectedToThisEndpoint) {

			++cnt;

            if (cnt >= 100) break;

			//cerr << desc.endpointId << " " << cache.cacheId << endl;
			a.push_back({desc.videoId, desc.endpointId, cache.cacheId, cache.cacheLatency, desc.numberOfRequests});
		}
	}

	cerr << "before soring" << endl;

	sort(a.begin(), a.end(), cmp);

	cerr << "after sorting" << endl;

	for (auto& i : a) {
		o.addVideoToCache(i.video, i.cache);
	}

	cerr << "after add" << endl;

	o.printOutput();
}

