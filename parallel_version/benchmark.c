#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*

  Serial version of matrix completion code. 
	
*/

#include "matCompl.h"

/*
arguments currently not implemented:
method
tol
file_out
*/

/*
outstanding questions:
should we move "create_omega" out of this?	YES
should the matrices be created here or be passed in?	YES
*/


void runBenchmark( char method, int nrows, int ncols, int rank,	int ku, int omega_c[], int numIter, double tol, char* file_out, double tau, double delta){     
	int i,j;
	int kn = (nrows*ncols)-ku; // Number of known values.
	int omega[kn]; // places of known values.
	create_omega(omega_c, ku, omega, kn, nrows*ncols);
 
	double *Y = alloc_array_z(nrows, ncols);
	double *Z = alloc_array_z(nrows, ncols);
	double *M = test_mat(rank, nrows, ncols);
	double *dummyMatrix = alloc_array_z(nrows, ncols);
	double *dummy2 = alloc_array_z(nrows,ncols);

	for( i = 0; i < numIter; i++){
		for(j=0; j <  ncols*nrows;j++){
			dummy2[j] = Y[j];
		}
		Z = shrink(dummy2, tau, nrows, ncols);
		Proj_sub(M, Z, omega, kn, dummyMatrix);
		ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, Y);
	}
	free_array(Y);
	free_array(M); 
	free_array(dummy2);
	free_array(Z);
	free_array(dummyMatrix);
}