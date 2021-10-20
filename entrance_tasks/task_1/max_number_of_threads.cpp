#include <omp.h>
#include <iostream>

using namespace std;
int main(void){
#ifdef _OPENMP
    int max_threads = omp_get_max_threads();
#endif
    cout << "Hello world!";
    cout << "Max number of threads: " << max_threads << endl;

    return 0;
}

