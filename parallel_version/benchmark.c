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


void runBenchmark( char method, int nrows, int ncols, int rank,	int ku, int omega_c[], int kn, int omega[], int numIter, double tol, char* file_out, double tau, double delta, double* Y, double* Z, double* M, double* dummyMatrix, double* dummy2){    
	time_t start_time;
  	double seconds;
  	time(&start_time);  /* get current time; same as: now = time(NULL)  */

	int i, j;

	for( i = 0; i < numIter; i++){
		for(j=0; j <  ncols*nrows;j++){
			dummy2[j] = Y[j];
		}
		Z = shrink(dummy2, tau, nrows, ncols);
		Proj_sub(M, Z, omega, kn, dummyMatrix);
		ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, Y);
	}
	seconds = difftime(time(NULL),start_time);	//need to output this to file
}