#include <omp.h>
#include <iostream>
#include "vector"
using namespace std;
int main(int argc, char **argv){
    // Ensure that we have only 1 argument - number of terms in sum.
    if(argc != 2) {
        cout << "ERROR: wrong number of arguments." << endl;
        return 0;
    }
    // convert to long long
    unsigned long long N = strtoull(argv[1], NULL, 10);
    cout << "There will be " << N << " terms in sum." << endl;

    // here will be all results
    double sum = 0.0;

    // use reduction in order to avoid problems with random access to sum variable
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += 1.0 / (1 + i);
    }

    cout << "Total sum = " << sum << endl;
    return 0;
}
