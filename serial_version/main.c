/*

  Serial version of matrix completion code. 
	
*/

#include "matCompl.h"

int main(void){ 
 int nrows = 2;
 int ncols = 2;
 int rank = 1;
         



 int numIter = 1000;
 int i,j;
 double tau = 1.5*nrows;
 double delta = 1.9;
 
 int omega_c[] = {0}; // places of unknown values.
 int omega[] = {1,2,3}; // places of known values.

 int ku = 1; // Number of unknown values.
 int kn = (nrows*ncols)-ku; // Number of known values.

 double *Y = alloc_array_z(nrows, ncols);
  double *Z = alloc_array_z(nrows, ncols);
  double *M = test_mat(rank, nrows, ncols);
 double *dummyMatrix = alloc_array_z(nrows, ncols);
 double *dummy2 = alloc_array_z(nrows,ncols);


 for( i = 0; i < numIter; i++){
 
    for(j=0; j <  ncols*nrows;j++){
        dummy2[j] = Y[j];
    }

    Z = shrink(dummy2, tau, nrows, ncols);
 	Proj_sub(M, Z, omega, kn, dummyMatrix);
 	ma(Y, ncols, nrows, 1.0, dummyMatrix, ncols, nrows, delta, omega, kn, dummy2);
 }
 printf("Error = %f\n\n", RMSE2(M, Z, omega_c, ku));


 free_array(Y);
 free_array(M); 
 free_array(dummy2);
 free_array(Z);
 free_array(dummyMatrix);
 return 0;
}
 
