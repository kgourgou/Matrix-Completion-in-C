#include "matCompl.h"

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double* test_mat(int r, int nrows, int ncols){
	int i, j;
	int info = 0;
	char JOBU = 'A';
	char JOBVT = 'A';

	int LWORK = fmax(fmax(1,3*fmin(nrows,ncols)+fmax(nrows,ncols)),5*fmin(nrows,ncols));
	double* WORK = alloc_array(1, LWORK);
	double* A  = alloc_array(nrows, ncols);		//create an mxm matrix
	double* U = alloc_array(nrows, nrows);
	double* VT = alloc_array(ncols, ncols);
	double* S = alloc_array(fmin(nrows,ncols), fmin(nrows, ncols));
	
	for( i = 0; i < nrows; i++){
		for( j = 0; j < ncols; j++ ){
			A[map(i,j,ncols)] = (double)rand()/RAND_MAX;
		}
	}
	
	dgesvd_(&JOBU, &JOBVT, &nrows, &ncols, A, &nrows, S, U, &nrows, VT, &ncols, WORK, &LWORK, &info);

	for( i = 0; i < fmin(nrows,ncols); i++){
		if(i >= r){
			S[i] = 0.0;
		}
	}
	
	double* C = alloc_array_z(nrows,ncols);
	
	C = mm(mm(U, nrows, nrows, diag(S,nrows), nrows, ncols), nrows, ncols, VT, ncols, ncols);
	
	free_array(A);
	free_array(WORK);
	free_array(U);
	free_array(VT);
	free_array(S);
	//free_array(C);
	
	return C;
}