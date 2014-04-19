#include "matCompl.h"

/*
 shrink(double** A, double t, int M) applies the shrink operator on A with thresholding parameter t. 
 
 The idea is to compute the SVD of A, A=U*S*V, then create the matrix B

     B = U * S2 * V, 

     where S2_{i,i} = S_{i,i} if ((S_{i,i}-)*t>0) and 
           S2_{i,i} = 0 otherwise.
   
    Then it returns B.

*/
double* shrink(double* A, double tau, int nrows, int ncols){
	int i;
	int info = 0;
	char JOBU = 'A';
	char JOBVT = 'A';

	int LWORK = fmax(fmax(1,3*fmin(nrows,ncols)+fmax(nrows,ncols)),5*fmin(nrows,ncols));
	double* WORK = alloc_array(1, LWORK);
	double* U = alloc_array(nrows, nrows);
	double* VT = alloc_array(ncols, ncols);
	double* S = alloc_array(fmin(nrows,ncols), fmin(nrows, ncols));
	
	dgesvd_(&JOBU, &JOBVT, &nrows, &ncols, A, &nrows, S, U, &nrows, VT, &ncols, WORK, &LWORK, &info);

	for( i = 0; i < fmin(nrows,ncols); i++){
		//printf("%f ", S[i]);
			S[i] = fmax(0.0, S[i] - tau);
		//printf("%f\n", S[i]);
	}
	
	double* C = alloc_array_z(nrows,ncols);
	
	//C = mm(mm(U, nrows, nrows, 't', diag(S,nrows, ncols), nrows, ncols, 'n'), nrows, ncols, 'n', VT, ncols, ncols, 't');
	C = mm(mm(VT, ncols, ncols, 'n', diag(S,ncols, nrows), ncols, nrows, 'n'), ncols, nrows, 'n', U, nrows, nrows, 'n');
	
	//free_array(A);
	free_array(WORK);
	free_array(U);
	free_array(VT);
	free_array(S);
	
	return C;
}	