#include "info.h"
#include "output.h"
#include "sol_brute.h"

double scoreForVideoInCache(int videoId, int cacheId, Output &output) {
    int initScore = output.getScore();
    output.addVideoToCache(videoId, cacheId);
    
    int newScore = output.getScore();
    output.removeVideoFromCache(videoId, cacheId);
    
    int gain = newScore - initScore;
    return (double) gain / videoSizes[videoId];
}

bool insertBestVideoCachePair(Output &output) { // videoId, cacheId
    int bestVideo = -1, bestCache = -1;
    double bestScore = 1e-9;
    
    for (int videoId = 0; videoId < nVideos; videoId++) {
        for (int cacheId = 0; cacheId < nCaches; cacheId++) {
            double score = scoreForVideoInCache(videoId, cacheId, output);
            
            if (score > bestScore) {
                bestScore = score;
                bestVideo = videoId;
                bestCache = cacheId;
            }
        }
    }
    
    if (bestVideo != -1) {
        output.addVideoToCache(bestVideo, bestCache);
        return true;
    }
    
    return false;
}

void solveBrute(Output &output) {
    while (insertBestVideoCachePair(output)) {}
}
