#include "omp.h"
#include "iostream"
#include "math.h"

using namespace std;

int main(int argc, char **argv)
{
    int max_threads = omp_get_max_threads();
    double var = 0;
    double now;

    // add "ordered" to be able to call commands consequently inside the for loop
    #pragma omp parallel for ordered private(now) shared(var)
    for (int i = 0; i < max_threads; ++i) {
        // this part of code is executed in parallel
        int th_num = omp_get_thread_num();
        double now = exp(th_num);

//        cout << now << endl; //uncomment this line to prove parallel execution

#pragma omp ordered
        {
            // and this part of code is executed consequently
            var = now;
            cout << "I am thread number " << th_num << " and now I am the boss." << endl;
            cout << "I set new value in var. Now it is " << var << endl;
        };
    }
}