/*

  Serial version of matrix completion code. 
	
*/


#include "matCompl.h"

int main(void){ 
 int nrows = 2;
 int ncols = 2;
 int rank = 2;
 int numIter = 5;
 int i;
 double tau = 1.0;
 double delta = 1.0;
 
 int omega[] = {0, 1, 2, 3};
 int kn = 4;
 
 double *M = test_mat(rank, nrows, ncols);
 double *Y = alloc_array_z(nrows, ncols);
 double *Z = alloc_array(nrows, ncols);
 double *dummyMatrix = alloc_array(nrows, ncols);
 
 print_mat(M, nrows, ncols);
 
 for( i = 0; i < numIter; i++){
 	Z = shrink(Y, tau, nrows, ncols);
 	Y = ma(Y, ncols, nrows, 1.0, Proj_sub(M, Z, omega, kn, dummyMatrix), ncols, nrows, delta, omega, kn);
 }



 

 free_array(Y);
 free_array(M); 
 return 0;
}
 
