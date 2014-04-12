#include "matCompl.h"

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double** test_mat(int r, int nrows, int ncols){
	int i, j;
	double** A  = alloc_array(nrows, ncols);		//create an mxm matrix
	double** U = alloc_array(nrows, nrows);
	double** VT = alloc_array(ncols, ncols);
	double** S = alloc_array(
	for( i = 0; i < nrows; i++){
		for( j = 0; j < ncols; j++ ){
			A[i][j] = (double)rand()/RAND_MAX;
		}
	}
	//      SUBROUTINE DGESVD( JOBU, JOBVT, M, N, A, LDA, S, U, LDU, VT, LDVT, WORK, LWORK, INFO )
	DGESVD('A', 'A', nrows, ncols, A, nrows,  
	
	
	return A;
}