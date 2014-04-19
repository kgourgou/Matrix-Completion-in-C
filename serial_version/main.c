/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 4;
 int ncols = 4;
 int rank = 2;
 double *A = test_mat(rank, nrows, ncols);
 double *B = alloc_array_z(nrows, ncols);
         


 free_array(B);
 free_array(A); 
 return 0;
}
 
