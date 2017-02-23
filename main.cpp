#include "info.h"
#include "output.h"
#include "sol_brute.h"
#include "glapa.h"

int32_t main() {
	readInput();
    cerr << "reading done" << endl;
    /*
	Output o;
    solveBrute(o);
	o.printOutput();
    */
    Glapa::solve2().printOutput();
}
