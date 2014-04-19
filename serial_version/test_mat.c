#include "matCompl.h"

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double** test_mat(int r, int nrows, int ncols){
	int i, j;
	int* info;
	char JOBU = 'A';
	char JOBVT = 'A';

	//int LWORK = fmax(fmax(1,3*fmin(nrows,ncols)+fmax(nrows,ncols)),5*fmin(nrows,ncols));
	//double** WORK = alloc_array(1, LWORK);
	double** A  = alloc_array(nrows, ncols);		//create an mxm matrix
	double** U = alloc_array(nrows, nrows);
	double** VT = alloc_array(ncols, ncols);
	double** S = alloc_array(fmin(nrows,ncols), fmin(nrows, ncols));
	
	for( i = 0; i < nrows; i++){
		for( j = 0; j < ncols; j++ ){
			A[i][j] = (double)rand()/RAND_MAX;
		}
	}
	
	
	
	//int dgesvd_(char *jobu, char *jobvt, __CLPK_integer *m, __CLPK_integer *n, 
	//__CLPK_doublereal *a, __CLPK_integer *lda, __CLPK_doublereal *s, __CLPK_doublereal *u, __CLPK_integer *
	//ldu, __CLPK_doublereal *vt, __CLPK_integer *ldvt, __CLPK_doublereal *work, __CLPK_integer *lwork, 
	//__CLPK_integer *info);
	//SUBROUTINE DGESVD( JOBU, JOBVT, M, N, A, LDA, S, U, LDU, VT, LDVT, WORK, LWORK, INFO )
	//dgesvd_(&JOBU, &JOBVT, &nrows, &ncols, *A, nrows, S, U, nrows, VT, ncols, WORK, LWORK, info);
	
	return A;
}