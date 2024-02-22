#include <stdio.h>
#include <omp.h>

int main(){
    int nthreads, tid;
    printf("Set 4 threads\n");
    //Set number of threads to 4
    int num_threads = 4;
    omp_set_num_threads(num_threads); 
    //Obtain the number of threads
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    #pragma omp parallel private(tid)
    {
        //Get the id of the thread
        tid = omp_get_thread_num(); 
        printf("Hello from thread = %d\n",tid);
        if (tid == 0){ 
            //If I am the master
            //Obtain the number of threads
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }
    }
    return 0;
}