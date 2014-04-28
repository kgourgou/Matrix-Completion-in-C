/*

  Serial version of matrix completion code. 
	
*/

#include "matCompl.h"
#include "benchmark.h"


int main(void){ 
	int nrows = 40;
	int ncols = 40;
	int rank = 35;        

	int numIter = 10000;
	double tau = 1.5*nrows;
	double delta = 1.4;
	double tol = 1.0;	//		terrible choice of value, but this isn't implemented yet anyways
	
	char* file_out = "test.txt";

	int ku = 3; // Number of unknown values.
	int omega_c[] = {0, 5, 7}; // places of unknown values.
	int kn = (nrows*ncols)-ku; // Number of known values.
	int omega[kn]; // places of known values.
	create_omega(omega_c, ku, omega, kn, nrows*ncols);

	double *Y = alloc_array_z(nrows, ncols);
	double *Z = alloc_array_z(nrows, ncols);
	double *dummyMatrix = alloc_array_z(nrows, ncols);
	double *dummy2 = alloc_array_z(nrows,ncols);
	
	double *M = test_mat(rank, nrows, ncols);


	runBenchmark( 'S', nrows, ncols, rank, ku, omega_c, kn, omega, numIter, tol, file_out, tau, delta, Y, Z, M, dummyMatrix, dummy2);

	free_array(Y);
	free_array(M); 
	free_array(dummy2);
	free_array(Z);
	free_array(dummyMatrix);
	return 0;
}