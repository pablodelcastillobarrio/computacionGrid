#include <stdio.h>
#include <omp.h>

int main(){
	int nthreads, tid;
	printf("Trabajamos con 4 threads\n");
	
	//.......Set number of threads to 4
	//.......Obtain the number of threads
    int num_threads = 4;
    omp_set_num_threads(num_threads);
    nthreads = omp_get_num_threads();
	
	printf("Número de threads en ejecución = %d\n", nthreads);
	#pragma omp parallel private(tid) //Región paralela. Cada 
	{	//thread contiene sus propias copias de variables
		//........Get the id of the thread
        tid = omp_get_thread_num(); 
		printf("Hola desde el thread = %d\n",tid);
		if (tid == 0){ //If I am the master
			//.........Obtain the number of threads
            nthreads = omp_get_num_threads();
			printf("Número de threads = %d\n", nthreads);
		}
	}
	//Todos los threads se unen al maestro y finalizan
	printf("Trabajamos ahora con 3 threads");
	//.......Set number of threads to 3
	//.......Obtain the number of threads
    num_threads = 3;
    omp_set_num_threads(num_threads);
    nthreads = omp_get_num_threads();

	printf("Número de threads en ejecución = %d\n",nthreads);
	#pragma omp parallel private(tid)
	{
		//........Get the id of the thread
        tid = omp_get_thread_num(); 
		printf("Hola desde el thread = %d\n",tid);
		if (tid == 0){ //If I am the master
			//......Obtain the number of threads
            nthreads = omp_get_num_threads();
			printf("Número de threads = %d\n", nthreads);
		}
	}
}