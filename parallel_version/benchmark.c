#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

/*

  Parallel version of matrix completion code. 
	
*/

#include "matCompl.h"

/*
not currently implemented:
method argument
tol argument
file_out argument
*/


double runBenchmark( char method, int nrows, int ncols, int rank,	int ku, int omega_c[], int kn, int omega[], int numIter, double tol, char* file_out, double tau, double delta, double* Y, double* Z, double* M, double* dummyMatrix, double* dummy2){    

    time_t start_time;
	int i, j;
    double seconds;
    printf("Now running benchmark\n");

	
	for( i = 0; i < numIter; i++){
		if(method == 'S'){
			for(j=0; j <  ncols*nrows;j++){
				dummy2[j] = Y[j];
			}
		}
		else if(method == 'P'){
			#pragma omp parallel for
			for(j=0; j <  ncols*nrows;j++){
				dummy2[j] = Y[j];
		}
		}
		Z = shrink(dummy2, tau, nrows, ncols, method);
		Proj_sub(M, Z, omega, kn, dummyMatrix, method);
		ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, Y);
	}
	
	seconds = difftime(time(NULL),start_time);	//need to output this to file

    printf("Warning: Seconds returns garbage.")
	return seconds;
}
