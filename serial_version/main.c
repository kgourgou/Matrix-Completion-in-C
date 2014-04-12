/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 5;
 int rank = 3;
 double **A = test_mat(rank, nrows, ncols);

 
 free_array(A,nrows); 
 return 0;
}
 
