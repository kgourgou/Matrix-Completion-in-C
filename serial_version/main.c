/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int numRows = 5;
 int numCols = 5;
 int rank = 3;
 double **A = test_mat(rank, numRows, numCols);
 printmat(A, numRows, numCols);
 free_array(A,numRows); 
 return 0;

}