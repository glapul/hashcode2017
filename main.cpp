#include "info.h"
#include "output.h"
#include "sol_brute.h"

int32_t main() {
	readInput();
	Output o;
    for (int i = 0; i < nCaches; i++) {
        o.addVideoToCache(0, i);
    }
	o.printOutput();
}
