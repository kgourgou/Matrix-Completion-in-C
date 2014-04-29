/*

  Parallel version of matrix completion code. 
	
*/

#include "matCompl.h"
#include "benchmark.h"


int main(int argc, char* argv[]){ 
	int nrows = 300;
	int ncols = 300;
	int rank = 4;        

	int numIter = 10;
	double tau = 1.5*nrows;
	double delta = 1.4;
	double tol = 0.1;	//		terrible choice of value, but this isn't implemented yet anyways
	
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

        printf("Number of elements in matrix : %d\n",nrows*ncols);	

        // Number of threads to use. 
	// Run ./a.out 3 for three threads. 
        int num_of_threads = atoi(argv[1]);
	printf("Asked for %d threads\n", num_of_threads);
	omp_set_num_threads(num_of_threads);

	printf("Elapsed time : %1.4f sec\n", runBenchmark( 'P', nrows, ncols, rank, ku, omega_c, kn, omega, numIter, tol, file_out, tau, delta, Y, Z, M, dummyMatrix, dummy2));

    printf("RMSE : %1.2g\n", RMSE2(M, Z, omega_c, ku));



    // Cleaning up	
	free_array(Y);
	free_array(M); 
	free_array(dummy2);
	free_array(Z);
	free_array(dummyMatrix);
	return 0;
}
