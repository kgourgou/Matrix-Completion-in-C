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

    clock_t start_time = clock();
	int i, j;
    double timing;
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
		// Absolute tolerance used here.
		if(RMSE2(M,Z,omega_c,ku)<tol){
			break;
		}
	}
	
	timing = (clock()-start_time)*1000/(CLOCKS_PER_SEC);	//need to output this to file

   	return (timing/1000);
}
