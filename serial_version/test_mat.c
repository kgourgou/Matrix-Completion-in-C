#include "matCompl.h"

/*

  test_mat(int r, int numRows, int numCols) returns an (numRows x numCols) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double** test_mat(int r, int numRows, int numCols){
	int i, j;
	double** A  = alloc_array(numRows, numCols);		//create an mxm matrix
	for( i = 0; i < numRows; i++){
		for( j = 0; j < numCols; j++ ){
			A[i][j] = rand();
		}
	}
	return A;
}