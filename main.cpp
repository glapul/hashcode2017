#include "info.h"
#include "output.h"
#include "sol_brute.h"

int32_t main() {
	readInput();
	Output o;
    solveBrute(o);
	o.printOutput();
}
