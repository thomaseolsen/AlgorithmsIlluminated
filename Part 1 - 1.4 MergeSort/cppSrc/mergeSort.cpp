#include <chrono>
#include "mergeSort.h"

int smallSet[10] = {9, 8, 3, 6, 2, 7, 5, 1, 4, 0};

int main(int argc, char *argv[]) {

    auto t1 = chrono::high_resolution_clock::now();
    //Sort samllSet
    auto t2 = chrono::high_resolution_clock::now();
    cout << "Base C++ multiplication took "
              << chrono::duration_cast<chrono::nanoseconds>(t2-t1).count()
              << " nanoseconds to return a sorted set.\n";

    return 0;
}
