#include <omp.h>
#include <iostream>

using namespace std;
int main(void){
    #pragma omp parallel
    {
        cout << "Hello world! I am thread no " << omp_get_thread_num() << endl;
    }
    return 0;
}
