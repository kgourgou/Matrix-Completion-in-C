#include "matCompl.h"

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. 
  For the construction of the matrix, the singular value decomposition is used. 

  Not ready yet though.

*/
double** test_mat(int r, int nrows, int ncols){
	int i, j;
	int info;
//	int LWORK = fmax(1,3*fmin(nrows,ncols)+fmax(nrows,ncols),5*fmin(nrows,ncols));
//	double** WORK = alloc_array(1, LWORK);
	double** A  = alloc_array(nrows, ncols);		//create an mxm matrix
	double** U = alloc_array(nrows, nrows);
	double** VT = alloc_array(ncols, ncols);
	double** S = alloc_array(fmin(nrows,ncols), fmin(nrows, ncols));
	
	for( i = 0; i < nrows; i++){
		for( j = 0; j < ncols; j++ ){
			A[i][j] = (double)rand()/RAND_MAX;
		}
	}
	
//	dgesvd('A', 'A', nrows, ncols, A, nrows, S, U, nrows, VT, ncols, WORK, LWORK, &info);
	
	return A;
}
