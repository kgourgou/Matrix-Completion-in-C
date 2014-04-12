#include "matCompl.h"

/*

  test_mat(int r, int m) returns an (M x M) matrix of rank r. For the construction of the matrix, the 
  singular value decomposition is used. 

*/
double** test_mat(int r, int m){
	int i, j;
	A = alloc_array(m, m);		//create an mxm matrix
	for( i = 0; i < m; i++){
		for( j = 0; j < m; j++ ){
			A[i][j] = rand();
		}
	}
}